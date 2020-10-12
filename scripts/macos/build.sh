#!/bin/sh

. ./project_paths.sh

cmake --build $BUILD_DIR --config Release
cmake --build $BUILD_DIR --config Debug
