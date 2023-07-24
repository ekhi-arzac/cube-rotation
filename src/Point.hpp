#ifndef CUBE_ROTATION_POINT_HPP
#define CUBE_ROTATION_POINT_HPP


class Point {
public:
    float x, y, z;
    Point();
    Point(float x, float y, float z);

    Point project(float distance);

    Point& add(float n);
    friend Point& operator+(Point& p, float n);
    Point& operator+=(float n);

    Point& multiply(float n);
    friend Point& operator*(Point& p, float n);
    Point& operator*=(float n);
};


#endif //CUBE_ROTATION_POINT_HPP
