cmake_minimum_required(VERSION 3.5)

project(FilesAndStrings)

set(CMAKE_CXX_FLAGS_DEBUG "-ggdb -g -O0")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FilesAndStrings main.cpp)

add_subdirectory(libs/writer)
target_link_libraries(${PROJECT_NAME} Writer)

install(TARGETS FilesAndStrings
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
