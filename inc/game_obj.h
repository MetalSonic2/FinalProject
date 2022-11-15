#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include <vector>
#include <geometry.h>

class GameObject{
    Hitbox h;
    glm::vec3 pos;
    glm::vec3 front;
    glm::vec3 up;

    glm::vec3 velocity;

public:
    void teleport(glm::vec3 pos, glm::vec3 front, glm::vec3 up);
    void move(float t);
};

#endif