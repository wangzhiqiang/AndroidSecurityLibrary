//
// Created by wzq on 17-6-27.
//

#ifndef CONTEXT_H
#define CONTEXT_H


#include <jni.h>


class Context {

 public:

  /**
   *获取全局ApplicationContext
   * @param env  JNIEnv
   * @return jobject Context
   */
  jobject getApplicationContext(JNIEnv *env);

  /**
   *获取包名
   * @param env JNIEnv
   * @return  jstring current packageName
   */
  jstring getPackageName(JNIEnv *env);

  //获取packageManager

  /**
   *
   * @param env JNIEnv
   * @return PackageManager
   */
  jobject getPackageManager(JNIEnv *env);

  /**
   *
   *获取PackageInfo
   * @param env JNIEnv
   * @param appId  应用包名
   * @param flag @see android/content/pm/PackageInfo
   * @return  (jobject)PackageInfo
   *
   */
  jobject getPackageInfo(JNIEnv *env, jstring appId, int flag);


  /**
   *获取 包签名数组
   * @param env JNIEnv
   * @param packageInfo  android/content/pm/PackageInfo
   * @return  Signatures
   */
  jobjectArray getSignatures(JNIEnv *env, jobject packageInfo);
};


#endif //CONTEXT_H
