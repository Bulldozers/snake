//
// Created by Owen Maitzen on 2017-10-28.
//

#include <chrono>
#include <iostream>
#include <thread>
#include "Screen.h"

Screen::Screen(Pixel size, int fps) {
    this->size = size;
    this->fps = fps;
}

void Screen::display() {

    // pad with newlines

    for (int i = 0; i < 20; i++) {
        std::cout << '\n';
    }

    // top border

    std::cout << "╔";
    for (int col = 0; col < size.x; col++) {
        std::cout << "═";
    }
    std::cout << "╗" << std::endl;

    for (int row = 0; row < size.y; row++) {
        displayRow(row);
    }

    // bottom border

    std::cout << "╚";
    for (int col = 0; col < size.x; col++) {
        std::cout << "═";
    }
    std::cout << "╝" << std::endl;
}

void Screen::displayRow(int row) {
    std::cout << "║";
    for (int col = 0; col < size.x; col++) {
        displayPixel(Pixel(col, row));
    }
    std::cout << "║" << std::endl;
}

void Screen::displayPixel(Pixel pixel) {
    std::cout << ' '; // placeholder
}

void Screen::mainLoop() {
    mainLoop(-1);
}

void Screen::mainLoop(int numFrames) {
    while (numFrames-- != 0) {
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
    }
}
