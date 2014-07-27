add_executable(generate
    main.cpp
)

link_directories(${Grune_BINARY_DIR}/grune)
target_link_libraries(generate grune ${Boost_LIBRARIES})
