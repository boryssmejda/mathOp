. .\project_paths.ps1

conan install --install-folder $DEPS_DIR `
              --generator deploy `
              --profile $CONAN_PROFILE_LOCATION `
              --update `
              $CONANFILE_LOCATION
