#include <geometry.h>


static glm::vec3 linear_interpolate(glm::vec3 A, glm::vec3 B, float t){
    return A + (B - A) * t;
}

glm::vec3 Curve::operator[] (float t){
    glm::vec3 AB, BC, CD;
    glm::vec3 ABC, BCD;
    AB = linear_interpolate(A, B, t);
    BC = linear_interpolate(B, C, t);
    CD = linear_interpolate(C, D, t);

    ABC = linear_interpolate(AB, BC, t);
    BCD = linear_interpolate(BC, CD, t);

    return linear_interpolate(ABC, BCD, t);
}