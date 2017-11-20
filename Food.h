#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H


#include "Object.h"

/* food items that the snake eats. */

class Food: public Object {
public:
    Food(Screen *screen);

    void goToRandomPosition();
};


#endif //SNAKE_FOOD_H
