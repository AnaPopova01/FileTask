cmake_minimum_required(VERSION 3.5)

project (PackData)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${PROJECT_NAME} SHARED
    include/ipacker.h
    include/packerfactory.h

    src/dataPack.cpp
    src/dataPack.h
    src/packerfactory.cpp


)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include("unittest.cmake")
