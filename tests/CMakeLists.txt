include_directories(${GRAMMAR_SOURCE_DIR})
link_directories(${GRAMMAR_BINARY_DIR}/grammar)

add_executable(tests 
    test_main.cpp
    literal_tests.cpp
    non_terminal_tests.cpp
    production_tests.cpp
)

target_link_libraries(tests grammar cppunit)
