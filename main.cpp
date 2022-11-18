// #include <GL/glew.h>
// #include <GL/freeglut.h>
// #include <GL/gl.h>
// #include <stdio.h>
// #include <vector>
// #include <stb.h>    
// #include <Settings.h>
#include <game.h>
#include <stdio.h>

// void display_func (){
//     glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     glutSwapBuffers();
// }
// void idle_func (){
// 	glutPostRedisplay();

// }
// void reshape_func (int w, int h){
// 	glViewport( 0, 0, w, h );
// 	glutPostRedisplay();

// }
// void keyboard_func (unsigned char c, int x, int y){

// }
// void key_released (unsigned char c, int x, int y){

// }
// void key_special_pressed (int c, int x, int y){

// }
// void key_special_released (int c, int x, int y){

// }
// void mouse_func (int button, int state, int x, int y){

// }
// void active_motion_func (int x, int y){

// }
// void passive_motion_func (int x, int y){

// }


int main(int argc, char **argv){
    glutInit(&argc, argv);
    Game g;
	int ret = g.init();
	// printf("Hello!\n");
	return ret;

}