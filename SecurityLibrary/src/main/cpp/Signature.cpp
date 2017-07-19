//
// Created by wzq on 17-7-13.
//
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "malloc.h"
#include "Signature.h"
#include "Context.h"
#include "md5.h"
#include "Utils.h"


char *Signature::hexdigest(unsigned char *digest, int len) {
    char buf[len * 2 + 1];
    for (int i = 0; i < len; i++)
        sprintf(buf + i * 2, "%02x", digest[i]);
    buf[len] = 0;
    return buf;
}


void Signature::validate(JNIEnv *env) {

    Context *app;

    //获取applicationId
    jstring appId = app->getPackageName(env);
    //获取PackageInfo
    jobject packageInfo = app->getPackageInfo(env, appId, 64);
    //获取Signature[]
    jobjectArray signatures = app->getSignatures(env, packageInfo);
    //获取签名
    jobject signature = env->GetObjectArrayElement(signatures, 0);
    //获得 Signature
    jclass s_clazz = env->GetObjectClass(signature);
    //得到   Signature 方法的 toByteArray ID
    jmethodID toByteArray = env->GetMethodID(s_clazz, "toByteArray", "()[B");
    //获取 toByteArray 返回值
    jbyteArray data = (jbyteArray) env->CallObjectMethod(signature, toByteArray);
    //获取 jbyteArray 长度
    jsize len = env->GetArrayLength(data);
    //jbyteArray转为jbyte*
    jbyte *bap = env->GetByteArrayElements(data, JNI_FALSE);

    //jbyte 转 unsigned char
    unsigned char *rtn = (unsigned char *) malloc(len + 1);
    memcpy(rtn, bap, len);
    rtn[len] = 0;

    //计算MD5摘要
    unsigned char digest[16];
    MD5_CTX mdContext = {0};
    MD5Init(&mdContext);
    MD5Update(&mdContext, rtn, len);
    MD5Final(digest, &mdContext);

    char *res = hexdigest(digest, 16);
    char *list_data[]={
        (char *)"8e99c0e997525712ca1b32453e2dfba3", // zhongqian-product
        (char *)"c26f63110ada3b1a325a861a30619ae7", // wzq-debug-company
        (char *)"95296b94c9b124d4b3831b5e2fa3a5a7" // debug - all
    };
    bool isPass = false;

    int size = 0;
    ARRAY_LEN(list_data, size);

    for (int k = 0; k < size; k++) {
        char *val = list_data[k];
        if (strcmp(res, val) == 0) {
            isPass = true;
            break;
        }
    }
    if (!isPass) {
        LOGW("签名校验不通过 %s ", res);
        kill(getpid(), SIGKILL);
    }

    env->ReleaseByteArrayElements(data, bap, 0);  //释放掉

    delete app;

}

