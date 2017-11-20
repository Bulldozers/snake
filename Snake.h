#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H


#include "Screen.h"

class Snake : public Object {
private:
    Pixel velocity; // added to snake's position every frame
    int trailSize; // size of prevPositions
    std::vector<Pixel> prevPositions; // prevPositions[n] = position of snake's head (n+1) frames ago
    bool isAlive;

public:
    explicit Snake(Screen *screen);

    virtual ~Snake();

    void initialize();

    void update() override;

    // position of head plus prevPositions
    Shape shape() override;

    // self-explanatory
    void grow();
    void die();
    void restart();
};

#endif // SNAKE_SNAKE_H
