function(install_target)

    set(options OPTIONAL)
    set(oneValueArgs NAME NAMESPACE HEADER_NAME)
    set(multiValueArgs XD)

    cmake_parse_arguments(INSTALL_TARGET "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN} )

    install(TARGETS ${INSTALL_TARGET_NAME}
        EXPORT ${INSTALL_TARGET_NAME}_debug
        CONFIGURATIONS Debug
        ARCHIVE DESTINATION lib/Debug
        RUNTIME DESTINATION bin/Debug
        PUBLIC_HEADER DESTINATION include/${INSTALL_TARGET_HEADER_NAME}
    )

    install(TARGETS ${INSTALL_TARGET_NAME}
        EXPORT ${INSTALL_TARGET_NAME}_release
        CONFIGURATIONS Release
        ARCHIVE DESTINATION lib/Release
        RUNTIME DESTINATION bin/Release
        PUBLIC_HEADER DESTINATION include/${INSTALL_TARGET_HEADER_NAME}
    )

    install(EXPORT ${INSTALL_TARGET_NAME}_debug
        DESTINATION cmake/
        FILE ${INSTALL_TARGET_NAME}Config.cmake
        NAMESPACE ${INSTALL_TARGET_NAMESPACE}::
        CONFIGURATIONS DEBUG
    )

    install(EXPORT ${INSTALL_TARGET_NAME}_release
        DESTINATION cmake/
        FILE ${INSTALL_TARGET_NAME}Config.cmake
        NAMESPACE ${INSTALL_TARGET_NAMESPACE}::
        CONFIGURATIONS RELEASE
    )
endfunction()