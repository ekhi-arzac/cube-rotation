#ifndef CUBE_ROTATION_POLYHEDRON_HPP
#define CUBE_ROTATION_POLYHEDRON_HPP

#include <vector>
#include "Point.hpp"
#include <SDL.h>

class Polyhedron {
public:
    float distance;
    std::vector<Point> vertices;

    void pushVtx(float x, float y, float z);
    void setSize(float size);
    void setOffset (float offset);
    void rotateX(float alpha);
    void rotateY(float beta);
    void rotateZ(float gamma);

};


#endif //CUBE_ROTATION_POLYHEDRON_HPP
