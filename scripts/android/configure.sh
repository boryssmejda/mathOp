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

echo "Build configuration: $buildType"

cmake   -S $PROJECT_ROOT \
        -B $BUILD_DIR \
        -A x64 \
        -D CMAKE_SYSTEM_NAME=Android \
        -D CMAKE_SYSTEM_VERSION=21 \
        -D CMAKE_ANDROID_ARCH_ABI=arm64-v8a \
        -D CMAKE_ANDROID_NDK="$ANDROID_NDK_LOCATION" \
        -D CMAKE_BUILD_TYPE=$buildType \
        -D CMAKE_INSTALL_PREFIX="$INSTALL_DIR" \
        -D CMAKE_PREFIX_PATH="$DEPS_DIR" \
        -D FMT_HEADERS_LOCATION="$FMT_HEADERS_LOCATION" \
        -D BUILD_TESTS=ON \
