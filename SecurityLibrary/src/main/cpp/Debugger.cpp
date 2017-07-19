//
// Created by wzq on 17-7-17.
//

#include "string.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "Debugger.h"
#include "FLog.h"


void Debugger::validate(JNIEnv *env) {

    bool res = isDebuggerConnected(env);
    if (res) {
        LOGW("调试链接中 ...");
        kill(getpid(),SIGKILL);
    }
    checkTracerPid();

}


bool Debugger::isDebuggerConnected(JNIEnv *env) {

    jclass clazz_debug = env->FindClass("android/os/Debug");
    jmethodID method = env->GetStaticMethodID(clazz_debug, "isDebuggerConnected", "()Z");
    jboolean res = env->CallStaticBooleanMethod(clazz_debug, method);
    bool b = res == JNI_TRUE;
    return b;
}

void Debugger::checkTracerPid() {

    const int buf_size = 1024;
    char filename[buf_size];
    char line[buf_size];
    int pid = getpid();
    sprintf(filename, "/proc/%d/status", pid);
    FILE *fd = fopen(filename, "r");

    if (fd != NULL) {
        while (fgets(line, buf_size, fd)) {
            if (strncmp(line, "TracerPid", 9) == 0) {
                int statue = atoi(&line[10]);
                if (statue != 0) {
                    fclose(fd);
                    LOGE("检查到调试线程  Kill  %d", pid);
                    kill(pid, SIGKILL);
                }
                break;
            }
        }
        fclose(fd);
    } else {
        LOGD("open %s fail...", filename);
    }

}

