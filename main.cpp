#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <vector>
#include <stb.h>    
#include <Settings.h>

void display_func (){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}
void idle_func (){
	glutPostRedisplay();

}
void reshape_func (int w, int h){
	// WindowWidth  = width;
	// WindowHeight = height;

	glViewport( 0, 0, w, h );
	glutPostRedisplay();

}
void keyboard_func (unsigned char c, int x, int y){

}
void key_released (unsigned char c, int x, int y){

}
void key_special_pressed (int c, int x, int y){

}
void key_special_released (int c, int x, int y){

}
void mouse_func (int button, int button2, int x, int y){

}
void active_motion_func (int x, int y){

}
void passive_motion_func (int x, int y){

}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    
	glutInitWindowPosition( 100, 100 );
	glutInitWindowSize( InitWindowWidth, InitWindowHeight );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    
	glutCreateWindow( "CSE-170 Computer Graphics" );
	// Initialize GLEW
    printf("Starting!\n");
	GLenum ret = glewInit();
	if( ret != GLEW_OK ) {
		printf("GLEW initialization error.\n");
		glewGetErrorString( ret );
		return -1;
	}

	glutDisplayFunc( display_func );
	glutIdleFunc( idle_func );
	glutReshapeFunc( reshape_func );
	glutKeyboardFunc( keyboard_func );
	glutKeyboardUpFunc( key_released );
	glutSpecialFunc( key_special_pressed );
	glutSpecialUpFunc( key_special_released );
	glutMouseFunc( mouse_func );
	glutMotionFunc( active_motion_func );
	glutPassiveMotionFunc( passive_motion_func );

	// init();

	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f ); // background color
	glEnable( GL_DEPTH_TEST ); // enable depth test
	glEnable( GL_CULL_FACE ); // enable back-face culling
	glutMainLoop();

	return 0;

}