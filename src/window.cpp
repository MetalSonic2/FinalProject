#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "window.h"
#include <stdio.h>

Window *ACTIVE_WINDOW = NULL;


int Window::init_window(int w, int h){
    width = w;
    height = h;
	glutInitWindowPosition( 100, 100 );
	glutInitWindowSize( width, height );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    
    for(int i = 0; i < 256; i++) kbd_states[i] = false;
	glutCreateWindow( "CSE-170 Computer Graphics" );
    printf("creating window!\n");
    
	GLenum ret = glewInit();
	if( ret != GLEW_OK ) {
		printf("GLEW initialization error.\n");
		glewGetErrorString( ret );
		return -1;
	}

	glutDisplayFunc( __display_func );
	glutIdleFunc( __idle_func );
	glutReshapeFunc( __reshape_func );
	glutKeyboardFunc( __keyboard_func );
	glutKeyboardUpFunc( __key_released );
	glutSpecialFunc( __key_special_pressed );
	glutSpecialUpFunc( __key_special_released );
	glutMouseFunc( __mouse_func );
	glutMotionFunc( __active_motion_func );
	glutPassiveMotionFunc( __passive_motion_func );
    printf("set functions!\n");

	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f ); // background color
	glEnable( GL_DEPTH_TEST ); // enable depth test
	// glEnable( GL_CULL_FACE ); // enable back-face culling

    ACTIVE_WINDOW = this;
    return 0;
}

void Window::window_begin(){
	glutMainLoop();
}

void Window::display_func(){
}
void Window::idle_func(){
}
void Window::reshape_func(int w, int h){
    width = w; height = h;
}
void Window::keyboard_func(unsigned char c, int x, int y){
    
}
void Window::key_released(unsigned char c, int x, int y){
    
}
void Window::key_special_pressed(int c, int x, int y){
    
}
void Window::key_special_released(int c, int x, int y){
    
}
void Window::mouse_func(int button, int state, int x, int y){
    // Key 0: left button
	// Key 1: middle button
	// Key 2: right button
	// Key 3: scroll up
	// Key 4: scroll down

	if( x < 0 || x > width || y < 0 || y > height )
		return;


	mouse_states[ button ] = ( state == GLUT_DOWN );

	prev_mouse_pos = glm::vec2(x,y);
}
void Window::active_motion_func(int x, int y){
    
}
void Window::passive_motion_func(int x, int y){
   
}

void __display_func (){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->display_func();
    }
    glutSwapBuffers();
}
void __idle_func (){
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->idle_func();
    }
	glutPostRedisplay();
}
void __reshape_func (int w, int h){
	if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->reshape_func(w, h);
    }
    glViewport( 0, 0, w, h );
	glutPostRedisplay();
}
void __keyboard_func (unsigned char c, int x, int y){
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->keyboard_func(c, x, y);
    }
}
void __key_released (unsigned char c, int x, int y){
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->key_released(c, x, y);
    }

}
void __key_special_pressed (int c, int x, int y){
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->key_special_pressed(c, x, y);
    }
}
void __key_special_released (int c, int x, int y){
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->key_special_released(c, x, y);
    }
}
void __mouse_func (int button, int state, int x, int y){
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->mouse_func(button, state, x, y);
    }
}
void __active_motion_func (int x, int y){
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->active_motion_func(x, y);
    }
}
void __passive_motion_func (int x, int y){
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->passive_motion_func(x, y);
    }
}