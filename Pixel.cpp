#include "Pixel.h"

Pixel::Pixel(): x(0), y(0) {}
Pixel::Pixel(int xy): x(xy), y(xy) {}
Pixel::Pixel(int x, int y): x(x), y(y) {}
Pixel::Pixel(const Pixel &pixel) = default;

Pixel &Pixel::operator=(const Pixel &rhs) = default;

Pixel &Pixel::operator+=(const Pixel &rhs) { x += rhs.x; y += rhs.y; return *this; }
Pixel &Pixel::operator-=(const Pixel &rhs) { x -= rhs.x; y -= rhs.y; return *this; }
Pixel &Pixel::operator*=(const Pixel &rhs) { x *= rhs.x; y *= rhs.y; return *this; }
Pixel &Pixel::operator/=(const Pixel &rhs) { x /= rhs.x; y /= rhs.y; return *this; }

Pixel &Pixel::operator*=(const int &scalar) { x *= scalar; y *= scalar; return *this; }
Pixel &Pixel::operator/=(const int &scalar) { x /= scalar; y /= scalar; return *this; }

Pixel Pixel::zero = Pixel(0);
Pixel Pixel::one = Pixel(1);

bool operator==(const Pixel &lhs, const Pixel &rhs) { return (lhs.x == rhs.x && lhs.y == rhs.y); }
bool operator!=(const Pixel &lhs, const Pixel &rhs) { return !(lhs == rhs); }

bool operator>(const Pixel &lhs, const Pixel &rhs) { return (lhs.x > rhs.x && lhs.y > rhs.y); }
bool operator<(const Pixel &lhs, const Pixel &rhs) { return (lhs.x < rhs.x && lhs.y < rhs.y); }
bool operator>=(const Pixel &lhs, const Pixel &rhs) { return (lhs.x >= rhs.x && lhs.y >= rhs.y); }
bool operator<=(const Pixel &lhs, const Pixel &rhs) { return (lhs.x <= rhs.x && lhs.y <= rhs.y); }

Pixel operator+(const Pixel &lhs, const Pixel &rhs) { return Pixel(lhs) += rhs; }
Pixel operator-(const Pixel &lhs, const Pixel &rhs) { return Pixel(lhs) -= rhs; }
Pixel operator*(const Pixel &lhs, const Pixel &rhs) { return Pixel(lhs) *= rhs; }
Pixel operator/(const Pixel &lhs, const Pixel &rhs) { return Pixel(lhs) /= rhs; }

Pixel operator*(const Pixel &lhs, const int &scalar) { return Pixel(lhs) *= scalar; }
Pixel operator*(const int &scalar, const Pixel &rhs) { return Pixel(rhs) *= scalar; }
Pixel operator/(const Pixel &lhs, const int &scalar) { return Pixel(lhs) /= scalar; }
Pixel operator/(const int &scalar, const Pixel &rhs) { return Pixel(rhs) /= scalar; }