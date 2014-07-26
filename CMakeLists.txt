project(GRAMMAR)

cmake_minimum_required(VERSION 2.6)

add_subdirectory(grammar)
add_subdirectory(tests)

add_custom_target(testsuite COMMAND ${GRAMMAR_BINARY_DIR}/tests/tests 
                  DEPENDS ${GRAMMAR_BINARY_DIR}/tests/tests)
