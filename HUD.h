#ifndef SNAKE_HUD_H
#define SNAKE_HUD_H


#include "Object.h"

/* horizontal border at the top of the screen, separating the HUD from the game area. */

class HUD: public Object {
public:
    HUD(Screen *screen, int positionY); // adjust height of border with positionY

    Shape shape() override;
};


#endif //SNAKE_HUD_H
