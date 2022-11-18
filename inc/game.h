#ifndef GAME_H
#define GAME_H

#include "renderer.h"


struct Game{
    Renderer renderer;
    Window window;    

    int init();
};

#endif