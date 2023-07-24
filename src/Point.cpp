#include "Point.hpp"

Point::Point() {}

Point::Point(float x, float y, float z)
{
    this->x = x;
    this-> y = y;
    this-> z = z;
}


Point Point::project(float distance)
{
    Point res;
    res.x = this->x * (distance / this->z);
    res.y = this->y * (distance / this->z);
    return res;
}

Point& Point::multiply(float n) {
    this->x *= n;
    this->y *= n;
    this->z *= n;
    return *this;
}

Point& operator*(Point &p, float n) {
    return p.multiply(n);
}

Point& Point::operator*=(float n) {
    return this->multiply(n);
}

Point &Point::add(float n) {
    this->x += n;
    this->y += n;
    this->z += n;
    return *this;
}

Point &operator+(Point &p, float n) {
    return p.add(n);
}

Point &Point::operator+=(float n) {
    return this->add(n);
}


