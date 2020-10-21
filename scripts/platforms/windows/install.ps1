param ([ValidateSet('Debug','Release')]
        [String]$buildType
)

. .\project_paths.ps1

if($buildType -eq "")
{
    cmake --install $BUILD_DIR --config Release
    cmake --install $BUILD_DIR --config Debug
}
else
{
    cmake --install $BUILD_DIR --config $buildType
}
