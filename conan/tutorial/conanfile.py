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
        self.configure()
        if platform.system() == 'Windows':
            if self.options.shared == True:
                self.run("cmake -S ./CMake -B . -DBUILD_SHARED_LIBS=ON")
            else:
                self.run("cmake -S ./CMake -B .")

            self.run("cmake --build . --config Release --target install")
            self.run("cmake --build . --config Debug --target install")

        elif platform.system() == 'Linux':
            if self.options.shared == True:
                self.run("cmake -S ./CMake -B . -DCMAKE_BUILD_TYPE=DEBUG -DBUILD_SHARED_LIBS=ON")
            else
                self.run("cmake -S ./CMake -B . -DCMAKE_BUILD_TYPE=DEBUG")

            self.run("cmake --build . --config RELEASE --target install")

            if self.options.shared == True:
                self.run("cmake -S ./CMake -B . -DCMAKE_BUILD_TYPE=RELEASE -DBUILD_SHARED_LIBS=ON")
            else
                self.run("cmake -S ./CMake -B . -DCMAKE_BUILD_TYPE=RELEASE -DBUILD_SHARED_LIBS=ON")

            self.run("cmake --build . --config RELEASE --target install")

    def package(self):
        self.copy("*", dst=".", src="./CMake/install/mathOp")

    def package_info(self):
        self.cpp_info.libs = ["mathOp"]
