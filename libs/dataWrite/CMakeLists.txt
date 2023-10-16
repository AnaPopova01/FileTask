cmake_minimum_required(VERSION 3.5)

project (WriteData)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${PROJECT_NAME} SHARED dataWrite.cpp dataWrite.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

