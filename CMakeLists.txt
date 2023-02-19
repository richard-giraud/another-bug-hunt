cmake_minimum_required(VERSION 3.24)
project(another_bug_hunt)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(another_bug_hunt ${SDL2_INCLUDE_DIRS})

add_executable(another_bug_hunt main.cpp)
target_link_libraries(another_bug_hunt ${SDL2_LIBRARIES})
