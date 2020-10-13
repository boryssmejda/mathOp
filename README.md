# mathOp
mathOp is a C++ library, whose main goal was to examine the interoperability between [CMake](https://cmake.org/) and [Conan](https://conan.io/) in multiplatform development using C++.

## Motivation
I wanted to create this project to put together all I have learned during my 2020 internship in [Hexagon](https://hexagon.com/)
in their office in Łódź. Back then I was tasked with development of an Qt GUI application that could be deployed on Windows,
Android and iOS.
This time I wanted to create a simple library performing basic mathematical operations such as addition, subtraction, multiplication
and division. The library should have an external dependency and should be tested using a testing framework.
External dependency that I have chosen was [fmt](https://github.com/fmtlib/fmt).
The reasons were following:
* Portability with consistent output across platforms and support for older compilers
* Implementation of C++20 std::format, so that I could get a grasp of what is in store in C++20

I then wanted to write a set of unit tests to verify that my library is working correctly. As a test framework I went for
[Google Test](https://github.com/google/googletest). Mainly because I had already used it before and the project had to be
compiled first. This was what I was looking for, to make the project work across different platforms and it could really show
the potential of [Conan](https://conan.io/) as a package manager.

With the help of **CMake** and **Conan**, I wanted to make library easy to use as a potential 3rd party.
So that the consumer should only do two things in its CMakeLists.txt
```
find_package(mathOp)
target_link_libraries(Target PRIVATE mathOp::mathOp)
```

## Prerequisities
To use this library, you have to have following software installed:
- [CMake](https://cmake.org/), version minimum 3.16
- [Conan Package Manager](https://conan.io/), project works on v1.28.0

## Build from sources
To get the project, simply run:
```
git clone https://github.com/boryssmejda/mathOp.git
```
Depending on the platform, you want to build your project on, go to `scripts/` and the folder with
the platform you are interested in.

### Windows
```
./dependencies_install.ps1
./configure.ps1
./build.ps1 build_type - where build_type can be either Release or Debug
./install.ps1
./test.ps1 - to run library's unit tests
```
To clean up the workspace, simply run:</br>
```
./clean.ps1
./uninstall_dependencies.ps1
```

### Linux
```
./dependencies_install.sh
./configure.sh build_type - where build_type can be either Release or Debug
./build.sh
./install.sh
./test.sh
```
To delete `build` and `install` folders, simply run:
```
./clean.sh
```
To uninstall dependencies, simply run:
```
./uninstall_dependencies.sh
```

### Android
```
./dependencies_install.sh
./configure.sh build_type - where build_type can be either Release or Debug
./build.sh
./install.sh
./deploy.sh
./test.sh
```
To delete `build` and `install` folders, simply run:
```
./clean.sh
```
To uninstall dependencies, simply run:
```
./uninstall_dependencies.sh
```

### MacOS and iOS
```
./dependencies_install.sh
./configure
./build.sh build_type - either Debug or Release
./install build_type - pass Debug or Release, or nothing if both should be installed
./test - this command is only available on MacOS!
```
Cleaning the workspace of the `build/` and `install/` folders is as simple as running:
```
./clean.sh
```
Dependencies will be uninstalled, if you run:
```
./uninstall_dependencies.sh
```

## Adding to your project
To add `mathOp` as your dependency, simply place the built package into some known location,
show CMake where `find_package` should look for it,</br>
by pointing `CMAKE_PREFIX_PATH` to its location.
In your CMakeLists.txt simply write:
```
find_package(mathOp CONFIG REQUIRED)
target_link_libraries(target_name PRIVATE mathOp::mathOp)
```

## Tasks done already
1. Create scripts to configure, build, install and test the project across different platforms
   - PowerShell scripts to build project on Windows
   - Bash scripts for Linux, MacOS, Android and iOS
2. Write CMakeLists.txt that fullfills following functions:
   - creates library that uses C++17
   - finds and links all the project dependencies
   - adds precompiled headers for the target
   - installs project in specified location so that it is easy for others to consume the library
   - creates test and provides an easy mechanism to run all the tests regarding the development platform
3. Creation of Conan packages for header-only fmt and Google Test's binaries for 5 platforms
4. Creation of a C++ static library
5. Set of unit tests written with Google Test

## ToDo List
1. Create Conan packages and Conan recipe for mathOp library
2. Check if mathOp package can be easily consumed by external project
3. Add option to build mathOp as shared library with exported symbols
4. The Cross Platform Public C Interface
5. Call the library methods in Python scripts
6. Replace makefiles with Ninja as a default build system on UNIX platforms
7. Python scripts for uniform project building.
   - Compare their code with the platform specific scripts.
   - Check which one is more readable and potentially easier to maintain
8. Setup Continuous Integration for the project

## Acknowledgements
I would like to thank my friend [Grzegorz](https://github.com/Greg-Skowronski),
without whom I would not be able to prepare this project.</br>
He shared his time and, most importantly, his Macbook so I could experiment with porting the project
on both MacOS and iOS.</br>
Thank you Grzegorz!
