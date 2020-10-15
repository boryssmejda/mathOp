
cmake_minimum_required(VERSION 3.16)

    add_library(mathOp
        mathOp.h
        INTERNAL/add.cpp
        INTERNAL/subtract.cpp
        INTERNAL/multiply.cpp
        INTERNAL/divide.cpp
    )

    target_compile_definitions(mathOp
        PRIVATE
            $<$<BOOL:${BUILD_SHARED_LIBS}>:MATHOP_SHARED>
    )

    target_compile_options(mathOp
        PRIVATE
        $<$<BOOL:$<AND:$<BOOL:${BUILD_SHARED_LIBS}>,$<CXX_COMPILER_ID:AppleClang,Clang>>>:-fvisibility=hidden>
    )

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

    install(TARGETS mathOp
            EXPORT mathOp_debug
            CONFIGURATIONS Debug
            ARCHIVE DESTINATION lib/Debug
            RUNTIME DESTINATION bin/Debug
            PUBLIC_HEADER DESTINATION include/mathOp
    )

    install(TARGETS mathOp
            EXPORT mathOp_release
            CONFIGURATIONS Release
            ARCHIVE DESTINATION lib/Release
            RUNTIME DESTINATION bin/Release
            PUBLIC_HEADER DESTINATION include/mathOp
    )

    install(EXPORT mathOp_debug
            DESTINATION cmake/
            FILE mathOpConfig.cmake
            NAMESPACE mathOp::
            CONFIGURATIONS DEBUG
    )

    install(EXPORT mathOp_release
            DESTINATION cmake/
            FILE mathOpConfig.cmake
            NAMESPACE mathOp::
            CONFIGURATIONS RELEASE
    )
