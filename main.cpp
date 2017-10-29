#include "Screen.h"
#include "Snake.h"

/* Create a screen with a snake in the center, moving to the right.
 * When the snake hits the edge of the screen, it destroys itself and the mainloop continues for a few more frames.
 *
 * I'm using JetBrains' CLion IDE to build and run this project. It does a whole lot of cmake sorcery behind the scenes,
 * but if you download the IDE and create a project from these source files, I think it should work. */

int main() {
    auto *screen = new Screen(Pixel(60, 20), 5);
    auto *snake = new Snake(screen);
    snake->position = screen->getSize() / 2;

    for (int i = 0; i < 5; i++) {
        snake->grow();
    }

    screen->mainLoop(50);
    return 0;
}