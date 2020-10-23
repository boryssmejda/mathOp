#!/bin/sh

. ./project_paths.sh

if [ $# -eq 0 ]; then
    shouldBuildShared="OFF"
    echo "No configuration given. Default one chosen: Static"
elif [ "$1" = "Static" ]; then
    shouldBuildShared="OFF"
elif [ "$1" = "Shared" ]; then
    shouldBuildShared="ON"
else
    echo "Neither Static nor Shared! Aborting ..."
    exit 1
fi

cmake   -S $PROJECT_ROOT \
        -B $BUILD_DIR \
        -G "Ninja Multi-Config" \
        -D CMAKE_SYSTEM_NAME=Android \
        -D CMAKE_SYSTEM_VERSION=21 \
        -D CMAKE_ANDROID_ARCH_ABI=arm64-v8a \
        -D CMAKE_ANDROID_NDK="$ANDROID_NDK_LOCATION" \
        -D MATHOP_BUILD_SHARED=$shouldBuildShared \
        -D CMAKE_INSTALL_PREFIX="$INSTALL_DIR" \
        -D CMAKE_PREFIX_PATH="$DEPS_DIR" \
        -D BUILD_TESTS=ON \
