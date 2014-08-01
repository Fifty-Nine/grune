add_executable(generate
    main.cpp
    test_anbncn.cpp
    test_numbers.cpp
    test_tdh.cpp
    test_turtle.cpp
)

link_directories(${Grune_BINARY_DIR}/grune)
target_link_libraries(generate grune ${Boost_LIBRARIES})

add_custom_command(
    TARGET generate 
    POST_BUILD
    COMMAND generate 
)

