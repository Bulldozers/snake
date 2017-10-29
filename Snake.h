//
// Created by Owen Maitzen on 2017-10-28.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H


#include "Screen.h"

class Snake : public Object {
private:
    Pixel velocity;

public:
    explicit Snake(Screen *screen);
    ~Snake();

    void update() override;

    void die();
};


#endif // SNAKE_SNAKE_H