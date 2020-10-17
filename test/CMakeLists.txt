cmake_minimum_required(VERSION 3.16)

    find_package(GTest CONFIG REQUIRED)

    add_executable(test_mathOp_cpp_add
        mathOp_cpp/test_mathOp_cpp_add.cpp
    )
    list(APPEND tests
        test_mathOp_cpp_add
    )

    add_executable(test_mathOp_cpp_subtract
        mathOp_cpp/test_mathOp_cpp_subtract.cpp
    )
    list(APPEND tests
        test_mathOp_cpp_subtract
    )

    add_executable(test_mathOp_cpp_multiply
        mathOp_cpp/test_mathOp_cpp_multiply.cpp
    )
    list(APPEND tests
        test_mathOp_cpp_multiply
    )

    add_executable(test_mathOp_cpp_divide
        mathOp_cpp/test_mathOp_cpp_divide.cpp
    )
    list(APPEND tests
        test_mathOp_cpp_divide
    )

    ############# MATH_C_API ########################33

    add_executable(test_mathOp_c_api_add
        mathOp_c_api/test_mathOp_c_api_add.cpp
    )
    list(APPEND test_c_api
        test_mathOp_c_api_add
    )

    add_executable(test_mathOp_c_api_subtract
        mathOp_c_api/test_mathOp_c_api_subtract.cpp
    )
    list(APPEND test_c_api
        test_mathOp_c_api_subtract
    )

    add_executable(test_mathOp_c_api_multiply
        mathOp_c_api/test_mathOp_c_api_multiply.cpp
    )
    list(APPEND test_c_api
        test_mathOp_c_api_multiply
    )

    add_executable(test_mathOp_c_api_divide
        mathOp_c_api/test_mathOp_c_api_divide.cpp
    )
    list(APPEND test_c_api
        test_mathOp_c_api_divide
    )

    foreach(test ${tests})
        target_link_libraries(${test}
            PRIVATE
            mathOp
            GTest::gtest
            GTest::gtest_main
        )

        install(TARGETS ${test}
            CONFIGURATIONS Debug
            RUNTIME DESTINATION bin/Debug/mathOp
            BUNDLE DESTINATION bin/Debug/mathOp
        )

        install(TARGETS ${test}
            CONFIGURATIONS Release
            RUNTIME DESTINATION bin/Release/mathOp
            BUNDLE DESTINATION bin/Release/mathOp
        )
    endforeach()

    foreach(test ${test_c_api})

        target_link_libraries(${test}
            PRIVATE
                mathOp_c_api
                GTest::gtest
                GTest::gtest_main
        )

        install(TARGETS ${test}
                CONFIGURATIONS Debug
                RUNTIME DESTINATION bin/Debug/mathOp_c_api
                BUNDLE DESTINATION bin/Debug/mathOp_c_api
        )

        install(TARGETS ${test}
                CONFIGURATIONS Release
                RUNTIME DESTINATION bin/Release/mathOp_c_api
                BUNDLE DESTINATION bin/Release/mathOp_c_api
        )
    endforeach(test ${test_c_api})

    if(BUILD_SHARED_LIBS AND WIN32)
    #copy dll file into folders with executables
        add_custom_command(
            TARGET
                test_mathOp_cpp_add
                test_mathOp_c_api_add
            POST_BUILD
            COMMAND
                ${CMAKE_COMMAND} -E copy_if_different
                    $<TARGET_FILE:mathOp> $<TARGET_FILE_DIR:test_mathOp_cpp_add>
            COMMAND
                ${CMAKE_COMMAND} -E copy_if_different
                    $<TARGET_FILE:mathOp> $<TARGET_FILE_DIR:test_mathOp_c_api_add>
            DEPENDS
                $<TARGET_FILE:mathOp>
            COMMENT
                "Copying mathOp into mathOp_cpp directory"
        )
    endif()

    add_custom_command(
        TARGET
            test_mathOp_c_api_add
        POST_BUILD
        COMMAND
            ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:mathOp>
                $<TARGET_FILE:mathOp_c_api>
                $<TARGET_FILE_DIR:test_mathOp_c_api_add>
        DEPENDS
            $<TARGET_FILE:mathOp>
        COMMENT
            "Copying mathOp_c_api into mathOp_c_api directory"
    )
