/*
 Esteban Cortés Lozano A01334483
 Germán Torres Molina
 * Sergio Ruiz.
 *
 * TC3022. Computer Graphics Course.
 * Basic template OpenGL project.
 */

// Please don't change lines 9-31 (It helps me to grade)
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "freeglut.h"
#endif
#ifdef __unix__
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

#include <stdio.h>
#include <math.h>
#include "robot.h"
#include "/Users/super/Downloads/cgcourse-master (2)/cgcourse-master/TEXTURES_ACTIVITY/OBJ/header/glm.h"


Robot* robot;
GLMmodel* sintel;

float		sintel_pos[3];
float		sintel_dims[3];
float		radius;
void init() // FOR GLUT LOOP
{
	radius = 0;
	sintel_pos[0] = 0.0f;
	sintel_pos[1] = 0.0f;
	sintel_pos[2] = -5.0f;
	sintel = glmReadOBJ("/Users/super/Downloads/cgcourse-master (3)/cgcourse-master/CG_DEMO_VS2015/CG_DEMO/CG_DEMO/cube.obj");
	glmUnitize(sintel);
	glmDimensions(sintel, sintel_dims);
	glmScale(sintel, 8.0f);
	float center[3] = {
		sintel_pos[0] + sintel_dims[0] / 2.0f,
		sintel_pos[1] + sintel_dims[1] / 2.0f,
		sintel_pos[2] + sintel_dims[2] / 2.0f };
	radius = sqrtf(center[0] * center[0] + center[1] * center[1] + center[2] * center[2]);
	printf("SINTEL_DIMS={%.3f,%.3f,%.3f}\n", sintel_dims[0], sintel_dims[1], sintel_dims[2]);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0, 0.0, 0.0, 0.0);

    robot = new Robot();
    
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.0, 0.0, 0.0, 0.0);    // Clear the color state.
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
}


void axes(float scale)
{
    glLineWidth(3);
    glBegin(GL_LINES);
    {
        glColor3f(1, 0, 0); // red
        glVertex3f(0, 0, 0);
        glVertex3f(scale, 0, 0);
        
        glColor3f(0, 1, 0); // green
        glVertex3f(0, 0, 0);
        glVertex3f(0, scale, 0);
        
        glColor3f(0, 0, 1); // blue
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, scale);
    }
    glEnd();
}



void display()                            // Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers.
    glLoadIdentity();                                                // Reset 3D view matrix.
    gluLookAt(5.0, 7.0, 15.0,                                        // Where the camera is.
              0.0, 0.0, 0.0,                                        // To where the camera points at.
              0.0, 1.0, 0.0);                                        // "UP" vector.
    
    axes(5);
    
	glTranslatef(sintel_pos[0], sintel_pos[1], sintel_pos[2]);
	glmDraw(sintel, GLM_NONE);
	robot->draw();
    glutSwapBuffers();           

}

void idle()                                                            // Called when drawing is finished.
{
<<<<<<< HEAD
	robot->update();
=======
>>>>>>> 5114f1b70a388dcc159027a756b98a50b2a9f1a2
    glutPostRedisplay();                                            // Display again.
}

void reshape(int x, int y)                                            // Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
    glLoadIdentity();                                                // Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);        // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
    gluLookAt(0.0, 1.0, 10.0,  // where the camera is
              0.0, 0.0, 0.0, // pointing at
              0.0, 1.0, 0.0); // up vector
    
    display();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG first program");
    
    init();
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}
