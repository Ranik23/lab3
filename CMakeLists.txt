cmake_minimum_required(VERSION 3.22.1)
project(Lab1)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES 
        "include/*.h"
        "cpp_files/*.tpp"
    )

add_executable(Main main_files/main.cpp ${SOURCES})

add_executable(Main2 main_files/main2.cpp ${SOURCES})

add_executable(SetTest tests/set_test.cpp)
target_link_libraries(SetTest gtest gtest_main)

add_executable(SplayTest tests/splay_test.cpp)
target_link_libraries(SplayTest gtest gtest_main)

add_executable(CacheTest tests/cache_test.cpp)
target_link_libraries(CacheTest gtest gtest_main)
