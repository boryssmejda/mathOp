import project_paths as pp
import sys
import subprocess

if __name__ == "__main__":
    assert (len(sys.argv) == 2), "No build type given! Aborting ..."

    CONFIGURATION = sys.argv[1]
    if CONFIGURATION not in ['Release', 'Debug']:
        raise ValueError("Unknown Configuration: {}".format(CONFIGURATION))

    cmake_command = ['cmake', '--install', pp.BUILD_DIR, '--config', CONFIGURATION]
    subprocess.run(cmake_command)
