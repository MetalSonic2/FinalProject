#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <renderer.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Renderer::init_renderer(const char **objNames, const char **objFiles, int objc){
    for(int i = 0; i < objc; i++){
        int ret = GL_load_obj(objNames[i], objFiles[i]);
        if(ret) {
            printf("Failed to load %s\n", objNames[i]);
            return ret;
        }
    }
    return 0;
}


GL_Obj Renderer::get_gl_obj(const char *name){
    return GL_Objs[name];
}
static char* next_float();
int Renderer::GL_load_obj(const char *objName, const char *objFile){
    // std::ifstre  am ifs(objFile, std::ios_base::in);
    FILE *file = fopen(objFile, "r");
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> texCoords;
    std::vector<int> index_vertices;
    std::vector<int> index_normals;
    std::vector<int> index_texCoords;
    
    vertices.push_back(glm::vec3(0, 0, 0));
    normals.push_back(glm::vec3(0, 0, 0));
    texCoords.push_back(glm::vec2(0, 0));

    char buff[256] = {0};  
    while(!feof(file)){
        int line_len = 0;
        memset(&buff[0], 0, 256);
        fscanf(file, "%[^\n]\n", &buff[0]);
        printf("LINE: %s\n", &buff[0]);
        switch (buff[0]) {
            case 'v' : {
                switch (buff[1]) {
                    case 't' : {
                        float x, y;
                        sscanf(&buff[0], "vt %f %f", &x, &y);
                        // printf("vt %f %f\n", x, y);
                        texCoords.push_back(glm::vec2(x,y));
                    } break; // texcoords
                    case 'n' : {
                        float x, y, z;
                        sscanf(&buff[0], "vn %f %f %f", &x, &y, &z);
                        //printf("vn %f %f %f\n", x, y, z);
                        normals.push_back(glm::vec3(x,y,z));
                    } break; // normals
                    default : { // points
                        float x, y, z;
                        sscanf(&buff[0], "v %f %f %f\n", &x, &y, &z);
                        //printf("v %f %f %f\n", x, y, z);
                        vertices.push_back(glm::vec3(x,y,z));
                    } break;
                }
            } break;
            case 'f' : {
                int v[4], n[4], t[4];
                int ret = 0;
                memset(&v[0], -1, sizeof(v));
                memset(&n[0], -1, sizeof(n));
                memset(&t[0], -1, sizeof(t));
                ret = sscanf(&buff[0], "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d "
                    , &v[0], &t[0], &n[0]
                    , &v[1], &t[1], &n[1]
                    , &v[2], &t[2], &n[2]
                    , &v[3], &t[3], &n[3]);
                if( ret%3 == 0) goto print;
                
                memset(&v[0], -1, sizeof(v));
                memset(&n[0], -1, sizeof(n));
                memset(&t[0], -1, sizeof(t));
                ret = sscanf(&buff[0], "f %d//%d %d//%d %d//%d %d//%d "
                    , &v[0], &n[0]
                    , &v[1], &n[1]
                    , &v[2], &n[2]
                    , &v[3], &n[3]);
                if( ret%2 == 0) goto print;

                memset(&v[0], -1, sizeof(v));
                memset(&n[0], -1, sizeof(n));
                memset(&t[0], -1, sizeof(t));
                ret = sscanf(&buff[0], "f %d/%d %d/%d %d/%d %d/%d "
                    , &v[0], &t[0]
                    , &v[1], &t[1]
                    , &v[2], &t[2]
                    , &v[3], &t[3]);
                if( ret%2 == 0) goto print;

                memset(&v[0], -1, sizeof(v));
                memset(&n[0], -1, sizeof(n));
                memset(&t[0], -1, sizeof(t));
                ret = sscanf(&buff[0], "f %d %d %d %d"
                    , &v[0]
                    , &v[1]
                    , &v[2]
                    , &v[3]);

                print:
                printf("f ");
                for(int i = 0; i < 4; i++){
                    // printf("%d/%d/%d ", v[i], t[i], n[i]);
                    if(v[i] > 0) index_vertices.push_back(v[i]);
                    if(n[i] > 0) index_vertices.push_back(n[i]);
                    if(t[i] > 0) index_vertices.push_back(t[i]);
                }
                printf("\n");

            } break;
            default : {} // skip
        }
    }

    return GL_load_obj(objName, vertices, normals, texCoords, index_vertices, index_normals, index_texCoords);
}
int Renderer::GL_load_obj(const char *objName, std::vector<glm::vec3> verts, std::vector<glm::vec3> norms, std::vector<glm::vec2> textures,
                            std::vector<int> index_vertices, std::vector<int> index_normals, std::vector<int> index_texCoords){
    GL_Obj obj;
    glGenVertexArrays(1, &obj.VAO);
    glGenBuffers(7, &obj.VBO[0]);
    glGenBuffers(7, &obj.EBO[0]);

	glBindVertexArray(obj.VAO);
	glBindBuffer( GL_ARRAY_BUFFER, obj.VBO[0]);
	glBufferData( GL_ARRAY_BUFFER, verts.size() * sizeof(glm::vec3), &verts[0], GL_STATIC_DRAW );
	glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof( float ), (void*)0 );
	glEnableVertexAttribArray( 0 );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, obj.EBO[0]);
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, index_vertices.size() * sizeof(int), &index_vertices[0], GL_STATIC_DRAW);

    return 0;
}

