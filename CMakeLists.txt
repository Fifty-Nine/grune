project(Grune)

cmake_minimum_required(VERSION 2.6)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost
    1.49.0
    COMPONENTS unit_test_framework
)

find_package(Boost
    1.49.0
    COMPONENTS filesystem system
    REQUIRED
)

include_directories(
    ${Grune_SOURCE_DIR} 
    ${Boost_INCLUDE_DIRS} 
    contrib/cpp-flatten
)

add_compile_options("-std=c++11")

set(CHECK_TARGETS CACHE INTERNAL "")
set(COMMIT_TARGETS CACHE INTERNAL "")

function(add_check_target subdir target)
    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND git clean -xdf ./results
        COMMAND ${target}
        COMMAND diff -r --exclude=.gitignore expected results
        WORKING_DIRECTORY ${Grune_SOURCE_DIR}/${subdir}
    )
    add_custom_target(check_${subdir}
        COMMAND git clean -xdf ./results
        COMMAND ${target}
        COMMAND diff -r --exclude=.gitignore expected results
        WORKING_DIRECTORY ${Grune_SOURCE_DIR}/${subdir}
    )
    add_custom_target(commit_${subdir}
        COMMAND git clean -xdf ./results
        COMMAND ${target}
        COMMAND rm -r ./expected
        COMMAND cp -R results expected
        COMMAND git checkout expected/.gitignore
        WORKING_DIRECTORY ${Grune_SOURCE_DIR}/${subdir}
    )
    set(CHECK_TARGETS
        ${CHECK_TARGETS}
        check_${subdir}
        CACHE INTERNAL "" FORCE
    )
    set(COMMIT_TARGETS
        ${COMMIT_TARGETS}
        commit_${subdir}
        CACHE INTERNAL "" FORCE
    )
endfunction(add_check_target)

add_subdirectory(grune)
add_subdirectory(grune-yaml)
add_subdirectory(grune-json)
add_subdirectory(generation_tests)

if (Boost_UNIT_TEST_FRAMEWORK_FOUND)
    add_subdirectory(unit_tests)
else(Boost_UNIT_TEST_FRAMEWORK_FOUND)
    message(
        WARNING 
        "Boost unit test framework not found. Unit tests will not be built."
    )
endif (Boost_UNIT_TEST_FRAMEWORK_FOUND)

add_custom_target(check
    DEPENDS ${CHECK_TARGETS}
)

add_custom_target(commit
    DEPENDS ${COMMIT_TARGETS}
)
