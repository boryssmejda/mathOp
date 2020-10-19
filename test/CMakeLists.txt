cmake_minimum_required(VERSION 3.16)

    find_package(GTest CONFIG REQUIRED)

    ##################### MATH_OP ##############################
    add_executable(test_mathOp_cpp_add
        mathOp_cpp/test_mathOp_cpp_add.cpp
    )

    add_executable(test_mathOp_cpp_subtract
        mathOp_cpp/test_mathOp_cpp_subtract.cpp
    )

    add_executable(test_mathOp_cpp_multiply
        mathOp_cpp/test_mathOp_cpp_multiply.cpp
    )

    add_executable(test_mathOp_cpp_divide
        mathOp_cpp/test_mathOp_cpp_divide.cpp
    )

    configure_unittests(
        TESTSET
            test_mathOp_cpp_add
            test_mathOp_cpp_subtract
            test_mathOp_cpp_multiply
            test_mathOp_cpp_divide

        LOCATION
            "mathOp"
        DEPENDENCIES
            GTest::gtest
            GTest::gtest_main
            mathOp
        PACKAGE_NAME
            "mathOp"
    )

    if(MATHOP_BUILD_SHARED AND WIN32)
        copy_dll_for_unittests(TARGET_NAME "test_mathOp_cpp_add" TARGET_LIB "mathOp")
    endif()
    #############==== MATH_C_API ########################33

    # MATHOP_C_API tests should be created only when building static MATHOP
    if(NOT MATHOP_BUILD_SHARED)
        add_executable(test_mathOp_c_api_add
            mathOp_c_api/test_mathOp_c_api_add.cpp
        )

        add_executable(test_mathOp_c_api_subtract
            mathOp_c_api/test_mathOp_c_api_subtract.cpp
        )

        add_executable(test_mathOp_c_api_multiply
            mathOp_c_api/test_mathOp_c_api_multiply.cpp
        )

        add_executable(test_mathOp_c_api_divide
            mathOp_c_api/test_mathOp_c_api_divide.cpp
        )

        configure_unittests(
            TESTSET
                test_mathOp_c_api_add
                test_mathOp_c_api_subtract
                test_mathOp_c_api_multiply
                test_mathOp_c_api_divide

            LOCATION
                "mathOp_c_api"
            DEPENDENCIES
                GTest::gtest
                GTest::gtest_main
                mathOp_c_api
            PACKAGE_NAME
                "mathOp"
        )

        if(WIN32)
            add_custom_command(
                TARGET
                    test_mathOp_c_api_add
                POST_BUILD
                COMMAND
                    ${CMAKE_COMMAND} -E copy_if_different
                        $<TARGET_FILE:mathOp_c_api>
                        $<TARGET_FILE_DIR:test_mathOp_c_api_add>
                COMMENT
                    "Copying mathOp_c_api into mathOp_c_api directory"
            )
        endif()
    endif()
