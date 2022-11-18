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
    
	glutCreateWindow( "CSE-170 Computer Graphics" );

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

	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f ); // background color
	glEnable( GL_DEPTH_TEST ); // enable depth test
	glEnable( GL_CULL_FACE ); // enable back-face culling
	glutMainLoop();

    ACTIVE_WINDOW = this;
    return 0;
}


void __display_func (){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();

    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->display_func();
    }
}
void __idle_func (){
	glutPostRedisplay();
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->idle_func();
    }

}
void __reshape_func (int w, int h){
	glViewport( 0, 0, w, h );
	glutPostRedisplay();
    if(ACTIVE_WINDOW){
        ACTIVE_WINDOW->reshape_func(w, h);
    }

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