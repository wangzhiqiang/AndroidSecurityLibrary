//
// Created by wzq on 17-7-13.
//

#ifndef _SIGNATURE_H
#define _SIGNATURE_H

#include <jni.h>
#include "FLog.h"


class Signature {

 public:
  static void validate(JNIEnv *env);
 private:
  static char *hexdigest(unsigned char *digest, int len);

};


#endif //_SIGNATURE_H
