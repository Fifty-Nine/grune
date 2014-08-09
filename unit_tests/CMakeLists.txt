add_executable(unit_tests
    test_main.cpp
    grammar_tests.cpp
    json_tests.cpp
    literal_tests.cpp
    misc_tests.cpp
    non_terminal_tests.cpp
    production_tests.cpp
    sequence_tests.cpp
    yaml_tests.cpp
    tests.cpp
)

link_directories(${Grune_BINARY_DIR}/grune)
target_link_libraries(unit_tests 
    grune 
    grune-json
    grune-yaml 
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_check_target(unit_tests unit_tests)
