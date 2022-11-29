#ifndef GAME_H
#define GAME_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <GL/gl.h>
#include <iostream>
#include "shader.h"
#include "shaderprogram.h"
#include "renderer.h"
#include "player.h"
#include <chrono>
#include <thread>
#include <future>


struct Game : public Renderer {
    int init();
    void active_motion_func(int x, int y);
    void mouse_func(int button, int state, int x, int y);
    void passive_motion_func(int x, int y);
    void keyboard_func( unsigned char key, int x, int y );
    void key_released( unsigned char key, int x, int y );

    void start_timer(int us);
    
public:
    Player player;
    void timer(int us);
    void tick();
};

#endif