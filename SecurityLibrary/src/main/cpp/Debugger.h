//
// Created by wzq on 17-7-17.
//

#ifndef _DEBUGGER_H
#define _DEBUGGER_H


#include <jni.h>
class Debugger {
 public:
  /**
   * 检查App是否是在调试模式
   * @param env
   */
  static void validate(JNIEnv *env);


 protected:
  static bool  isDebuggerConnected(JNIEnv *env);
  //检查tracePid 对于纯java的桥接调试不可行
  static void checkTracerPid();

};


#endif //_DEBUGGER_H
