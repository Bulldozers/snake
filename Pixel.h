//
// Created by Owen Maitzen on 2017-10-28.
//

#ifndef SNAKE_PIXEL_H
#define SNAKE_PIXEL_H

// 2D vector with integer components. none of this has been tested but it's pretty simple

struct Pixel {
    int x, y;

    Pixel();
    explicit Pixel(int xy); // initialize with identical x and y values
    Pixel(int x, int y);
    Pixel(const Pixel &pixel);

    Pixel &operator=(const Pixel &rhs);

    Pixel &operator+=(const Pixel &rhs);
    Pixel &operator-=(const Pixel &rhs);
    Pixel &operator*=(const Pixel &rhs);
    Pixel &operator/=(const Pixel &rhs);

    Pixel &operator*=(const int &scalar);
    Pixel &operator/=(const int &scalar);
};

bool operator==(const Pixel &lhs, const Pixel &rhs);
bool operator!=(const Pixel &lhs, const Pixel &rhs);

// item-wise operators
Pixel operator+(const Pixel &lhs, const Pixel &rhs);
Pixel operator-(const Pixel &lhs, const Pixel &rhs);
Pixel operator*(const Pixel &lhs, const Pixel &rhs);
Pixel operator/(const Pixel &lhs, const Pixel &rhs);

Pixel operator*(const Pixel &lhs, const int &scalar);
Pixel operator*(const int &scalar, const Pixel &rhs);
Pixel operator/(const Pixel &lhs, const int &scalar);
Pixel operator/(const int &scalar, const Pixel &rhs);

Pixel operator-(const Pixel &pixel);

#endif //SNAKE_PIXEL_H
