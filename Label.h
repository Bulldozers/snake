//
// Created by Julian Strom on 2017-11-16.
//

#ifndef SNAKE_LABEL_H
#define SNAKE_LABEL_H

#include "Screen.h"
#include <string>

class Label: public Object {
private:
    std::string name;

public:
    Label(Screen *screen, std::string n);

    Shape shape();

    std::string getName();
    void setName(std::string n);

    ~Label();

};

#endif //SNAKE_LABEL_H
