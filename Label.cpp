#include "Label.h"
#include <iostream>
#include <string>


Label::Label(Screen *screen, std::string text) : Object(screen) {
    this->text = text;
}

Label::~Label() = default;

/* the shape of the label is the characters of the label text arranged consecutively in a horizontal line.
 * if the text is left-aligned, this line starts at position {0, 0} relative to the label's position.
 * for center and right alignment, this offset is shifted to the left accordingly. */

Shape Label::shape() {
    int xOffset = alignment == LEFT ? 0 :
                  alignment == CENTER ? (-text.size() / 2) :
                  -text.size();

    Shape shape = Shape();
    for (int i = 0; i < text.size(); i++)  {
        shape.push_back({{i + xOffset, 0}, text[i]});
    }
    return shape;
}

std::string Label::getText() {
    return text;
}

void Label::getText(std::string text) {
     this->text = text;
}
