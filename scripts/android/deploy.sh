#!/bin/sh

. ./project_paths.sh

if [ $# -eq 0 ]; then
    echo >&2 "No build type given!"
    exit 1
fi

if [ "$1" = "Debug" ]; then
    buildType="Debug"
elif [ "$1" = "Release" ]; then
    buildType="Release"
else
    echo "Unknown Configuration! Aborting ..."
    exit 1
fi

adb push $BUILD_DIR/test/$buildType/test_mathOp_cpp_add \
         $BUILD_DIR/test/$buildType/test_mathOp_cpp_subtract \
         $BUILD_DIR/test/$buildType/test_mathOp_cpp_multiply \
         $BUILD_DIR/test/$buildType/test_mathOp_cpp_divide \
         $BUILD_DIR/test/$buildType/test_mathOp_c_api_add \
         $BUILD_DIR/test/$buildType/test_mathOp_c_api_subtract \
         $BUILD_DIR/test/$buildType/test_mathOp_c_api_multiply \
         $BUILD_DIR/test/$buildType/test_mathOp_c_api_divide \
         $BUILD_DIR/src/$buildType/libmathOp_c_api.so \
         /data/local/tmp

adb shell
cd /data/local/tmp

# deployed files have no execution privilegies
chmod +x *

# just to close adb shell and return to 'normal' terminal
exit
