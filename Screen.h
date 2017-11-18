//
// Created by Owen Maitzen on 2017-10-28.
//

#ifndef SNAKE_SCREEN_H
#define SNAKE_SCREEN_H


#include <vector>
#include "Object.h"

class Screen {
private:
    Pixel size;
    int fps;

    // state of all keys - keys['A'] is true if A was pressed in the last frame, false otherwise
    bool keys[256];

    std::vector<Object *> objects;

    void display();
    void displayPixel(Pixel pixel);
public:
    Screen(Pixel size, int fps);
    
    Pixel getSize();

    // starting the main loop - only goes for a limited number of frames
    void mainLoop(int numFrames);

    void tick();

    // call the above function with argument -1, which essentially makes it go infinitely (about 25 years actually)
    void mainLoop();

    // interface to the objects list - no mutating except with explicit functions
    std::vector<Object *> getObjects();
    Object *addObject(Object *object);
    void removeObject(Object *object);

    // whether key was pressed, queries the private array
    bool key(char key);

    // check each object for collision with any part of shape
    std::vector<Object *> objectsAtPixel(Pixel pixel);
};


#endif //SNAKE_SCREEN_H
