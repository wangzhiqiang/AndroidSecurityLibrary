//
// Created by wzq on 17-6-30.
//

#ifndef _FLOG_H
#define _FLOG_H

#include "jni.h"
#include <android/log.h>

static const char *TAG = "LOG_TAG";

static  const bool  ENABLE_LOG= true;




#define LOGD(fmt, args...) if(ENABLE_LOG) __android_log_print(ANDROID_LOG_DEBUG, TAG, fmt, ##args)
#define LOGI(fmt, args...) if(ENABLE_LOG) __android_log_print(ANDROID_LOG_INFO,  TAG, fmt, ##args)
#define LOGW(fmt, args...) if(ENABLE_LOG) __android_log_print(ANDROID_LOG_WARN,  TAG, fmt, ##args)
#define LOGE(fmt, args...) if(ENABLE_LOG) __android_log_print(ANDROID_LOG_ERROR, TAG, fmt, ##args)

#endif //_FLOG_H
