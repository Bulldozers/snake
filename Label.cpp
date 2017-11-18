//
// Created by Julian Strom on 2017-11-16.
//

#include "Label.h"
#include <iostream>
#include <string>


Label::Label(Screen *screen, std::string n) : Object(screen) {
    this->name = n;
}

Shape Label::shape() {
    Shape shape = Shape();
    for (int i = 0; i < name.size(); i++)  {
        shape.push_back({{i,0}, name[i]});
    }
    return shape;
}

std::string Label::getName() {
    return name;
}

void Label::setName(std::string n) {
     this->name = n;
}
