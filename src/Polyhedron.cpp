#include "Polyhedron.hpp"
#include "math.h"

// Rotates each y and z coordinate with rotation matrix
void Polyhedron::rotateX(float alpha)
{
    for (Point& p : vertices)
    {
        float y = p.y;
        p.y = cos(alpha) * p.y - sin(alpha) * p.z;
        p.z = sin(alpha) * y + cos(alpha) * p.z;
    }
}
// Rotates each x and z coordinate with rotation matrix
void Polyhedron::rotateY(float beta)
{
    for (Point& p : vertices)
    {
        float x = p.x;
        p.x = cos(beta) * p.x + sin(beta) * p.z;
        p.z = -sin(beta) * x + cos(beta) * p.z;
    }
}
// Rotates each x and y coordinate with rotation matrix
void Polyhedron::rotateZ(float gamma)
{
    for (Point& p : vertices)
    {
        float x = p.x;
        p.x = cos(gamma) * p.x - sin(gamma) * p.y;
        p.y = sin(gamma) * x + cos(gamma) * p.y;
    }
}
// Modify distance between projection to change size
void Polyhedron::setSize(float size)
{
    for (Point& p : vertices)
    {
        p *= size;
    }
}
// Push vertex to projection vector
void Polyhedron::pushVtx(float x, float y, float z) {
    vertices.emplace_back(x, y, z);
}
// Change polygon position
void Polyhedron::setOffset(float offset) {
    for (Point& p : vertices) {
        p += offset;
    }
}

