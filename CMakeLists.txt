project(GRAMMAR)

cmake_minimum_required(VERSION 2.6)

find_package(Boost
    1.49.0
    REQUIRED
)

include_directories(${GRAMMAR_SOURCE_DIR} ${Boost_INCLUDE_DIRS})

add_compile_options("-std=c++11")

add_subdirectory(grammar)
add_subdirectory(tests)

