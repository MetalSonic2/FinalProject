#include <game_obj.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

void GameObject::teleport(glm::vec3 pos, glm::vec3 front, glm::vec3 up){
    this->pos = pos;
    this->front = front;
    this->up = up;
}
void GameObject::move(float t){
    pos += (velocity * t);
}
void GameObject::setVelocity(glm::vec3 vel){
    velocity = vel;
}
glm::vec3 GameObject::getVelocity(){
    return velocity;
}
void GameObject::draw(ShaderProgram shader){
    glm::mat4 model_matrix(1);

    shader.SetUniform("modelMatrix", glm::value_ptr(model_matrix), 4, GL_FALSE, 1);
    glBindVertexArray(gl_obj.VAO);
    // printf("globj: %d-%d\n", gl_obj.VAO, gl_obj.vertex_count);
    glDrawArrays(GL_TRIANGLES, 0, gl_obj.vertex_count);
    // glDrawArrays(GL_TRIANGLES, 0, gl_obj.vertex_count);
}
GameObject::GameObject(GL_Obj gl_obj){
    this->gl_obj = gl_obj;
    this->pos = glm::vec3(0,0,0);
    this->front = glm::vec3(1,0,0);
    this->up = glm::vec3(0,1,0);
}
GameObject::GameObject(){}