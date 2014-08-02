add_executable(unit_tests
    test_main.cpp
    grammar_tests.cpp
    literal_tests.cpp
    misc_tests.cpp
    non_terminal_tests.cpp
    production_tests.cpp
    sequence_tests.cpp
    yaml_tests.cpp
)

link_directories(${Grune_BINARY_DIR}/grune)
target_link_libraries(unit_tests grune grune-yaml cppunit)

add_custom_command(
    TARGET unit_tests 
    POST_BUILD
    COMMAND unit_tests
    COMMAND diff -r expected results
    WORKING_DIRECTORY ${Grune_SOURCE_DIR}/unit_tests
)

add_custom_target(check_unit_tests
    COMMAND unit_tests
    COMMAND diff -r --exclude=.gitignore expected results
    DEPENDS unit_tests
    WORKING_DIRECTORY ${Grune_SOURCE_DIR}/unit_tests
)

add_custom_target(commit_unit_tests
    COMMAND unit_tests
    COMMAND rm -r ./expected
    COMMAND cp -R results expected
    DEPENDS unit_tests
    WORKING_DIRECTORY ${Grune_SOURCE_DIR}/unit_tests
)
