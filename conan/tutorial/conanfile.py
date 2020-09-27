from conans import ConanFile, CMake, tools
import platform

class mathOpConan(ConanFile):
    name = "mathOp"
    version = "1.0"
    license = "MIT License"
    author = "Borys Smejda"
    url = "https://github.com/boryssmejda/CMake.git"
    description = ""
    settings = "os", "compiler", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"

    def source(self):
        self.run("git clone {}".format(self.url))

    def configure(self):
        if self.settings.compiler == "Visual Studio":
            del self.settings.compiler.runtime

    def build(self):
        cmake_release = CMake(self, build_type="Release")
        cmake_release.configure(source_folder="./CMake")
        cmake_release.build()
        cmake_release.install()

        cmake_debug = CMake(self, build_type="Debug")
        cmake_debug.configure(source_folder="./CMake")
        cmake_debug.build()
        cmake_debug.install()

    def package(self):
        self.copy("*", dst=".", src="./CMake/install/mathOp")

    def package_info(self):
        self.cpp_info.libs = ["mathOp"]
