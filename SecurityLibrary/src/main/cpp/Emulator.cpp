//
// Created by wzq on 17-6-30.
//
#include <unistd.h>
#include "Emulator.h"
#include "FLog.h"
#include "Utils.h"

void Emulator::validate(JNIEnv *env) {

    Emulator *emulator;
    bool res = emulator->hasEmulatorFile();
    if (res) {
        kill(getpid(), SIGKILL);
    }
    //TODO 判断其它项

}

bool Emulator::hasEmulatorFile() {

    char *file_list[] = {
        (char *)"/dev/socket/qemud",
        (char *)"/dev/qemu_pipe",
        (char *)"/system/lib/libc_malloc_debug_qemu.so",
        (char *)"/sys/qemu_trace",
        (char *)"/system/bin/qemu-props"
    };


    bool res = false;
    int len = 0;
    ARRAY_LEN(file_list, len);

    for (int i = 0; i < len; i++) {
        if (access(file_list[i], F_OK) == 0) {
            LOGW("检查到模拟器文件 %s", file_list[i]);
            res = true;
            break;
        }
    }

    return res;
}


