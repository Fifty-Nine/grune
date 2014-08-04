SET(SOURCES
    grammar.cpp
    production.cpp
    symbol.cpp
)

SET(HEADERS
    grammar.hpp
    grune-json.hpp
    production.hpp
    symbol.hpp
)

add_library(grune-json
    ${SOURCES}
    ${HEADERS}
)

add_library(json11 IMPORTED STATIC)
set_property(TARGET json11 PROPERTY IMPORTED_LOCATION "${Grune_BINARY_DIR}/contrib/json11/libjson11.a")

target_include_directories(grune-json PUBLIC "${Grune_SOURCE_DIR}/contrib")

target_link_libraries(grune-json grune json11)
