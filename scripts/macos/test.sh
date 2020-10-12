#!/bin/sh

. ./project_paths.sh

cd $BUILD_DIR
ctest -C Release
ctest -C Debug
cd $SCRIPTS_LOCATION
