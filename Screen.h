//
// Created by Owen Maitzen on 2017-10-28.
//

#ifndef SNAKE_SCREEN_H
#define SNAKE_SCREEN_H


#include "Pixel.h"

class Screen {
private:
    Pixel size;
    int fps;

    void display();
    void displayRow(int row);
    void displayPixel(Pixel pixel);
public:
    Screen(Pixel size, int fps);

    // starting the main loop - only goes for a limited number of frames
    void mainLoop(int numFrames);

    // call the above function with argument -1, which essentially makes it go infinitely (about 25 years actually)
    void mainLoop();
};


#endif //SNAKE_SCREEN_H
