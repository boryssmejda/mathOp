import project_paths as pp
import sys
import os
import subprocess


if __name__ == "__main__":
    assert (len(sys.argv) == 2), "No build type given! Aborting ..."

    CONFIGURATION = sys.argv[1]
    if CONFIGURATION not in ['Release', 'Debug']:
        raise ValueError("Unknown Configuration: {}".format(CONFIGURATION))

    try:
        os.chdir(pp.BUILD_DIR)
    except OSError:
        print("Can't change the cwd to: {}".format(pp.BUILD_DIR))

    cmake_command = ['ctest','--build-config', CONFIGURATION]
    subprocess.run(cmake_command)
