#!/bin/sh

. ./project_paths.sh

if [ $# -eq 0 ]; then
    shouldBuildShared="OFF"
elif [ "$1" = "Static" ]; then
    shouldBuildShared="OFF"
elif [ "$1" = "Shared" ]; then
    shouldBuildShared="OFF"
else
    echo "Neither Static nor Shared! Aborting ..."
    exit 1
fi

cmake   -G Xcode \
        -S $PROJECT_ROOT \
        -B $BUILD_DIR \
        -D BUILD_SHARED_LIBS=$shouldBuildShared \
        -D CMAKE_INSTALL_PREFIX="$INSTALL_DIR" \
        -D CMAKE_PREFIX_PATH="$DEPS_DIR" \
        -D BUILD_TESTS=ON \
