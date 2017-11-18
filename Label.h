//
// Created by Julian Strom on 2017-11-16.
//

#ifndef SNAKE_LABEL_H
#define SNAKE_LABEL_H

#include "Alignment.h"
#include "Screen.h"
#include <string>

class Label: public Object {
private:
    std::string name;

public:
    Alignment alignment;

    Label(Screen *screen, std::string n);

    Shape shape() override;

    std::string getName();
    void setName(std::string n);

    ~Label();

};

#endif //SNAKE_LABEL_H
