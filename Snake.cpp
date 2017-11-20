#include <cstdlib>
#include <iostream>
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
        bool AI_ON = true;
        if (!AI_ON) {
            if (key(0x26)) { // UP
                velocity = {0, -1};
            } else if (key(0x28)) { // DOWN
                velocity = {0, 1};
            } else if (key(0x25)) { // LEFT
                velocity = {-1, 0};
            } else if (key(0x27)) { // RIGHT
                velocity = {1, 0};
            }
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

        if (AI_ON) {
            for (Object *object : getScreen()->getObjects()) {
                if (Food *food = dynamic_cast<Food *>(object)) {

                    bool shouldTurnLeft = false, shouldTurnRight = false;

                    Pixel relativeFoodPosition;
                    if (velocity.x > 0) {
                        relativeFoodPosition = food->position - position;
                    } else if (velocity.x < 0) {
                        relativeFoodPosition = position - food->position;
                    } else if (velocity.y > 0) {
                        relativeFoodPosition = {food->position.y - position.y, position.x - food->position.x};
                    } else if (velocity.y < 0) {
                        relativeFoodPosition = {position.y - food->position.y, food->position.x - position.x};
                    }

                    if (relativeFoodPosition.x <= 0) {
                        if (relativeFoodPosition.y < 0) {
                            shouldTurnLeft = true;
                        } else {
                            shouldTurnRight = true;
                        }
                    }

                    if (shouldTurnLeft) {
                        if (velocity.x > 0) { velocity = {0, -1}; }
                        else if (velocity.x < 0) { velocity = {0, 1}; }
                        else if (velocity.y > 0) { velocity = {1, 0}; }
                        else if (velocity.y < 0) { velocity = {-1, 0}; }
                    } else if (shouldTurnRight) {
                        if (velocity.x > 0) { velocity = {0, 1}; }
                        else if (velocity.x < 0) { velocity = {0, -1}; }
                        else if (velocity.y > 0) { velocity = {-1, 0}; }
                        else if (velocity.y < 0) { velocity = {1, 0}; }
                    }
                }
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

// snake functions with callbacks to the screen

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
