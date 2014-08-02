add_executable(generate
    main.cpp
    test_anbncn.cpp
    test_numbers.cpp
    test_tdh.cpp
    test_turtle.cpp
)

link_directories(${Grune_BINARY_DIR}/grune)
target_link_libraries(generate grune ${Boost_LIBRARIES})

add_custom_command(
    TARGET generate 
    POST_BUILD
    COMMAND generate
    COMMAND diff -r expected results
    WORKING_DIRECTORY ${Grune_SOURCE_DIR}/generation_tests
)

add_custom_target(check_generate
    COMMAND generate
    COMMAND diff -r expected results
    DEPENDS generate
    WORKING_DIRECTORY ${Grune_SOURCE_DIR}/generation_tests
)

add_custom_target(commit_generate
    COMMAND generate
    COMMAND rm -r ./expected
    COMMAND cp -R results expected
    DEPENDS generate
    WORKING_DIRECTORY ${Grune_SOURCE_DIR}/generation_tests
)
