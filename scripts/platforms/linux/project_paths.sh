#!/bin/sh

SCRIPTS_LOCATION=$PWD
PROJECT_ROOT=$(realpath "$SCRIPTS_LOCATION/../../..")
DEPS_DIR="$PROJECT_ROOT/deps"
BUILD_DIR="$PROJECT_ROOT/build"
INSTALL_DIR="$PROJECT_ROOT/install/"
CONANFILE_LOCATION="$PROJECT_ROOT/conan/conanfiles/desktop/conanfile.txt"
CONAN_PROFILE_LOCATION="$PROJECT_ROOT/conan/profiles/conan-profile-linux.txt"

print_variables()
{
    echo "============================= PROJECT VARIABLES ============================="
    echo "SCRIPTS_LOCATION: $SCRIPTS_LOCATION"
    echo "PROJECT_ROOT: $PROJECT_ROOT"
    echo "DEPS_DIR: $DEPS_DIR"
    echo "BUILD_DIR: $BUILD_DIR"
    echo "INSTALL_DIR: $INSTALL_DIR"
    echo "CONANFILE_LOCATION: $CONAN_PROFILE_LOCATION"
    echo "CONAN_PROFILE_LOCATION: $CONAN_PROFILE_LOCATION"
    echo "=============================================================================="
}
