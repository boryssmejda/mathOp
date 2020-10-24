import os
import sys

from conans import ConanFile, CMake, tools


class Pybind11TestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.h", dst="bin", src="include")

    def test(self):
        sys.path.append("./bin")
        import example
        print("Add %s" % example.add(2, 3))
        assert example.add(2, 40) == 42