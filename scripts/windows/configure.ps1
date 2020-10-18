param ([ValidateSet('Shared','Static')]
        [String]$buildType='Static'
)

. .\project_paths.ps1

switch ($buildType)
{
        'Static' { $shouldBuildShared = 'OFF' }
        'Shared' { $shouldBuildShared = 'ON'}
}

cmake   -S $PROJECT_ROOT `
        -B $BUILD_DIR `
        -A x64 `
        -D MATHOP_BUILD_SHARED=$shouldBuildShared `
        -D CMAKE_INSTALL_PREFIX="$INSTALL_DIR" `
        -D CMAKE_PREFIX_PATH="$DEPS_DIR" `
        -D FMT_HEADERS_LOCATION="$FMT_HEADERS_LOCATION" `
        -D BUILD_TESTS=ON `
