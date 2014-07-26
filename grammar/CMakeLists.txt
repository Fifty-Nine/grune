include_directories(${GRAMMAR_SOURCE_DIR})
add_library(grammar 
    symbol.cpp 
    terminal.cpp 
    non_terminal.cpp
)

target_compile_options(grammar PUBLIC "-std=c++11")
