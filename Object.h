//
// Created by Owen Maitzen on 2017-10-28.
//

#ifndef SNAKE_OBJECT_H
#define SNAKE_OBJECT_H


#include <utility>
#include <vector>
#include "Pixel.h"

/* a list of the positions of the pixels that the object occupies, relative to the object's position, and the characters
 * displayed at each */
typedef std::vector<std::pair<Pixel, char>> Shape;

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

    // called every frame
    virtual void update() = 0;

    /* the positions of the pixels that the object occupies, relative to the object's position, and the characters
     * displayed at each. by default, this returns the single pair {Pixel::zero, character} */
    virtual Shape shape();

    bool key(char key);

};


#endif //SNAKE_OBJECT_H
