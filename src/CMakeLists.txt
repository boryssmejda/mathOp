
cmake_minimum_required(VERSION 3.16)

    set(MATHOP_SOURCES
        mathOp.h
        INTERNAL/add.cpp
        INTERNAL/subtract.cpp
        INTERNAL/multiply.cpp
        INTERNAL/divide.cpp
    )

    if(MATHOP_BUILD_SHARED)
        add_library(mathOp
            SHARED
            ${MATHOP_SOURCES}
        )
    else()
        add_library(mathOp
            STATIC
            ${MATHOP_SOURCES}
        )
    endif()

    target_compile_definitions(mathOp
        PUBLIC
            $<$<BOOL:${MATHOP_BUILD_SHARED}>:MATHOP_SHARED>
            $<$<NOT:$<BOOL:${MATHOP_BUILD_SHARED}>>:MATHOP_STATIC>
    )

    set_target_properties(mathOp
        PROPERTIES
            PUBLIC_HEADER mathOp.h
            POSITION_INDEPENDENT_CODE ON
            CXX_VISIBILITY_PRESET hidden
            VISIBILITY_INLINES_HIDDEN ON
    )
    target_include_directories(mathOp
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:mathOp/include>
    )

    get_target_property(FMT_HEADER_LOCATION fmt::fmt INTERFACE_INCLUDE_DIRECTORIES)
    target_precompile_headers(mathOp
        PRIVATE
            "${FMT_HEADER_LOCATION}/fmt/core.h"
            <stdexcept>
            <limits>
            <iostream>
    )

    target_link_libraries(mathOp
        PRIVATE
            fmt::fmt
    )

    ###########################################

    # mathOp_c_api is only build and installed with static mathOp

    add_library(mathOp_c_api
        SHARED
            mathOp_c_api.h
            INTERNAL/mathOp_c_api.cpp
    )

    target_precompile_headers(mathOp_c_api REUSE_FROM mathOp)

    target_compile_definitions(mathOp_c_api
        PUBLIC
            MATHOP_C_API_EXPORTS
    )

    set_target_properties(mathOp_c_api
        PROPERTIES
            PUBLIC_HEADER mathOp_c_api.h
            POSITION_INDEPENDENT_CODE ON
            CXX_VISIBILITY_PRESET hidden
            VISIBILITY_INLINES_HIDDEN ON
    )
    target_include_directories(mathOp_c_api
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:mathOp/include>
    )

    target_link_libraries(mathOp_c_api
        PRIVATE
            mathOp
    )

    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/mathOpConfigVersion.cmake
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion
    )

    install_target(NAME "mathOp" "mathOp_c_api"
                NAMESPACE "mathOp"
                HEADER_NAME "mathOp"
                CMAKE_FILE "mathOp"
                EXPORT_NAME "mathOp"
                PACKAGE_NAME "mathOp"
    )

    pybind11_add_module(mathOp_cpp mathOp_pybind11_module.cpp)
    target_link_libraries(mathOp_cpp PRIVATE mathOp)

    install(TARGETS mathOp_cpp
        ARCHIVE DESTINATION mathOp/lib/
        LIBRARY DESTINATION mathOp/lib/
        RUNTIME DESTINATION mathOp/bin/
    )
