import project_paths as pp
import platform
import sys
import subprocess


if __name__ == "__main__":

    if len(sys.argv) == 1:
        MATHOP_BUILD_SHARED = "OFF"
    elif len(sys.argv) == 2 and sys.argv[1] == 'Static':
        MATHOP_BUILD_SHARED = "OFF"
    elif len(sys.argv) == 2 and sys.argv[1] == 'Shared':
        MATHOP_BUILD_SHARED = "ON"
    else:
        raise ValueError("Unknown Configuration: {}".format(sys.argv[1]))

    cmake_command = ["cmake",
                    "-G", "Ninja Multi-Config",
                    "-S", pp.PROJECT_ROOT,
                    "-B", pp.BUILD_DIR,
                    "-D", "CMAKE_SYSTEM_NAME=Android",
                    "-D", "CMAKE_SYSTEM_VERSION=21",
                    "-D", "CMAKE_ANDROID_ARCH_ABI=arm64-v8a",
                    "-D", "CMAKE_ANDROID_NDK={}".format(pp.ANDROID_NDK_LOCATION),
                    "-D", "MATHOP_BUILD_SHARED={}".format(MATHOP_BUILD_SHARED),
                    "-D", "CMAKE_INSTALL_PREFIX={}".format(pp.INSTALL_DIR),
                    "-D", "CMAKE_PREFIX_PATH={}".format(pp.DEPS_DIR),
                    "-D", "BUILD_TESTS=ON"]

    subprocess.run(cmake_command)
