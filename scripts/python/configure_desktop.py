import project_paths as pp
import platform
import sys
import subprocess

def get_generator():
    generators = {
        'Windows': 'Visual Studio 16 2019',
        'Linux': 'Ninja Multi-Config',
        'Darwin': 'Xcode'
    }
    return generators[platform.system()]


if __name__ == "__main__":

    if len(sys.argv) == 1:
        MATHOP_BUILD_SHARED = "OFF"
    elif len(sys.argv) == 2 and sys.argv[1] == 'Static':
        MATHOP_BUILD_SHARED = "OFF"
    elif len(sys.argv) == 2 and sys.argv[1] == 'Shared':
        MATHOP_BUILD_SHARED = "ON"
    else:
        raise ValueError("Unknown Configuration: {}".format(sys.argv[1]))

    PLATFORM_GENERATOR = get_generator()
    cmake_command = ["cmake",
                    "-G", PLATFORM_GENERATOR,
                    "-S", pp.PROJECT_ROOT,
                    "-B", pp.BUILD_DIR,
                    "-D", "MATHOP_BUILD_SHARED={}".format(MATHOP_BUILD_SHARED),
                    "-D", "CMAKE_INSTALL_PREFIX={}".format(pp.INSTALL_DIR),
                    "-D", "CMAKE_PREFIX_PATH={}".format(pp.DEPS_DIR),
                    "-D", "BUILD_TESTS=ON"]

    subprocess.run(cmake_command)
