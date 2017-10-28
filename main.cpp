#include "Screen.h"

// g++ -std=c++11 -o snake main.cpp Screen.cpp Pixel.cpp

int main() {
    Screen testScreen = Screen(Pixel(60, 20), 5);
    testScreen.mainLoop(5);
    return 0;
}