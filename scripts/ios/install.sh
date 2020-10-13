#!/bin/sh

. ./project_paths.sh

if [ $# -eq 0 ]; then
    cmake --install $BUILD_DIR --config Debug
    cmake --install $BUILD_DIR --config Release
elif [ "$1" = "Debug" ]; then
    cmake --install $BUILD_DIR --config Debug
elif [ "$1" = "Release" ]; then
    cmake --install $BUILD_DIR --config Release
else
    echo "Unknown Configuration! Aborting ..."
    exit 1
fi
