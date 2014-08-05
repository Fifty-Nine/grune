SET(SOURCES
    generate.cpp
    grammar.cpp
    non_terminal.cpp
    production.cpp
    sentence_iterator.cpp
    symbol.cpp
    symbol_traits.cpp
)

SET(HEADERS
    all.hpp
    generate.hpp
    grammar.hpp
    grune_fwd.hpp
    non_terminal.hpp
    production.hpp
    sentence_iterator.hpp
    symbol.hpp
    symbol_traits.hpp
)

add_subdirectory(grammars)
add_library(grune
    ${SOURCES}
    ${HEADERS}
)

set_contrib_project_vars(cpp-flatten)
ExternalProject_Add(cpp-flatten
    PREFIX ${cpp-flatten_PREFIX}
    GIT_REPOSITORY https://github.com/Fifty-Nine/cpp-flatten.git
    GIT_TAG 02af27986bbc80d3ef2e90af62bd3af0fefee40b
    INSTALL_COMMAND ""
)
target_include_directories(grune PUBLIC ${cpp-flatten_SOURCE_DIR})
