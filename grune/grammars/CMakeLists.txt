SET(PWD ${CMAKE_CURRENT_SOURCE_DIR})

SET(SOURCES
    ${SOURCES}
    ${PWD}/anbncn.cpp
    ${PWD}/turtle.cpp
    PARENT_SCOPE
)

SET(HEADERS
    ${HEADERS}
    ${PWD}/anbncn.hpp
    ${PWD}/turtle.hpp
    PARENT_SCOPE
)
