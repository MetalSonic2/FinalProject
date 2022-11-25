#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <renderer.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

GLuint vao;
GLuint vbo;
GLuint ebo;

int Renderer::init_renderer(const char **obj_names, const char **obj_files, int objc){
    shader.Create("./shaders/TexPerspLight.vert", "./shaders/TexPerspLight.frag");
    printf("created shaders!\n");

    for(int i = 0; i < objc; i++){
        int ret = GL_load_obj(obj_names[i], obj_files[i]);
        if(ret) {
            printf("Failed to load %s\n", obj_files[i]);
            return ret;
        }
    }
    glBindVertexArray(0);
    printf("Loaded Objects\n");

    position = glm::vec3(0,1,2);
    direction = glm::vec3(0,0,-1);
    return 0;
}


GL_Obj Renderer::get_gl_obj(const char *name){
    return GL_Objs[name];
}
int Renderer::GL_load_obj(const char *obj_name, const char *obj_file){
    // std::ifstre  am ifs(objFile, std::ios_base::in);    
    printf("started loading: %s\n", obj_name);
    FILE *file = fopen(obj_file, "r");
    std::vector<glm::vec3> starting_vertices;
    std::vector<glm::vec3> starting_normals;
    std::vector<glm::vec2> starting_texCoords;
    std::vector<int> index_vertices;
    std::vector<int> index_normals;
    std::vector<int> index_texCoords;
    
    starting_vertices.push_back(glm::vec3(0, 0, 0));
    starting_normals.push_back(glm::vec3(0, 0, 0));
    starting_texCoords.push_back(glm::vec2(0, 0));

    char buff[256] = {0};  
    while(!feof(file)){
        int line_len = 0;
        memset(&buff[0], 0, 256);
        fscanf(file, "%[^\n]\n", &buff[0]);
        // printf("LINE: %s\n", &buff[0]);
        switch (buff[0]) {
            case 'v' : {
                switch (buff[1]) {
                    case 't' : {
                        float x, y;
                        sscanf(&buff[0], "vt %f %f", &x, &y);
                        // printf("vt %f %f\n", x, y);
                        starting_texCoords.push_back(glm::vec2(x,y));
                    } break; // texcoords
                    case 'n' : {
                        float x, y, z;
                        sscanf(&buff[0], "vn %f %f %f", &x, &y, &z);
                        //printf("vn %f %f %f\n", x, y, z);
                        starting_normals.push_back(glm::vec3(x,y,z));
                    } break; // normals
                    default : { // points
                        float x, y, z;
                        sscanf(&buff[0], "v %f %f %f\n", &x, &y, &z);
                        //printf("v %f %f %f\n", x, y, z);
                        starting_vertices.push_back(glm::vec3(x,y,z));
                    } break;
                }
            } break;
            case 'f' : {
                std::vector<int> v;
                std::vector<int> n;
                std::vector<int> t;
                int a = 0, b = 0, c = 0;
                enum MODE{
                    NONE = -1,
                    VTN = 0,
                    VT_ = 1,
                    V_N = 2,
                    V__ = 3
                };
                int mode = NONE;
                if(sscanf(&buff[0], "f %d/%d/%d ", &a, &b, &c) == 3){
                    mode = VTN;
                }
                else if(sscanf(&buff[0], "f %d//%d ", &a, &b, &c) == 2){
                    mode = V_N;
                }

                else if(sscanf(&buff[0], "f %d/%d ", &a, &b, &c) == 2){
                    mode = VT_;
                }
                else if(sscanf(&buff[0], "f %d ", &a, &b, &c) == 1){
                    mode = V__;
                }
                
                else return 1;
                // printf("mode: %d\n", mode);
                const char *patterns[] = {" %d/%d/%d ", " %d//%d ", " %d/%d ", " %d "};
                int offset = 0;
                while(true){
                    //advance to next whitespace;
                    while(buff[offset] != ' ' && buff[offset] != '\n' && buff[offset] != '\0') offset++;
                    if(buff[offset] == '\0') break;
                    
                    a = 0; b = 0; c = 0;
                    sscanf(&buff[offset], patterns[mode], &a, &b, &c);
                    if(mode == VTN){
                        v.push_back(a);
                        t.push_back(b);
                        n.push_back(c);
                    }else if(mode == VT_){
                        v.push_back(a);
                        t.push_back(b);
                        n.push_back(0);
                    }else if(mode == V_N){
                        v.push_back(a);
                        t.push_back(0);
                        n.push_back(b);
                    }else if(mode == V__){
                        v.push_back(a);
                        t.push_back(0);
                        n.push_back(0);
                    }else{

                    }
                    offset++;
                }
                
                // int v[4], n[4], t[4];
                // int ret = 0;
                // memset(&v[0], -1, sizeof(v));
                // memset(&n[0], -1, sizeof(n));
                // memset(&t[0], -1, sizeof(t));
                // ret = sscanf(&buff[0], "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d "
                //     , &v[0], &t[0], &n[0]
                //     , &v[1], &t[1], &n[1]
                //     , &v[2], &t[2], &n[2]
                //     , &v[3], &t[3], &n[3]);
                // if( ret%3 == 0) goto print;
                
                // memset(&v[0], -1, sizeof(v));
                // memset(&n[0], -1, sizeof(n));
                // memset(&t[0], -1, sizeof(t));
                // ret = sscanf(&buff[0], "f %d//%d %d//%d %d//%d %d//%d "
                //     , &v[0], &n[0]
                //     , &v[1], &n[1]
                //     , &v[2], &n[2]
                //     , &v[3], &n[3]);
                // if( ret%2 == 0) goto print;

                // memset(&v[0], -1, sizeof(v));
                // memset(&n[0], -1, sizeof(n));
                // memset(&t[0], -1, sizeof(t));
                // ret = sscanf(&buff[0], "f %d/%d %d/%d %d/%d %d/%d "
                //     , &v[0], &t[0]
                //     , &v[1], &t[1]
                //     , &v[2], &t[2]
                //     , &v[3], &t[3]);
                // if( ret%2 == 0) goto print;

                // memset(&v[0], -1, sizeof(v));
                // memset(&n[0], -1, sizeof(n));
                // memset(&t[0], -1, sizeof(t));
                // ret = sscanf(&buff[0], "f %d %d %d %d"
                //     , &v[0]
                //     , &v[1]
                //     , &v[2]
                //     , &v[3]);

                // print:
                // // printf("f ");
                
                if(v.size() > 3){
                    int order[] = {0, 1, 2, 0, 2, 3};
                    for(int i = 0; i < 6; i++){
                        // printf("%d/%d/%d ", v[i], t[i], n[i]);
                        index_vertices.push_back(v[order[i]]);
                        index_normals.push_back(n[order[i]]);
                        index_texCoords.push_back(t[order[i]]);
                    }
                } else{
                    for(int i = 0; i < 3; i++){
                        index_vertices.push_back(v[i]);
                        index_normals.push_back(n[i]);
                        index_texCoords.push_back(t[i]);
                    }
                }
                // printf("\n");
            } break;
            default : {} // skip
        }
    }
    

    std::vector<glm::vec3> final_verticies;
    std::vector<glm::vec3> final_normals;
    std::vector<glm::vec2> final_texCoords;
    
    for(int i = 0; i < index_vertices.size(); i++){
        final_verticies.push_back(starting_vertices[index_vertices[i]]);
        final_normals.push_back(starting_normals[index_normals[i]]);
        final_texCoords.push_back(starting_texCoords[index_texCoords[i]]);
    }

    return GL_load_obj(obj_name, final_verticies, final_normals, final_texCoords);
}
int Renderer::GL_load_obj(const char *obj_name, std::vector<glm::vec3> verts, std::vector<glm::vec3> norms, std::vector<glm::vec2> textures){
    GL_Obj obj;
    glGenVertexArrays(1, &(obj.VAO));
    glGenBuffers(7, &obj.VBO[0]);

	glBindVertexArray(obj.VAO);
    obj.vertex_count = verts.size();
    // verts

	glBindBuffer( GL_ARRAY_BUFFER, obj.VBO[0]);
	glBufferData( GL_ARRAY_BUFFER, verts.size() * sizeof(glm::vec3), &verts[0], GL_STATIC_DRAW );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), (void*)0 );
	glEnableVertexAttribArray( 0 );
    // norms
	glBindBuffer( GL_ARRAY_BUFFER, obj.VBO[1]);
	glBufferData( GL_ARRAY_BUFFER, norms.size() * sizeof(glm::vec3), &norms[0], GL_STATIC_DRAW );
	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), (void*)0 );
	glEnableVertexAttribArray( 1 );
    // textures
	glBindBuffer( GL_ARRAY_BUFFER, obj.VBO[2]);
	glBufferData( GL_ARRAY_BUFFER, textures.size() * sizeof(glm::vec2), &textures[0], GL_STATIC_DRAW );
	glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof( float ), (void*)0 );
	glEnableVertexAttribArray( 2 );
    GL_Objs[obj_name] = obj;
    printf("finished loading: %s\n", obj_name);
    return 0;
}
void Renderer::display_func(){
    // printf("display_func\n");
    if(locked_mode) glutWarpPointer(width/2, height/2);
	shader.Use();
    PerspectiveMatrix = glm::perspective<float>(glm::radians(90.0f), width /(float) height, 0.01f, 1000.0f);
	shader.SetUniform( "projectionMatrix", glm::value_ptr( PerspectiveMatrix ), 4, GL_FALSE, 1 );
    ViewMatrix = glm::lookAt(position, position + direction, glm::vec3(0,1,0));
	shader.SetUniform( "viewMatrix", glm::value_ptr( ViewMatrix ), 4, GL_FALSE, 1 );
    glm::mat4 ModelMatrix(1.0f);
	shader.SetUniform( "modelMatrix", glm::value_ptr( ModelMatrix ), 4, GL_FALSE, 1 );
	shader.SetUniform( "tex0", 0);
	shader.SetUniform( "use_textures", 3 != 3);

    for(int i = 0; i < render_objs.size(); i++){
        render_objs[i].draw(shader);
    }
}
void Renderer::add_render_obj(GameObject &obj){
    render_objs.push_back(obj);
}