add_executable(make-samples
    main.cpp
)

target_link_libraries(make-samples grune-yaml)

add_custom_command(
    TARGET make-samples
    POST_BUILD
    COMMAND make-samples
    WORKING_DIRECTORY ${Grune_BINARY_DIR}/grune-yaml/samples
)
