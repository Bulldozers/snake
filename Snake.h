//
// Created by Owen Maitzen on 2017-10-28.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H


#include "Screen.h"

class Snake : public Object {
private:
    Pixel velocity;
    int trailSize; // size of prevPositions
    std::vector<Pixel> prevPositions; // prevPositions[n] = position of snake's head (n+1) frames ago
    bool isAlive;

public:
    explicit Snake(Screen *screen);

    ~Snake();

    void initialize();

    void update() override;

    // position of head plus prevPositions
    Shape shape() override;

    void grow();
    void die();
    void restart();
};

#endif // SNAKE_SNAKE_H
