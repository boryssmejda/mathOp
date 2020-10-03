import os

from conans import ConanFile, tools


class FmtConan(ConanFile):
    name = "fmt"
    version = "7.0.3"
    license = "Copyright (c) 2012 - present, Victor Zverovich"
    author = "Victor Zverovich"
    url = "https://github.com/fmtlib/fmt.git"
    description = "{fmt} is an open-source formatting library for C++."
    topics = ("c++", "formatting", "performance")
    no_copy_source = True
    # No settings/options are necessary, this is header only

    def source(self):
        self.run("git clone {0}".format(self.url))
        self.run("cd fmt && git checkout tags/{0} -b v{0}-branch".format(self.version))

    def package(self):
        self.copy("*h", dst="include/fmt", src="fmt/include/fmt")

    def package_id(self):
        self.info.header_only()
