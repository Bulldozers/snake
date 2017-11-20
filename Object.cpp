#include "Object.h"
#include "Screen.h"

Object::Object(Screen *screen) {
    this->screen = screen;

    // add reference to this object in screen
    screen->addObject(this);
}

Object::~Object() {
    // remove reference
    screen->removeObject(this);
}

Screen *Object::getScreen() {
    return screen;
}

void Object::update() {}

Shape Object::shape() {
    return {{Pixel::zero, character}};
}

bool Object::key(char key) {
    return screen->key(key);
}
