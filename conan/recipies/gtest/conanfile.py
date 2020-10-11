from conans import ConanFile, CMake, tools


class GTestConan(ConanFile):
    name = "gtest"
    version = "1.10.0"
    license = "https://github.com/google/googletest/blob/master/googletest/LICENSE"
    author = "Borys Smejda borys.smejda@gmail.com"
    url = "https://github.com/google/googletest.git"
    description = "Google Testing and Mocking Framework"
    topics = ("C++", "unittests")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"

    def source(self):
        self.run("git clone {0} && cd googletest && git checkout tags/release-{1} -b v{1}-branch".format(self.url, self.version))

    def build(self):
        cmake_release = CMake(self, build_type="Release")
        cmake_release.definitions["gtest_force_shared_crt"] = "ON"
        cmake_release.definitions["CMAKE_POSITION_INDEPENDENT_CODE"] = "ON"
        cmake_release.configure(source_folder="./googletest")
        cmake_release.build()
        cmake_release.install()

        cmake_debug = CMake(self, build_type="Debug")
        cmake_debug.definitions["gtest_force_shared_crt"] = "ON"
        cmake_debug.definitions["CMAKE_POSITION_INDEPENDENT_CODE"] = "ON"
        cmake_debug.configure(source_folder="./googletest")
        cmake_debug.build()
        cmake_debug.install()

    def package(self):
        self.copy("*.h", dst="include", src="hello")
        self.copy("*hello.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["hello"]

