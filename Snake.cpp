//
// Created by Owen Maitzen on 2017-10-28.
//

#include <cstdlib>
#include "Snake.h"

Snake::Snake(Screen *screen) : Object(screen) {
    velocity = Pixel(1, 0);
    character = 'S';
}

Snake::~Snake() = default;

void Snake::update() {
    if (key('w')) {
        velocity = {0, -1};
    } else if (key('s')) {
        velocity = {0, 1};
    } else if (key('a')) {
        velocity = {-1, 0};
    } else if (key('d')) {
        velocity = {1, 0};
    }

    position += velocity;

    // neither coordinate (x or y) can be below 0 or above screen width/height
    if (!(position >= Pixel::zero && position < getScreen()->getSize())) {
        die();
    }
}

void Snake::die() {
    delete this; // rip
}