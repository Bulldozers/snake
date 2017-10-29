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

Pixel Screen::getSize() {
    return size;
}

void Screen::display() {

    // pad with newlines

    for (int i = 0; i < 20; i++) {
        std::cout << std::endl;
    }

    // top border

    std::cout << "╔";
    for (int col = 0; col < size.x; col++) {
        std::cout << "═";
    }
    std::cout << "╗" << std::endl;

    // rows of screen
    
    for (int row = 0; row < size.y; row++) {
        std::cout << "║";
        for (int col = 0; col < size.x; col++) {
            displayPixel(Pixel(col, row));
        }
        std::cout << "║" << std::endl;
    }

    // bottom border

    std::cout << "╚";
    for (int col = 0; col < size.x; col++) {
        std::cout << "═";
    }
    std::cout << "╝" << std::endl;
}

void Screen::displayPixel(Pixel pixel) {
    
    // check for objects in the list at this position.
    // objects that are later in the list are "on top"
    
    char character = ' ';
    for (Object *object : objectsWithPosition(pixel)) {
        character = object->character;
    }
    
    std::cout << character;
}

void Screen::mainLoop() {
    mainLoop(-1);
}

void Screen::mainLoop(int numFrames) {
    while (numFrames-- != 0) {
        for (Object *object : objects) {
            object->update();
        }
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
    }
}

std::vector<Object *> Screen::getObjects() {
    return objects;
}

Object *Screen::addObject(Object *object) {
    objects.push_back(object);
    return object;
}

void Screen::removeObject(Object *object) {

    // fancy
    for (auto i = objects.begin(); i < objects.end(); i++) {
        if (*i == object) {
            objects.erase(i);
            return;
        }
    }
}

bool Screen::key(char key) {
    return keys[key];
}

std::vector<Object *> Screen::objectsWithPosition(Pixel position) {
    std::vector<Object *> objectsWithPosition;
    
    for (Object *object : objects) {
        if (object->position == position) {
            objectsWithPosition.push_back(object);
        }
    }
    
    return objectsWithPosition;
}
