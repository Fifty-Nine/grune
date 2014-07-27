project(Grune)

cmake_minimum_required(VERSION 2.6)

find_package(Boost
    1.49.0
    REQUIRED
)

include_directories(${Grune_SOURCE_DIR} ${Boost_INCLUDE_DIRS})

add_compile_options("-std=c++11")

add_subdirectory(grune)
add_subdirectory(tests)

add_custom_target(check
    COMMAND ${Grune_BINARY_DIR}/tests/tests
    DEPENDS ${Grune_BINARY_DIR}/tests/tests
)
