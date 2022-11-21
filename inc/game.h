#ifndef GAME_H
#define GAME_H

#include "renderer.h"


struct Game : public Renderer {
    int init();

    void display_func();
};

#endif