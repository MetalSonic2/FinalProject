cmake_minimum_required(VERSION 3.24.2)

project(CodeZ)


find_package(OpenGL REQUIRED)
link_directories(lib)
# find_package(freeglut REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/inc/)

add_subdirectory(src)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
set(RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
add_executable(${PROJECT_NAME} main.cpp)

if (WIN32)
target_link_libraries(${PROJECT_NAME} gamelib windowlib renderlib playerlib gameobjlib intersectionlib
                                    geometrylib zombielib resourcelib gunlib opengl32 glew32 freeglut)
endif(WIN32)
if(UNIX)
target_link_libraries(${PROJECT_NAME} gamelib windowlib renderlib playerlib gameobjlib intersectionlib
geometrylib zombielib resourcelib gunlib GL GLU glut GLEW)
endif(UNIX)
