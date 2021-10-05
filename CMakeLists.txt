cmake_minimum_required(VERSION 3.16)
project(yahtzee VERSION 1.0.0)

add_subdirectory(inc)
add_subdirectory(src)
include_directories(inc)

add_executable(${PROJECT_NAME} src/main.cpp)

add_library(
    yahtz STATIC
    src/gameEngine.cpp
    src/dice.cpp
    src/diceContainer.cpp
    )
    
target_link_libraries(${PROJECT_NAME} yahtz sfml-system sfml-window sfml-graphics sfml-network sfml-audio)