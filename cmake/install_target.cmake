function(install_target)

    set(options OPTIONAL)
    set(oneValueArgs NAMESPACE HEADER_NAME CMAKE_FILE EXPORT_NAME)
    set(multiValueArgs NAME)

    cmake_parse_arguments(INSTALL_TARGET "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN} )

    install(TARGETS ${INSTALL_TARGET_NAME}
        EXPORT ${INSTALL_TARGET_EXPORT_NAME}_debug
        CONFIGURATIONS Debug
        ARCHIVE DESTINATION lib/Debug
        RUNTIME DESTINATION bin/Debug
        PUBLIC_HEADER DESTINATION include/${INSTALL_TARGET_HEADER_NAME}
    )

    install(TARGETS ${INSTALL_TARGET_NAME}
        EXPORT ${INSTALL_TARGET_EXPORT_NAME}_release
        CONFIGURATIONS Release
        ARCHIVE DESTINATION lib/Release
        RUNTIME DESTINATION bin/Release
        PUBLIC_HEADER DESTINATION include/${INSTALL_TARGET_HEADER_NAME}
    )

    install(EXPORT ${INSTALL_TARGET_EXPORT_NAME}_debug
        DESTINATION cmake/
        FILE ${INSTALL_TARGET_EXPORT_NAME}Config.cmake
        NAMESPACE ${INSTALL_TARGET_NAMESPACE}::
        CONFIGURATIONS DEBUG
    )

    install(EXPORT ${INSTALL_TARGET_EXPORT_NAME}_release
        DESTINATION cmake/
        FILE ${INSTALL_TARGET_EXPORT_NAME}Config.cmake
        NAMESPACE ${INSTALL_TARGET_NAMESPACE}::
        CONFIGURATIONS RELEASE
    )
endfunction()