//
// Created by wzq on 17-6-30.
//

#ifndef _EMULATOR_H
#define _EMULATOR_H


#include <jni.h>
class Emulator {
 public:
  static void validate(JNIEnv *env);
  /**
   * 检查是否含有模拟器特有的几个文件
   * @return bool
   */
  bool hasEmulatorFile();
};


#endif //_EMULATOR_H
