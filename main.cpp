#include <iostream>
#include "SnakeScreen.h"

/* Create a screen with a snake in the center, moving to the right.
 * When the snake hits the edge of the screen, it destroys itself and the mainloop continues for a few more frames.
 *
 * I'm using JetBrains' CLion IDE to build and run this project. It does a whole lot of cmake sorcery behind the scenes,
 * but if you download the IDE and create a project from these source files, I think it should work. */

int main() {
    auto screen = new SnakeScreen(Pixel(78, 21), 15);
    screen->mainLoop();
    return 0;
}