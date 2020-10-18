function(install_sharedLib_for_unittests)
    set(options OPTIONAL)
    set(oneValueArgs NAME LOCATION HEADER_NAME)
    set(multiValueArgs MULTI)

    cmake_parse_arguments(COPY_SHARED_LIB "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN} )

    install(TARGETS ${COPY_SHARED_LIB_NAME}
        CONFIGURATIONS Release
        RUNTIME DESTINATION bin/Release/${COPY_SHARED_LIB_LOCATION}
        LIBRARY DESTINATION bin/Release/${COPY_SHARED_LIB_LOCATION}
        PUBLIC_HEADER DESTINATION include/${COPY_SHARED_LIB_HEADER_NAME}
    )

    install(TARGETS ${COPY_SHARED_LIB_NAME}
        CONFIGURATIONS Debug
        RUNTIME DESTINATION bin/Debug/${COPY_SHARED_LIB_LOCATION}
        LIBRARY DESTINATION bin/Debug/${COPY_SHARED_LIB_LOCATION}
        PUBLIC_HEADER DESTINATION include/${COPY_SHARED_LIB_HEADER_NAME}
    )

endfunction()