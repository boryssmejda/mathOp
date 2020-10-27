from conans import ConanFile, CMake, tools
import platform

class mathOpConan(ConanFile):
    name = "mathOp"
    version = "1.0"
    license = "MIT License"
    author = "Borys Smejda"
    url = "https://github.com/boryssmejda/CMake.git"
    description = "My adventure with Conan and CMake"
    settings = "os", "compiler", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": True}
    generators = "cmake"
    build_requires = ["fmt/7.0.3@borys/stable", "pybind11/2.6.0@borys/stable"]

    def source(self):
        self.run("git clone {}".format(self.url))

    def configure(self):
        if self.settings.compiler == "Visual Studio":
            del self.settings.compiler.runtime

    def build(self):

        self.run("conan install fmt/7.0.3@borys/stable -if ./CMake/deps -g deploy")
        self.run("conan install pybind11/2.6.0@borys/stable -if ./CMake/deps -g deploy")
        cmake_release = CMake(self, build_type="Release")
        cmake_release.definitions["BUILD_TESTS"] = "OFF"
        cmake_release.definitions["CMAKE_PREFIX_PATH"] = "./deps"
        cmake_release.configure(source_folder="./CMake")
        cmake_release.build()
        cmake_release.install()

        cmake_debug = CMake(self, build_type="Debug")
        cmake_debug.definitions["BUILD_TESTS"] = "OFF"
        cmake_debug.configure(source_folder="./CMake")
        cmake_debug.build()
        cmake_debug.install()

    def package(self):
        self.copy("*", dst=".", src="./CMake/install/mathOp")

    def package_info(self):
        self.cpp_info.libs = ["mathOp"]
