cmake_minimum_required(VERSION 3.16)

    find_package(GTest CONFIG REQUIRED)

    add_executable(test_mathOp_add test_mathOp_add.cpp)
    list(APPEND tests test_mathOp_add)

    add_executable(test_mathOp_subtract test_mathOp_subtract.cpp)
    list(APPEND tests test_mathOp_subtract)

    add_executable(test_mathOp_multiply test_mathOp_multiply.cpp)
    list(APPEND tests test_mathOp_multiply)

    add_executable(test_mathOp_divide test_mathOp_divide.cpp)
    list(APPEND tests test_mathOp_divide)

    foreach(test ${tests})
        target_link_libraries(${test}
            PRIVATE
            mathOp
            GTest::gtest
            GTest::gtest_main
        )

        install(TARGETS ${test}
            CONFIGURATIONS Debug
            RUNTIME DESTINATION bin/Debug
        )

        install(TARGETS ${test}
            CONFIGURATIONS Release
            RUNTIME DESTINATION bin/Release
        )
    endforeach()
