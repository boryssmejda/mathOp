. .\project_paths.ps1

conan install --install-folder $DEPS_DIR `
              --generator deploy `
              --update `
              $CONANFILE_LOCATION
