#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glm/vec3.hpp>

/*
    Cubic Bezier Curve
*/
struct Curve{
    glm::vec3 A, B, C, D;

public: 
    /*
        Iterpolates the curve between t = 0 and t = 1
    */
    glm::vec3 operator [] (float t);
};


/*
    A Face should be 4 coplanar points.
*/
struct Face{
    glm::vec3 A, B, C, D;
};

/*
    A Sphere
*/
struct Sphere{
    glm::vec3 center;
    float radius;
};

/*
    Enum for the 6 faces of a hitbox
*/
enum Hitbox_faces{
    TOP = 0,
    BOTTOM = 1,
    RIGHT = 2,
    LEFT = 3,
    FRONT = 4,
    BACK = 5
};

/*
    Hitbox with 6 faces as relative coordinates to the orientation;
*/
struct Hitbox{
    Face faces[6];
    glm::vec3 pos;
    glm::vec3 front;
    glm::vec3 up;
};

/*
    A ray is a point and a direction;
*/
struct Ray{
    glm::vec3 pos;
    glm::vec3 dir;
};

#endif