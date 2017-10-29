//
// Created by Owen Maitzen on 2017-10-28.
//

#include <cstdlib>
#include "Snake.h"

Snake::Snake(Screen *screen) : Object(screen) {
    character = 'S';

    velocity = Pixel(1, 0);
    trailSize = 0;
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

    prevPositions.insert(prevPositions.begin(), position);
    while (prevPositions.size() > trailSize) {
        prevPositions.pop_back();
    }

    position += velocity;

    // snake's head can't collide with body
    for (const Pixel &prevPosition : prevPositions) {
        if (position == prevPosition) {
            die();
        }
    }

    // neither coordinate (x or y) of snake's head can be below 0 or above screen width/height
    if (!(position >= Pixel::zero && position < getScreen()->getSize())) {
        die();
    }
}

Shape Snake::shape() {
    Shape shape = Object::shape();
    for (const Pixel &prevPosition : prevPositions) {
        shape.push_back({prevPosition - position, '*'});
    }
    return shape;
}

void Snake::grow() {
    trailSize++;
}

void Snake::die() {
    delete this; // rip
}