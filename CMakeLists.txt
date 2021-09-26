cmake_minimum_required(VERSION 3.16)
project(yahtzee VERSION 1.0.0)
add_subdirectory(inc)
add_subdirectory(src)
include_directories(inc)

add_executable(${PROJECT_NAME} src/main.cpp)

#find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

add_library(
    yahtz
    src/template.cpp
    )
    
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio yahtz)