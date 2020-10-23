from conans import ConanFile, CMake
import os

class TestFmtConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def build(self):
        cmake = CMake(self, build_type="Release")
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")

    def test(self):
        os.chdir("bin")
        self.run(".%sfmtTest" % os.sep)