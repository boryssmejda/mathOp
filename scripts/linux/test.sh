#!/bin/sh

. ./project_paths.sh

cd $BUILD_DIR

if [ $# -eq 0 ]; then
    ctest -C Release
    ctest -C Debug
elif [ "$1" = "Debug" ]; then
    ctest -C Debug
elif [ "$1" = "Release" ]; then
    ctest -C Release
else
    echo "Unknown Configuration! Aborting ..."
    exit 1
fi

cd $SCRIPTS_LOCATION
