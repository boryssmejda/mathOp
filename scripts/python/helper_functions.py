import os
import shutil
import subprocess

def delete_if_exists(FOLDER_PATH: str) -> None:
    if os.path.exists(FOLDER_PATH) and os.path.isdir(FOLDER_PATH):
        shutil.rmtree(FOLDER_PATH)
        print("Deleted successfully: {}".format(FOLDER_PATH))
    else:
        print("{} does not exist".format(FOLDER_PATH))


class CMake:

    @staticmethod
    def build(BUILD_DIR: str, BUILD_TYPE: str) -> None:
        cmake_command = ['cmake', '--build', BUILD_DIR, '--config', BUILD_TYPE]
        subprocess.run(cmake_command)


    @staticmethod
    def test(BUILD_TYPE: str) -> None:
        cmake_command = ['ctest','--build-config', BUILD_TYPE]
        subprocess.run(cmake_command)


    @staticmethod
    def install(BUILD_DIR: str, BUILD_TYPE: str) -> None:
        cmake_command = ['cmake', '--install', BUILD_DIR, '--config', BUILD_TYPE]
        subprocess.run(cmake_command)