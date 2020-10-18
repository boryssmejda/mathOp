macro(copy_dll_for_unittests)

    set(options OPTIONAL)
    set(oneValueArgs TARGET_NAME TARGET_LIB)
    set(multiValueArgs TESTSET DEPENDENCIES)

    cmake_parse_arguments(COPY_DLL "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN}
    )

    add_custom_command(
        TARGET
            ${COPY_DLL_TARGET_NAME}
            POST_BUILD
            COMMAND
                ${CMAKE_COMMAND} -E copy_if_different
                    $<TARGET_FILE:${COPY_DLL_TARGET_LIB}> $<TARGET_FILE_DIR:${COPY_DLL_TARGET_NAME}>
            COMMENT
                "Copying ${COPY_DLL_TARGET_LIB} into $<TARGET_FILE_DIR:${COPY_DLL_TARGET_NAME}> directory"
    )

endmacro(copy_dll_for_unittests)
