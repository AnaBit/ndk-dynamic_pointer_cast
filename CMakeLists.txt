cmake_minimum_required(VERSION 2.8)

project(dlopen_test)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "-frtti -g -Wl,-E -Wno-error=unused-command-line-argument")

#set (CMAKE_CXX_FLAGS "-frtti -g")

#SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "-rdynamic")

include_directories(${PROJECT_SOURCE_DIR})

add_library(ddlib MODULE dlopen_lib.cpp)

add_library(loadlib SHARED load_lib.cpp)
target_link_libraries(loadlib dl)

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} loadlib dl)
