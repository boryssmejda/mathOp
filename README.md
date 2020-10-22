# mathOp
mathOp is a C++ library, whose main goal was to examine the interoperability between [CMake](https://cmake.org/) and [Conan](https://conan.io/) in multiplatform development using C++.

## Table of contents
- [mathOp](#mathop)
  - [Table of contents](#table-of-contents)
  - [Motivation](#motivation)
  - [Prerequisities](#prerequisities)
  - [Setup](#setup)
    - [Windows](#windows)
    - [Linux](#linux)
    - [Android](#android)
    - [MacOS](#macos)
  - [Adding mathOp to your project](#adding-mathop-to-your-project)
  - [Code Examples](#code-examples)
    - [Operations on small numbers without underflow or overflow](#operations-on-small-numbers-without-underflow-or-overflow)
    - [Exception on overflow](#exception-on-overflow)
    - [Division by 0](#division-by-0)
  - [Tasks done already](#tasks-done-already)
  - [ToDo List](#todo-list)
  - [Acknowledgements](#acknowledgements)

## Motivation
I wanted to create this project to put together all I have learned during my 2020 internship in [Hexagon](https://hexagon.com/)
in their office in Łódź.</br>
Back then I was tasked with development of an Qt GUI application that could be deployed on Windows,
Android and iOS.</br>

I am fully aware, that the C++ code the library is written in, is extremely simple. However, the code complexity was not
of main intrest for me when doing this project.</br>
I just wanted to prepare a potential platform for any future multiplatform project
that I could start. I wanted also to experience any hurdles in preparing a multiplatform C++ project nowadays.</br>

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
```cmake
find_package(mathOp)
target_link_libraries(Target PRIVATE mathOp::mathOp)
```

## Prerequisities
To use this library, you have to have following software installed:
- [CMake](https://cmake.org/), version minimum 3.16
- [Conan Package Manager](https://conan.io/), project works on v1.28.0

## Setup
To get the project, simply run:
```
git clone https://github.com/boryssmejda/mathOp.git
```
Depending on the platform, you want to build your project on, go to `scripts/` and the folder with
the platform you are interested in.

### Windows
```
$ ./dependencies_install.ps1
$ ./configure.ps1
$ ./build.ps1 build_type - where build_type can be either Release or Debug
$ ./install.ps1
$ ./test.ps1 - to run library's unit tests
```
To clean up the workspace, simply run:</br>
```
$ ./clean.ps1
$ ./uninstall_dependencies.ps1
```

### Linux
```
$ ./dependencies_install.sh
$ ./configure.sh build_type - where build_type can be either Release or Debug
$ ./build.sh
$ ./install.sh
$ ./test.sh
```
To delete `build` and `install` folders, simply run:
```bash
$ ./clean.sh
```
To uninstall dependencies, simply run:
```bash
$ ./uninstall_dependencies.sh
```

### Android
```
$ ./dependencies_install.sh
$ ./configure.sh build_type - where build_type can be either Release or Debug
$ ./build.sh
$ ./install.sh
$ ./deploy.sh
$ ./test.sh
```
To delete `build` and `install` folders, simply run:
```bash
$ ./clean.sh
```
To uninstall dependencies, simply run:
```bash
$ ./uninstall_dependencies.sh
```

### MacOS
```
$ ./dependencies_install.sh
$ ./configure
$ ./build.sh build_type - either Debug or Release
$ ./install build_type - pass Debug or Release, or nothing if both should be installed
$ ./test - this command is only available on MacOS!
```
Cleaning the workspace of the `build/` and `install/` folders is as simple as running:
```bash
$ ./clean.sh
```
Dependencies will be uninstalled, if you run:
```bash
$ ./uninstall_dependencies.sh
```

## Adding mathOp to your project
To add `mathOp` as your dependency, simply place the built package into some known location,</br>
show CMake where `find_package` should look for it, by pointing `CMAKE_PREFIX_PATH` to its location.</br>
In your CMakeLists.txt simply write:
```cmake
find_package(mathOp CONFIG REQUIRED)
target_link_libraries(target_name PRIVATE mathOp::mathOp)
```

## Code Examples

### Operations on small numbers without underflow or overflow
```cpp
#include <mathOp/mathOp.h>

int main()
{
   int a = mathOp::add(10, 20);
   int b = mathOp::subtract(30, 10);
   int c = mathOp::multiply(9, 36);
   double d = mathOp::divide(100, 20);
}
```

### Exception on overflow
```cpp
#include <mathOp/mathOp.h>
#include <limits>
#include <stdexcept>

int main()
{
   const int MAX_INT = std::numeric_limits<int>::max();
   try
   {
      mathOp::add(MAX_INT, 1);
   }
   catch(const std::invalid_argument& ia)
   {
      ia.what();
   }
}
```

### Division by 0
```cpp
#include <mathOp/mathOp.h>
#include <stdexcept>

int main()
{
   const int billion = 1'000'000'000;
   try
   {
      mathOp::divide(billion, 0);
   }
   catch(const std::invalid_argument& ia)
   {
      ia.what();
   }
}
```


## Tasks done already
1. Create scripts to configure, build, install and test the project across different platforms
   - PowerShell scripts to build project on Windows
   - Bash scripts for Linux, MacOS and Android
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
- [ ] Create Conan packages and Conan recipe for mathOp library
- [ ] Check if mathOp package can be easily consumed by external project
- [x] Add option to build mathOp as shared library with exported symbols
- [x] The Cross Platform Public C Interface
- [x] Use C API in Python scripts
- [ ] Replace -fPIC, -fvisibility=hidden flag with CMake's proper variables
- [ ] Add custom exceptions to C++ library to differentiate between overflow and underflow
- [ ] Prepare unit tests in Python of the mathOp library
- [ ] Create fmt binary package using Conan
- [ ] Create Pybind 11 package with Conan Package Manager
- [x] Replace makefiles with Ninja as a default build system on UNIX platforms
- [x] Python scripts for uniform project building.
    - Compare their code with the platform specific scripts.
    - Check which one is more readable and potentially easier to maintain
- [ ] Setup Continuous Integration for the project

## Acknowledgements
I would like to thank my friend [Grzegorz](https://github.com/Greg-Skowronski),
without whom I couldn't prepare this project.</br>
He shared his time and, most importantly, his Macbook, so I could experiment</br>
with porting the project on both MacOS and iOS.</br>
Thank you Grzegorz!
