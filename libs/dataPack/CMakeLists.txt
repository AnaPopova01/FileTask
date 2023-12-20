cmake_minimum_required(VERSION 3.5)

project (dataPack)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(${PROJECT_NAME} SHARED
    include/dataPack/ipacker.h
    include/dataPack/packerfactory.h
    include/dataPack/basepack.h
    include/dataPack/standartprot.h
    include/dataPack/magicprot.h

    source/magicprot.cpp
    source/packerfactory.cpp
    source/standartprot.cpp
    source/basepack.cpp


)

target_link_libraries(${PROJECT_NAME} PUBLIC threadPool )

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME})

include("unittest.cmake")
