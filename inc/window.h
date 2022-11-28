#ifndef WINDOW_H
#define WINDOW_H
#include <GL/freeglut.h>
#include <glm/glm.hpp>

struct Window{
    int width, height;

    glm::vec2 prev_mouse_pos;
    int mouse_states[4];
    int kbd_states[256];
        
    virtual void display_func();
    virtual void idle_func();
    virtual void reshape_func(int w, int h);
    virtual void keyboard_func(unsigned char c, int x, int y);
    virtual void key_released(unsigned char c, int x, int y);
    virtual void key_special_pressed(int c, int x, int y);
    virtual void key_special_released(int c, int x, int y);
    virtual void mouse_func(int button, int state, int x, int y);
    virtual void active_motion_func(int x, int y);
    virtual void passive_motion_func(int x, int y);

// successfully initializing a window will set it to active window
    int init_window(int w, int h); 
    void window_begin();
    virtual ~Window(){};
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