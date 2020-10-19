macro(configure_unittests)

    set(options OPTIONAL)
    set(oneValueArgs LOCATION PACKAGE_NAME)
    set(multiValueArgs TESTSET DEPENDENCIES)

    cmake_parse_arguments(CONFIGURE_UNIT_TESTS "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN}
    )

    foreach(test ${CONFIGURE_UNIT_TESTS_TESTSET})
        target_link_libraries(${test}
            PRIVATE
            ${CONFIGURE_UNIT_TESTS_DEPENDENCIES}
        )
    
        install(TARGETS ${test}
            CONFIGURATIONS Debug
            RUNTIME DESTINATION ${CONFIGURE_UNIT_TESTS_PACKAGE_NAME}/bin/Debug/${CONFIGURE_UNIT_TESTS_LOCATION}
            BUNDLE DESTINATION ${CONFIGURE_UNIT_TESTS_PACKAGE_NAME}/bin/Debug/${CONFIGURE_UNIT_TESTS_LOCATION}
        )
    
        install(TARGETS ${test}
            CONFIGURATIONS Release
            RUNTIME DESTINATION ${CONFIGURE_UNIT_TESTS_PACKAGE_NAME}/bin/Release/${CONFIGURE_UNIT_TESTS_LOCATION}
            BUNDLE DESTINATION ${CONFIGURE_UNIT_TESTS_PACKAGE_NAME}/bin/Release/${CONFIGURE_UNIT_TESTS_LOCATION}
        )

        set_target_properties(${test}
            PROPERTIES
                INSTALL_RPATH
                    "$ORIGIN"
                MACOSX_RPATH
                    TRUE
        )
    endforeach()

endmacro(configure_unittests)

