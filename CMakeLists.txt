if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "In source builds are not allowed!")
endif()

cmake_minimum_required(VERSION 3.16)

option(BUILD_SHARED_LIBS OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(CMakeExperiment)

    add_library(mathOp src/mathOp.cpp src/mathOp.h)
    set_target_properties(mathOp PROPERTIES PUBLIC_HEADER src/mathOp.h)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install/mathOp")

    install(TARGETS mathOp
            EXPORT mathOp_debug
            CONFIGURATIONS Debug
            ARCHIVE DESTINATION lib/Debug
            RUNTIME DESTINATION lib/Debug
            PUBLIC_HEADER DESTINATION include/mathOp
    )

    install(TARGETS mathOp
            EXPORT mathOp_release
            CONFIGURATIONS Release
            ARCHIVE DESTINATION lib/Release
            RUNTIME DESTINATION lib/Release
            PUBLIC_HEADER DESTINATION include/mathOp
    )

    install(EXPORT mathOp_debug
            DESTINATION cmake/
            FILE mathOp-config.cmake
            NAMESPACE mathOp::
            CONFIGURATIONS DEBUG
    )

    install(EXPORT mathOp_release
            DESTINATION cmake/
            FILE mathOp-config.cmake
            NAMESPACE mathOp::
            CONFIGURATIONS RELEASE
    )

    install(DIRECTORY ${PROJECT_BINARY_DIR}/Debug
        DESTINATION lib
        FILES_MATCHING
        PATTERN "*.pdb"
        PATTERN "*.ilk"
        PATTERN "*.exp"
    )

    target_include_directories(mathOp
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
            $<INSTALL_INTERFACE:include>
    )
