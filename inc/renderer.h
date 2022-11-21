#ifndef RENDERER_H
#define RENDERER_H
#include "window.h"
#include <GL/glut.h>
#include <game_obj.h>
#include <glm/vec2.hpp>
#include <vector>
#include <map>

class Renderer : public Window{
    std::map<const char*, GL_Obj> GL_Objs;
    std::vector<GameObject> Game_objs;
public:
    int init_renderer(const char **objNames, const char **objFiles, int objc);
    GL_Obj get_gl_obj(const char *name);
    int GL_load_obj(const char *objName, const char *objFile);
    int GL_load_obj(const char *objName, std::vector<glm::vec3> verts, std::vector<glm::vec3> norms, std::vector<glm::vec2> textures,
                    std::vector<int> index_vertices, std::vector<int> index_normals, std::vector<int> index_texCoords);
    };

#endif