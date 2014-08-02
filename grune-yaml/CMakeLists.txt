SET(SOURCES
    grammar.cpp
    production.cpp
    symbol.cpp
)

SET(HEADERS
    grammar.hpp
    grune-yaml.hpp
    production.hpp
    symbol.hpp
)

add_library(grune-yaml
    ${SOURCES}
    ${HEADERS}
)
target_link_libraries(grune-yaml grune yaml-cpp)

add_subdirectory(samples)
