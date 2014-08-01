SET(SOURCES
    generate.cpp
    grammar.cpp
    non_terminal.cpp
    production.cpp
    sentence_iterator.cpp
    symbol.cpp
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
