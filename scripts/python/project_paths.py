import os

SCRIPTS_LOCATION = os.getcwd() # PROJECT_ROOT/scripts/python
SCRIPT_ROOT_LOCATION = os.path.dirname(SCRIPTS_LOCATION) # PROJECT_ROOT/scripts
PROJECT_ROOT = os.path.dirname(SCRIPT_ROOT_LOCATION)
DEPS_DIR = os.path.join(PROJECT_ROOT, "deps")
BUILD_DIR = os.path.join(PROJECT_ROOT, "build")
INSTALL_DIR = os.path.join(PROJECT_ROOT, "install")

CONAN_FOLDER_LOCATION = os.path.join(PROJECT_ROOT, "conan")
CONANFILE_DESKTOP_LOCATION = os.path.join(CONAN_FOLDER_LOCATION, "conanfiles", "desktop", "conanfile.txt")
CONANFILE_ANDROID_LOCATION = os.path.join(CONAN_FOLDER_LOCATION, "conanfiles", "android", "conanfile.txt")

CONAN_PROFILES_ROOT = os.path.join(CONAN_FOLDER_LOCATION, "profiles")
CONAN_PROFILE_LOCATION_WINDOWS = os.path.join(CONAN_PROFILES_ROOT, "conan-profile-windows.txt")
CONAN_PROFILE_LOCATION_LINUX = os.path.join(CONAN_PROFILES_ROOT, "conan-profile-linux.txt")
CONAN_PROFILE_LOCATION_MACOS = os.path.join(CONAN_PROFILES_ROOT, "conan-profile-macos.txt")
CONAN_PROFILE_LOCATION_ANDROID = os.path.join(CONAN_PROFILES_ROOT, "conan-profile-android.txt")

ANDROID_NDK_LOCATION = os.path.join(DEPS_DIR, "android_ndk_installer")

def print_project_paths():
    print("SCRIPTS_LOCATION: {}".format(SCRIPTS_LOCATION))
    print("SCRIPT_ROOT_LOCATION: {}".format(SCRIPT_ROOT_LOCATION))
    print("PROJECT_ROOT: {}".format(PROJECT_ROOT))
    print("DEPS_DIR: {}".format(DEPS_DIR))
    print("BUILD_DIR: {}".format(BUILD_DIR))
    print("INSTALL_DIR: {}".format(INSTALL_DIR))

    print("CONAN_FOLDER_LOCATION: {}".format(CONAN_FOLDER_LOCATION))
    print("CONANFILE_DESKTOP_LOCATION: {}".format(CONANFILE_DESKTOP_LOCATION))
    print("CONANFILE_ANDROID_LOCATION: {}".format(CONANFILE_ANDROID_LOCATION))

    print("CONAN_PROFILES_ROOT: {}".format(CONAN_PROFILES_ROOT))
    print("CONAN_PROFILE_LOCATION_WINDOWS: {}".format(CONAN_PROFILE_LOCATION_WINDOWS))
    print("CONAN_PROFILE_LOCATION_LINUX: {}".format(CONAN_PROFILE_LOCATION_LINUX))
    print("CONAN_PROFILE_LOCATION_MACOS: {}".format(CONAN_PROFILE_LOCATION_MACOS))
    print("CONAN_PROFILE_LOCATION_ANDROID: {}".format(CONAN_PROFILE_LOCATION_ANDROID))

    print("ANDROID_NDK_LOCATION: {}".format(ANDROID_NDK_LOCATION))

if __name__ == "__main__":
    print_project_paths()
