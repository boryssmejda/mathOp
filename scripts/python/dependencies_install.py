import project_paths as pp
import sys
import platform
import os


def get_conan_profile():

    assert platform.system() in ['Windows', 'Linux', 'Darwin'], "Unsupported platform!"

    if platform.system() == 'Windows':
        return pp.CONAN_PROFILE_LOCATION_WINDOWS
    elif platform.system() == 'Linux':
        return pp.CONAN_PROFILE_LOCATION_LINUX
    elif platform.system() == 'Darwin':
        return pp.CONAN_PROFILE_LOCATION_MACOS


if __name__ == "__main__":

    if len(sys.argv) == 1:
        CONAN_PROFILE = get_conan_profile()
        CONANFILE = pp.CONANFILE_DESKTOP_LOCATION
    elif len(sys.argv) == 2 and sys.argv[1] == 'Android':
        CONAN_PROFILE = pp.CONAN_PROFILE_LOCATION_ANDROID
        CONANFILE = pp.CONANFILE_ANDROID_LOCATION
    else:
        raise ValueError("Unknown Platform: {}".format(sys.argv[1]))

    conan_install = ("conan install"
                    " --install-folder {}"
                    " --generator deploy"
                    " --profile {}"
                    " --update {}").format(pp.DEPS_DIR, CONAN_PROFILE, CONANFILE)

    os.system(conan_install)
