//
// Created by Owen Maitzen on 2017-10-28.
//

#include <cstdlib>
#include <w32api/rpc.h>
#include "Snake.h"
#include "Food.h"
#include "SnakeScreen.h"

Snake::Snake(Screen *screen) : Object(screen) {
    character = 'S';
}

Snake::~Snake() = default;

void Snake::initialize() {
    isAlive = true;

    position = getScreen()->getSize() / 2;
    velocity = Pixel(1, 0);
    trailSize = 1;
    prevPositions.clear();
}

void Snake::update() {
    prevPositions.insert(prevPositions.begin(), position);
    while (prevPositions.size() > trailSize) {
        prevPositions.pop_back();
    }

    if (isAlive) {
        if (key(VK_UP)) {
            velocity = {0, -1};
        } else if (key(VK_DOWN)) {
            velocity = {0, 1};
        } else if (key(VK_LEFT)) {
            velocity = {-1, 0};
        } else if (key(VK_RIGHT)) {
            velocity = {1, 0};
        }

        position += velocity;

        // check for collisions with food - look at all objects at the snake's head
        for (Object *object : getScreen()->objectsAtPixel(position)) {

            // check if object is food
            if (Food *food = dynamic_cast<Food *>(object)) {
                grow();
                food->goToRandomPosition();
            }

            // if object is the HUD, then we have a collision
            if (dynamic_cast<HUD *>(object)) {
                die();
            }
        }

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

    } else {
        if (key('R')) {
            restart();
        }
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

    if (auto snakeScreen = dynamic_cast<SnakeScreen *>(getScreen())) {
        snakeScreen->setScore(snakeScreen->getScore() + 1);
    }
}

void Snake::die() {
    isAlive = false;

    if (auto snakeScreen = dynamic_cast<SnakeScreen *>(getScreen())) {
        snakeScreen->gameOver();
    }
}

void Snake::restart() {
    initialize();

    if (auto snakeScreen = dynamic_cast<SnakeScreen *>(getScreen())) {
        snakeScreen->restart();
    }
}
