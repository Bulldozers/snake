#include <cstdlib>
#include "Food.h"
#include "Screen.h"

Food::Food(Screen *screen): Object(screen) {
    character = 'O';
}

void Food::goToRandomPosition() {

    // figure out positions of all empty pixels

    std::vector<Pixel> possiblePositions;
    for (int x = 1; x < getScreen()->getSize().x - 1; x++) { // sneaky don't go on the edge or else AI will fail
        for (int y = 3; y < getScreen()->getSize().y - 1; y++) {
            Pixel pixel = Pixel(x,y);
            if (getScreen()->objectsAtPixel(pixel).empty()) {
                possiblePositions.push_back(pixel);
            }
        }
    }

    // pick a random position from that list
    position = possiblePositions[rand() % possiblePositions.size()];
}