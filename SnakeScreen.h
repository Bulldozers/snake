//
// Created by Owen Maitzen on 2017-11-19.
//

#ifndef SNAKE_SNAKESCREEN_H
#define SNAKE_SNAKESCREEN_H


#include "Screen.h"
#include "HUD.h"
#include "Label.h"
#include "Food.h"

class Snake; // forward declare

class SnakeScreen: public Screen {
private:
    int score;
    int highscore = 0;
public:
    HUD *hud;
    Label *scoreLabel;
    Label *highscoreLabel;
    Label *gameOverLabel;

    Snake *snake;
    Food *food;

    SnakeScreen(Pixel size, int fps);
    virtual ~SnakeScreen();

    void initialize();

    int getScore();
    void setScore(int score);

    void gameOver();
    void restart();
};


#endif //SNAKE_SNAKESCREEN_H
