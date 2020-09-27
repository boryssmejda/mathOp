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

    def build_windows(self):
        self.configure()
        if self.options.shared == True:
            self.run("cmake -S ./CMake -B . -DBUILD_SHARED_LIBS=ON")
        else:
            self.run("cmake -S ./CMake -B .")

        self.run("cmake --build . --config Release --target install")
        self.run("cmake --build . --config Debug --target install")


    def build_linux(self):
        if self.options.shared == True:
            self.run("cmake -S ./CMake -B . -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=ON")
        else:
            self.run("cmake -S ./CMake -B . -DCMAKE_BUILD_TYPE=Debug")

        self.run("cmake --build . --target install")

        if self.options.shared == True:
            self.run("cmake -S ./CMake -B . -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON")
        else:
            self.run("cmake -S ./CMake -B . -DCMAKE_BUILD_TYPE=Release")

        self.run("cmake --build . --target install")

    def build_android(self):
        print('Android welcome to <-------')
        cmake = CMake(self, build_type="Release")
        cmake.configure(source_folder="./CMake")
        cmake.build()
        cmake.install()

    def build(self):
        if self.settings.os == 'Windows':
            self.build_windows()

        elif self.settings.os == 'Linux':
            self.build_linux()

        elif self.settings.os == 'Android':
            self.build_android()

    def package(self):
        self.copy("*", dst=".", src="./CMake/install/mathOp")

    def package_info(self):
        self.cpp_info.libs = ["mathOp"]
