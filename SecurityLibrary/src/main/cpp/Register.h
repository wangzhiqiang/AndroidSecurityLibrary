//
// Created by wzq on 17-7-3.
//

#ifndef _REGISTER_H
#define _REGISTER_H

#include <jni.h>
#include <linux/signal.h>


class Register {

 public:

  /**
   * 注册对应的Native方法到Java
   * @param env
   * @return
   */
  static int registerNativeMethods(JNIEnv *env, const char *className,
                            JNINativeMethod *gMethods, int numMethods);
};


#endif //_REGISTER_H
