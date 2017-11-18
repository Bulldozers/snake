//
// Created by Owen Maitzen on 2017-11-18.
//

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H


#include "Object.h"

class Food: public Object {
public:
    Food(Screen *screen);

    void goToRandomPosition();
};


#endif //SNAKE_FOOD_H
