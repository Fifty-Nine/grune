add_executable(tests 
    test_main.cpp
    grammar_tests.cpp
    literal_tests.cpp
    misc_tests.cpp
    non_terminal_tests.cpp
    production_tests.cpp
    sequence_tests.cpp
)

link_directories(${Grune_BINARY_DIR}/grune)
target_link_libraries(tests grune cppunit)

add_custom_command(
    TARGET tests 
    POST_BUILD
    COMMAND ${Grune_BINARY_DIR}/tests/tests
)

