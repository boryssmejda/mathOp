
cmake_minimum_required(VERSION 3.16)

    add_library(mathOp mathOp.cpp mathOp.h)
    set_target_properties(mathOp PROPERTIES PUBLIC_HEADER mathOp.h)
    target_include_directories(mathOp
        PRIVATE
        ${CMAKE_SOURCE_DIR}/deps/fmt/include
    )

    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install/mathOp")

    install(TARGETS mathOp
            EXPORT mathOp_debug
            CONFIGURATIONS Debug
            ARCHIVE DESTINATION lib/Debug
            PUBLIC_HEADER DESTINATION include/mathOp
    )

    install(TARGETS mathOp
            EXPORT mathOp_release
            CONFIGURATIONS Release
            ARCHIVE DESTINATION lib/Release
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

    install(DIRECTORY ${PROJECT_BINARY_DIR}/Debug
        DESTINATION lib
        FILES_MATCHING
        PATTERN "*.pdb"
    )

    target_include_directories(mathOp
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
            $<INSTALL_INTERFACE:include>
    )
