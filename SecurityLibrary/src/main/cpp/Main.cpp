#include <jni.h>
//#include <string>
#include "Register.h"
#include "Utils.h"
#include "Signature.h"
#include "Emulator.h"
#include "Debugger.h"
/**
*
 *  注册Native 方法到 java
*
*/

static  void validate(JNIEnv *env){

    Signature::validate(env);
    Emulator::validate(env);
    Debugger::validate(env);

}

void register_ndk_load(JNIEnv *env) {
    //动态注册JNI

    const char *clazz = "cn/wangzq/library/Security";

    JNINativeMethod methods[] = {
        {"validate", "()V", (void *) validate},
        {"validateSignature", "()V", (void *) Signature::validate},
        {"validateEmulator", "()V", (void *) Emulator::validate},
        {"validateDebug", "()V", (void *) Debugger::validate},

    };
    int len = 0;
    ARRAY_LEN(methods, len)
    Register::registerNativeMethods(env, clazz, methods, len);
}

//动态库入口
//动态注册JNI
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    jint result = -1;

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return result;
    }
    register_ndk_load(env);

    return JNI_VERSION_1_6;
}




