cmake_minimum_required(VERSION 3.24.2)

project(CodeZ)


find_package(OpenGL REQUIRED)
link_directories(lib)
# find_package(freeglut REQUIRED)


add_subdirectory(src)

if (WIN32)
target_link_libraries(${PROJECT_NAME} gamelib windowlib renderlib opengl32 glew32 freeglut)
endif(WIN32)
if(UNIX)
target_link_libraries(${PROJECT_NAME} GL GLU glut GLEW)
endif(UNIX)
