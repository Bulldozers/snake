//
// Created by Owen Maitzen on 2017-11-19.
//

#include "SnakeScreen.h"
#include "Snake.h"

SnakeScreen::SnakeScreen(Pixel size, int fps): Screen(size, fps) {
    hud = new HUD(this, 1);

    scoreLabel = new Label(this, "Placeholder Text");
    scoreLabel->position = {getSize().x / 4, 0};
    scoreLabel->alignment = CENTER;

    highscoreLabel = new Label(this, "Placeholder Text 2: Electric Boogaloo");
    highscoreLabel->position = {3 * getSize().x / 4, 0};
    highscoreLabel->alignment = CENTER;

    snake = new Snake(this);
    food = new Food(this);

    initialize();
}

SnakeScreen::~SnakeScreen() = default;

void SnakeScreen::initialize() {
    setScore(0);

    snake->initialize();
    food->goToRandomPosition();
}

int SnakeScreen::getScore() {
    return score;
}

void SnakeScreen::setScore(int score) {
    this->score = score;

    if (score > highscore) {
        highscore = score;
    }

    scoreLabel->setName("SCORE: " + std::to_string(score));
    highscoreLabel->setName("HIGHSCORE: " + std::to_string(highscore));
}

void SnakeScreen::gameOver() {
    gameOverLabel = new Label(this, "GAME OVER - PRESS R");
    gameOverLabel->position = getSize() / 2;
    gameOverLabel->alignment = CENTER;
}

void SnakeScreen::restart() {
    delete gameOverLabel;

    initialize();
}
