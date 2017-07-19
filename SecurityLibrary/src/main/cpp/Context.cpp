//
// Created by wzq on 17-6-27.
//

#include "Context.h"



jobject Context::getApplicationContext(JNIEnv *env) {
    jclass activityThread = env->FindClass("android/app/ActivityThread");

    jmethodID currentActivityThread = env->GetStaticMethodID(activityThread,
                                                             "currentActivityThread",
                                                             "()Landroid/app/ActivityThread;");

    jobject at = env->CallStaticObjectMethod(activityThread, currentActivityThread);
    jmethodID getApplication = env->GetMethodID(activityThread,
                                                "getApplication",
                                                "()Landroid/app/Application;");
    jobject context = env->CallObjectMethod(at, getApplication);

    return context;
}

jstring Context::getPackageName(JNIEnv *env) {

    jobject context = getApplicationContext(env);

    jclass application = env->GetObjectClass(context);

    jmethodID getPackageName = env->GetMethodID(application,
                                                "getPackageName",
                                                "()Ljava/lang/String;");

    jstring res = (jstring) env->CallObjectMethod(context, getPackageName);

    return res;

}

jobject Context::getPackageManager(JNIEnv *env) {

    jobject context = getApplicationContext(env);

    jclass application = env->GetObjectClass(context);

    jmethodID getPackageManager = env->GetMethodID(application,
                                                   "getPackageManager",
                                                   "()Landroid/content/pm/PackageManager;");

    return env->CallObjectMethod(context, getPackageManager);
}

jobject Context::getPackageInfo(JNIEnv *env, jstring appId, int flag) {
    jobject packageManager = getPackageManager(env);

    jclass clazz = env->GetObjectClass(packageManager);

    jmethodID getPackageInfo = env->GetMethodID(clazz,
                                                "getPackageInfo",
                                                "(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");

    return env->CallObjectMethod(packageManager, getPackageInfo, appId, flag);
}

jobjectArray Context::getSignatures(JNIEnv *env, jobject packageInfo) {

    jclass packageInfoClazz = env->GetObjectClass( packageInfo);
    jfieldID fieldID_signatures =env->GetFieldID( packageInfoClazz,  "signatures", "[Landroid/content/pm/Signature;");
    jobjectArray signatures = (jobjectArray) env->GetObjectField(packageInfo, fieldID_signatures);
    return signatures;

}




