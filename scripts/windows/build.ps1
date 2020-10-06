param ([Parameter(Mandatory)]
        [ValidateSet('Debug','Release')]
        [String]$buildType=$(throw "-buildType is required.")
)

. .\project_paths.ps1

cmake --build $BUILD_DIR `
      --config $buildType
