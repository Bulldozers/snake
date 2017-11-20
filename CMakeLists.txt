cmake_minimum_required(VERSION 3.8)
project(Snake)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Pixel.cpp Pixel.h Screen.cpp Screen.h Object.cpp Object.h Snake.cpp Snake.h Label.cpp Label.h Food.cpp Food.h HUD.cpp HUD.h SnakeScreen.cpp SnakeScreen.h)
add_executable(Snake ${SOURCE_FILES})