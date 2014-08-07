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

set_contrib_project_vars(json11)
ExternalProject_Add(json11_build
    PREFIX ${json11_PREFIX}
    STAMP_DIR ${json11_STAMP_DIR}
    SOURCE_DIR ${json11_SOURCE_DIR}
    BINARY_DIR ${json11_BINARY_DIR}
    GIT_REPOSITORY https://github.com/Fifty-Nine/json11.git
    GIT_TAG master 
    INSTALL_COMMAND ""
)

add_library(json11 IMPORTED STATIC)
set_property(TARGET json11 PROPERTY IMPORTED_LOCATION ${json11_BINARY_DIR}/libjson11.a)
add_dependencies(json11 json11_build)

target_include_directories(grune-json PUBLIC ${json11_SOURCE_DIR}/..)
target_link_libraries(grune-json grune json11)
