//
// Created by Owen Maitzen on 2017-10-28.
//

#include <chrono>
#include <iostream>
#include <thread>
#include <Windows.h>
#include "Screen.h"

Screen::Screen(Pixel size, int fps) {
    this->size = size;
    this->fps = fps;

    for (int c = 0; c < 256; c++) {
        toggleState[c] = (GetKeyState(c) & 0x0001) != 0;
    }
}

Screen::~Screen() = default;

Pixel Screen::getSize() {
    return size;
}

void Screen::display() {
    std::string output = "";

    // pad with newlines

    for (int i = 0; i < 20; i++) {
        output += '\n';
    }

    // top border

    output += "╔";
    for (int col = 0; col < size.x; col++) {
        output += "═";
    }
    output += "╗\n";

    // rows of screen

    for (int row = 0; row < size.y; row++) {
        output += "║";
        for (int col = 0; col < size.x; col++) {
            output += charAtPixel(Pixel(col, row));
        }
        output += "║\n";
    }

    // bottom border

    output += "╚";
    for (int col = 0; col < size.x; col++) {
        output += "═";
    }
    output += "╝\n";

    std::cout << output;
}

char Screen::charAtPixel(Pixel pixel) {

    // check for objects in the list at this position.
    // objects that are later in the list are "on top"
    
    char character = ' ';
    for (Object *object : objectsAtPixel(pixel)) {
        for (auto pair : object->shape()) {
            if (object->position + pair.first == pixel) {
                character = pair.second;
            }
        }
    }
    
    return character;
}

void Screen::mainLoop() {
    mainLoop(-1);
}

void Screen::tick() {
    for (int c = 0; c < 256; c++) {
        keys[c] = false;

        // if toggle state has changed, then key was pressed since the last frame

        bool newToggleState = (GetKeyState(c) & 0x0001) != 0;
        if (newToggleState != toggleState[c]) {
            toggleState[c] = newToggleState;
            keys[c] = true;
        }
    }

    for (int i = 0; i < objects.size(); i++) {
        objects[i]->update();
    }
    display();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
}

void Screen::mainLoop(int numFrames) {
    while (numFrames-- != 0) {
        tick();
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

std::vector<Object *> Screen::objectsAtPixel(Pixel pixel) {
    std::vector<Object *> objectsAtPixel;
    
    for (Object *object : objects) {
        for (auto pair : object->shape()) {
            if (object->position + pair.first == pixel) {
                objectsAtPixel.push_back(object);
                break;
            }
        }
    }
    
    return objectsAtPixel;
}
