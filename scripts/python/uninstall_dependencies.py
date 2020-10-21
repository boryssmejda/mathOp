import project_paths as pp
import os
import shutil


def delete_if_exists(FOLDER_PATH: str) -> None:
    if os.path.exists(FOLDER_PATH) and os.path.isdir(FOLDER_PATH):
        shutil.rmtree(FOLDER_PATH)
        print("Deleted successfully: {}".format(FOLDER_PATH))
    else:
        print("{} does not exist".format(FOLDER_PATH))


if __name__ == "__main__":
    delete_if_exists(pp.DEPS_DIR)
