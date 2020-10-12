#!/bin/sh

. ./project_paths.sh

cmake   -G Xcode \
        -S $PROJECT_ROOT \
        -B $BUILD_DIR \
        -D CMAKE_INSTALL_PREFIX="$INSTALL_DIR" \
        -D CMAKE_PREFIX_PATH="$DEPS_DIR" \
        -D FMT_HEADERS_LOCATION="$FMT_HEADERS_LOCATION" \
        -D BUILD_TESTS=ON \