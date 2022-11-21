#include <game.h>
#include "Settings.h"

#define GUARD(func) \
    ret = func; \
    if(ret) return ret 

const char *objNames[] = {
    "plane"
};
const char *objFiles[] = {
    "untitled.obj"
};
int obj_count = 1;
int Game::init(){
    int ret;
    GUARD(init_window(InitWindowWidth, InitWindowHeight));
    GUARD(init_renderer(objNames, objFiles, obj_count));
    return 0;
}

void Game::display_func(){

}