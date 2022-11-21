#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include <vector>
#include <geometry.h>

struct GL_Obj{
    GLuint VAO;
    GLuint VBO[7];
    GLuint EBO[7];
    // [Vertex, Normals, TexCoord, instance m1, instance m2, instance m3, instance m4] 
};

class GameObject{
    Hitbox h;
    glm::vec3 pos;
    glm::vec3 front;
    glm::vec3 up;
    GL_Obj gl_obj;

    glm::vec3 velocity;

public:
    void teleport(glm::vec3 pos, glm::vec3 front, glm::vec3 up);
    void move(float t);
};

#endif