#ifndef SNAKE_LABEL_H
#define SNAKE_LABEL_H

#include "Screen.h"
#include <string>

// horizontal alignment of text in a label
enum Alignment { LEFT, CENTER, RIGHT };

class Label: public Object {
private:
    std::string text; // text that the label displays

public:
    Alignment alignment;

    Label(Screen *screen, std::string text);
    virtual ~Label();

    Shape shape() override;

    std::string getText();
    void getText(std::string text);

};

#endif //SNAKE_LABEL_H
