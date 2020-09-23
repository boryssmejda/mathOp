from conans import ConanFile, CMake, tools
import platform

class HelloConan(ConanFile):
    name = "mathOp"
    version = "1.0"
    license = "MIT License"
    author = "Borys Smejda"
    url = "https://github.com/boryssmejda/CMake.git"
    description = ""
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}
    generators = "cmake"

    def source(self):
        self.run("git clone {}".format(self.url))

    def build(self):

        if platform.system() == 'Windows':
            self.run("cmake ../../source/CMake")
            self.run("cmake --build . --config Release --target install")
            self.run("cmake --build . --config Debug --target install")
        elif platform.system() == 'Linux':
            pass

    def package(self):
        self.copy("*", dst=".", src="../../source/CMake/install/mathOp")

    def package_info(self):
        self.cpp_info.libs = ["mathOp"]
        #self.cpp_info.debug.libs = ["mathOp_d"]

