package cn.wangzq.library;

import android.support.annotation.Keep;

/**
 * @author wzq
 * @email wangzhiqiang@17money.com
 * @date : 2017-06-30 13:22
 */
@Keep
public class Security {

    static {
        System.loadLibrary("security");
    }

    public static native void validate();
    public static native void validateSignature();
    public static native void validateEmulator();
    public static native void validateDebug();

}
