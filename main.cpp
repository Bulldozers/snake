#include "SnakeScreen.h"

/* create an instance of SnakeScreen and run it on an endless loop. */

int main() {
    SnakeScreen(Pixel(78, 21), 30).mainLoop();
    return 0;
}