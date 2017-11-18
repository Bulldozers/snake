//
// Created by Owen Maitzen on 2017-11-18.
//

#include <cstdlib>
#include "Food.h"
#include "Screen.h"

Food::Food(Screen *screen): Object(screen) {
    character = 'O';
    goToRandomPosition();
}

void Food::goToRandomPosition() {

    // figure out positions of all empty pixels

    std::vector<Pixel> possiblePositions;
    for (int x = 0; x < getScreen()->getSize().x; x++) {
        for (int y = 0; y < getScreen()->getSize().y; y++) {
            Pixel pixel = Pixel(x,y);
            if (getScreen()->objectsAtPixel(pixel).empty()) {
                possiblePositions.push_back(pixel);
            }
        }
    }

    // pick a random position from that list
    position = possiblePositions[rand() % possiblePositions.size()];
}