cmake_minimum_required(VERSION 3.5)

project(FilesAndStrings)

set(CMAKE_CXX_FLAGS_DEBUG "-ggdb -g -O0")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(UNITTEST ON)

if(UNITTEST)
        add_subdirectory(googletests/)
endif()

if(UNITTEST)
        message(" output lib dir " ${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG})
        enable_testing()
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FilesAndStrings main.cpp)

add_subdirectory(libs/dataGen)
add_subdirectory(libs/dataPack)
add_subdirectory(libs/dataRead)

target_link_libraries(${PROJECT_NAME} dataGen)

target_link_libraries(${PROJECT_NAME} dataPack)

target_link_libraries(${PROJECT_NAME} dataRead)

install(TARGETS FilesAndStrings
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
