//
// Created by Owen on 2017-11-18.
//

#ifndef SNAKE_HUD_H
#define SNAKE_HUD_H


#include "Object.h"

class HUD: public Object {
public:
    HUD(Screen *screen, int positionY);

    Shape shape() override;

};


#endif //SNAKE_HUD_H
