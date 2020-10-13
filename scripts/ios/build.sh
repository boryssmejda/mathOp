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

cmake --build $BUILD_DIR --config $buildType
