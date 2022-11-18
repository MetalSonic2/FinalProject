#include <game.h>
#include "Settings.h"

#define GUARD(func) \
    ret = func; \
    if(ret) return ret 


int Game::init(){
    int ret;
    GUARD(window.init_window(InitWindowWidth, InitWindowHeight));
    renderer.window = &window;
    GUARD(renderer.init());
    return 0;
}