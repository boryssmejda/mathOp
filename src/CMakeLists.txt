
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

    # compile mathOp with PIC to link it against shared math_c_api on UNIX-like systems
    if(NOT WIN32)
        target_compile_options(mathOp
            PRIVATE
                -fvisibility=hidden
                -fvisibility-inlines-hidden
                -fPIC
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

    ###########################################

    # mathOp_c_api is only build and installed with static mathOp
    if(NOT MATHOP_BUILD_SHARED)
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
                    -fPIC
                    -fvisibility=hidden
                    -fvisibility-inlines-hidden
            )
        endif()

    endif()

    if(MATHOP_BUILD_SHARED)
        # install only mathOp when it is built as shared lib
        install_target(NAME "mathOp"
                    NAMESPACE "mathOp"
                    HEADER_NAME "mathOp"
                    CMAKE_FILE "mathOp"
                    EXPORT_NAME "mathOp"
                    PACKAGE_NAME "mathOp"
        )

        install_sharedLib_for_unittests(NAME "mathOp" LOCATION "mathOp" HEADER_NAME "mathOp" PACKAGE_NAME "mathOp")
    else()
        # mathOp_c_api is only build and installed with static mathOp
        install_target(NAME "mathOp" "mathOp_c_api"
                    NAMESPACE "mathOp"
                    HEADER_NAME "mathOp"
                    CMAKE_FILE "mathOp"
                    EXPORT_NAME "mathOp"
                    PACKAGE_NAME "mathOp"
        )

        install_sharedLib_for_unittests(NAME "mathOp_c_api" LOCATION "mathOp_c_api" HEADER_NAME "mathOp" PACKAGE_NAME "mathOp")
    endif()
