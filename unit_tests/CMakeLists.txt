add_executable(unit_tests
    test_main.cpp
    grammar_tests.cpp
    literal_tests.cpp
    misc_tests.cpp
    non_terminal_tests.cpp
    production_tests.cpp
    sequence_tests.cpp
)

link_directories(${Grune_BINARY_DIR}/grune)
target_link_libraries(unit_tests grune cppunit)

add_custom_command(
    TARGET unit_tests 
    POST_BUILD
    COMMAND unit_tests 
)

