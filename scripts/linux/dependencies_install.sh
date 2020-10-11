#!/bin/sh

. ./project_paths.sh

conan install --install-folder $DEPS_DIR \
              --generator deploy \
              --profile $CONAN_PROFILE_LOCATION \
              --update \
              $CONANFILE_LOCATION \
