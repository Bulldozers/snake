//
// Created by Owen Maitzen on 2017-10-28.
//

#ifndef SNAKE_OBJECT_H
#define SNAKE_OBJECT_H


#include "Pixel.h"

// forward-declare this so we can store a pointer to an instance in the object
class Screen;

class Object {
private:
    Screen *screen;

public:
    Pixel position;
    char character;

    explicit Object(Screen *screen);
    ~Object();

    Screen *getScreen();
    
    virtual void update() = 0;
    
    bool key(char key);

};


#endif //SNAKE_OBJECT_H
