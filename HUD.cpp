//
// Created by Owen on 2017-11-18.
//

#include "HUD.h"
#include "Screen.h"

HUD::HUD(Screen *screen, int positionY): Object(screen) {
    position = {0, positionY};
    character = '=';
}

// horizontal border the width of the screen

Shape HUD::shape() {
    Shape shape = Shape();
    for (int x = 0; x < getScreen()->getSize().x; x++) {
        shape.push_back({{x, 0}, character});
    }
    return shape;
}
