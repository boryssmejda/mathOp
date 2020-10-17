function(copy_dll_for_unittests)
    set(options OPTIONAL)
    set(oneValueArgs NAME LOCATION)
    set(multiValueArgs MULTI)

    cmake_parse_arguments(COPY_DLL "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN} )

    install(TARGETS ${COPY_DLL_NAME}
        CONFIGURATIONS Release
        RUNTIME DESTINATION bin/Release/${COPY_DLL_LOCATION}
    )

    install(TARGETS ${COPY_DLL_NAME}
        CONFIGURATIONS Debug
        RUNTIME DESTINATION bin/Debug/${COPY_DLL_LOCATION}
    )

endfunction()