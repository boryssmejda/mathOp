param ([ValidateSet('Debug','Release')]
        [String]$buildType
)

. .\project_paths.ps1

if($buildType -eq "")
{
    cmake --build $BUILD_DIR --target RUN_TESTS --config Release
    cmake --build $BUILD_DIR --target RUN_TESTS --config Debug
}
else
{
    cmake --build $BUILD_DIR --target RUN_TESTS --config $buildType
}
