package cn.wangzq.library;


/**
 * @author wzq
 * @email wangzhiqiang@17money.com
 * @date : 2017-06-30 13:22
 */
public class Security {

    static {
        System.loadLibrary("security");
    }

    public static native void validate();
    public static native void validateSignature();
    public static native void validateEmulator();
    public static native void validateDebug();

}
