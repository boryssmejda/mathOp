#!/bin/sh

. ./project_paths.sh

cd $BUILD_DIR
make test
cd $SCRIPTS_LOCATION
