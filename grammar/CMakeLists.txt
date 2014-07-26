include_directories(${GRAMMAR_SOURCE_DIR})
add_library(grammar 
    literal.cpp
    non_terminal.cpp
    production.cpp
    symbol.cpp 
    terminal.cpp 
    types.cpp
)

target_compile_options(grammar PUBLIC "-std=c++11")
