from conans import ConanFile, CMake, tools

class Pybind11Conan(ConanFile):
    name = "pybind11"
    version = "2.6.0"
    license = "Copyright (c) 2016 Wenzel Jakob <wenzel.jakob@epfl.ch>, All rights reserved."
    author = "Wenzel Jakob"
    url = "https://github.com/pybind/pybind11.git"
    description = "Seamless operability between C++11 and Python"
    topics = ("python", "bindings", "C++")


    def source(self):
        self.run(f"git clone {self.url}")
        self.run(f"cd pybind11 && git checkout tags/v{self.version} -b v{self.version}-branch")

    def build(self):
        cmake = CMake(self)
        cmake.definitions["PYBIND11_TEST"] = "OFF"
        cmake.configure(source_folder="pybind11")
        cmake.install()

    def package(self):
        pass
        # cmake.install() will automatically place all headers into package folder

    def package_id(self):
        self.info.header_only()

