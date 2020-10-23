import os

from conans import ConanFile, tools, CMake


class FmtConan(ConanFile):
    name = "fmt"
    version = "7.0.3"
    license = "Copyright (c) 2012 - present, Victor Zverovich"
    author = "Victor Zverovich"
    url = "https://github.com/fmtlib/fmt.git"
    description = "{fmt} is an open-source formatting library for C++."
    topics = ("c++", "formatting", "performance")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "header_only": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "header_only": False, "fPIC": True}

    def source(self):
        self.run("git clone {0}".format(self.url))
        self.run("cd fmt && git checkout tags/{0} -b v{0}-branch".format(self.version))

    def build(self):
        cmake_release = CMake(self, build_type="Release")
        cmake_release.definitions["FMT_DOC"] = "OFF"
        cmake_release.definitions["FMT_TEST"] = "OFF"
        cmake_release.configure(source_folder="./fmt")
        cmake_release.build()
        cmake_release.install()

        cmake_debug = CMake(self, build_type="Debug")
        cmake_debug.definitions["FMT_DOC"] = "OFF"
        cmake_debug.definitions["FMT_TEST"] = "OFF"
        cmake_debug.configure(source_folder="./fmt")
        cmake_debug.build()
        cmake_debug.install()

    def package(self):
        #self.copy("*h", dst="include/fmt", src="fmt/include/fmt")
        pass

    def package_id(self):
        pass
        #self.cpp_info.libs = ["fmt"]
