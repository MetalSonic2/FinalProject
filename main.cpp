// #include <GL/glew.h>
// #include <GL/freeglut.h>
// #include <GL/gl.h>
// #include <stdio.h>
// #include <vector>
// #include <stb.h>    
// #include <Settings.h>
#include <game.h>
#include <stdio.h>

int main(int argc, char **argv){
  glutInit(&argc, argv);
  Game g;
	int ret = g.init();
  // printf("Hello!\n");
	return ret;

}