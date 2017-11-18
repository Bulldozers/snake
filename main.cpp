#include "Screen.h"
#include "Snake.h"
#include "Label.h"
#include "Food.h"
#include "HUD.h"

/* Create a screen with a snake in the center, moving to the right.
 * When the snake hits the edge of the screen, it destroys itself and the mainloop continues for a few more frames.
 *
 * I'm using JetBrains' CLion IDE to build and run this project. It does a whole lot of cmake sorcery behind the scenes,
 * but if you download the IDE and create a project from these source files, I think it should work. */

int main() {
    auto screen = new Screen(Pixel(78, 22), 10);

    auto hud = new HUD(screen, 1);
    auto label = new Label(screen, "Score: 0");
    label->position = {screen->getSize().x / 2, 0};
    label->alignment = CENTER;

    auto snake = new Snake(screen);
    snake->position = screen->getSize() / 2;
    snake->grow();

    auto food = new Food(screen);

    screen->mainLoop(50);
    return 0;
}