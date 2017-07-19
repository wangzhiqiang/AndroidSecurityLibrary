//
// Created by wzq on 17-7-3.
//

#include "Register.h"


int Register::registerNativeMethods(JNIEnv *env, const char *className,
                                    JNINativeMethod *gMethods, int numMethods) {
    jclass clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    //调用JNIEnv函数，动态注册JNI
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}