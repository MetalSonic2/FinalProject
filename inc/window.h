#ifndef WINDOW_H
#define WINDOW_H

#include <GL/freeglut.h>

struct Window{
    int width, height;
        
    void (*display_func )();
    void (*idle_func) ();
    void (*reshape_func )(int w, int h);
    void (*keyboard_func )(unsigned char c, int x, int y);
    void (*key_released )(unsigned char c, int x, int y);
    void (*key_special_pressed )(int c, int x, int y);
    void (*key_special_released )(int c, int x, int y);
    void (*mouse_func )(int button, int state, int x, int y);
    void (*active_motion_func )(int x, int y);
    void (*passive_motion_func )(int x, int y);

// successfully initializing a window will set it to active window
    int init_window(int w, int h); 

};

void __display_func ();
void __idle_func ();
void __reshape_func (int w, int h);
void __keyboard_func (unsigned char c, int x, int y);
void __key_released (unsigned char c, int x, int y);
void __key_special_pressed (int c, int x, int y);
void __key_special_released (int c, int x, int y);
void __mouse_func (int button, int button2, int x, int y);
void __active_motion_func (int x, int y);
void __passive_motion_func (int x, int y);

extern Window *ACTIVE_WINDOW;

#endif