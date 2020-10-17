
cmake_minimum_required(VERSION 3.16)

    add_library(mathOp
        mathOp.h
        INTERNAL/add.cpp
        INTERNAL/subtract.cpp
        INTERNAL/multiply.cpp
        INTERNAL/divide.cpp
    )

    target_compile_definitions(mathOp
        PUBLIC
            $<$<BOOL:${BUILD_SHARED_LIBS}>:MATHOP_SHARED>
            $<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:MATHOP_STATIC>
    )

    if(BUILD_SHARED_LIBS AND NOT WIN32)
        target_compile_options(mathOp
            PRIVATE
                -fvisibility=hidden
                -fvisibility-inlines-hidden
        )
    endif()

    set_target_properties(mathOp PROPERTIES PUBLIC_HEADER mathOp.h)
    target_include_directories(mathOp
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:include>
    )

    target_compile_definitions(mathOp
        PRIVATE
            FMT_HEADER_ONLY
    )
    target_precompile_headers(mathOp
        PRIVATE
            "${FMT_HEADERS_LOCATION}/fmt/format.h"
            <stdexcept>
            <limits>
    )

    ###########################################3333

    add_library(mathOp_c_api
        SHARED
            mathOp_c_api.h
            INTERNAL/mathOp_c_api.cpp
    )

    target_compile_definitions(mathOp_c_api
        PUBLIC
            MATHOP_C_API_EXPORTS
    )

    set_target_properties(mathOp_c_api PROPERTIES PUBLIC_HEADER mathOp_c_api.h)
    target_include_directories(mathOp_c_api
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:include>
    )

    target_link_libraries(mathOp_c_api
        PRIVATE
            mathOp
    )

    if(NOT WIN32)
        target_compile_options(mathOp_c_api
            PRIVATE
                -fvisibility=hidden
                -fvisibility-inlines-hidden
        )
    endif()

    install_target(NAME "mathOp" "mathOp_c_api"
                   NAMESPACE "mathOp"
                   HEADER_NAME "mathOp"
                   CMAKE_FILE "mathOp"
                   EXPORT_NAME "mathOp"
    )

    copy_dll_for_unittests(NAME "mathOp_c_api" LOCATION "mathOp_c_api")

    if(BUILD_SHARED_LIBS AND WIN32)
        copy_dll_for_unittests(NAME "mathOp" LOCATION "mathOp")
        copy_dll_for_unittests(NAME "mathOp" LOCATION "mathOp_c_api")
    endif()
