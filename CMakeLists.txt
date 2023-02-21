cmake_minimum_required(VERSION 3.24)
project(another_bug_hunt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
include_directories(another_bug_hunt ${SDL2_INCLUDE_DIRS})

find_package(Cairo REQUIRED)
include_directories(another_bug_hunt ${CAIRO_INCLUDE_DIRS})

add_executable(another_bug_hunt
        main.cpp
        src/Application.cpp src/Application.h
        src/models/Room.cpp src/models/Room.h
        src/Surface.cpp src/Surface.h
        src/models/Marine.cpp src/models/Marine.h
        src/services/Marines.cpp src/services/Marines.h)
target_link_libraries(another_bug_hunt ${SDL2_LIBRARIES})
target_link_libraries(another_bug_hunt ${CAIRO_LIBRARIES})
