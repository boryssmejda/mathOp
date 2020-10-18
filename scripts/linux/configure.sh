#!/bin/sh

. ./project_paths.sh

if [ $# -eq 0 ]; then
    echo >&2 "No build type given!"
    exit 1
fi

#if [ "$1" = "Debug" ]; then
#    buildType="Debug"
#elif [ "$1" = "Release" ]; then
#    buildType="Release"
#else
#    echo "Unknown Configuration! Aborting ..."
#    exit 1
#fi

#echo "Build configuration: $buildType"

if [ "$1" = "Static" ]; then
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
        -D MATHOP_BUILD_SHARED=$shouldBuildShared \
        -D CMAKE_INSTALL_PREFIX="$INSTALL_DIR" \
        -D CMAKE_PREFIX_PATH="$DEPS_DIR" \
        -D FMT_HEADERS_LOCATION="$FMT_HEADERS_LOCATION" \
        -D BUILD_TESTS=ON \
