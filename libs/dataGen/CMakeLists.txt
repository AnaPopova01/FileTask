cmake_minimum_required(VERSION 3.5)

project (GenData)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${PROJECT_NAME} SHARED dataGen.cpp dataGen.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include("unittest.cmake")
