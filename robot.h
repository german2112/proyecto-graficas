#pragma once
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
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
#include "block.h"
#define PARTS 19

#ifndef __ROBOT
#define __ROBOT

class Robot{
public:
    Robot();
    ~Robot(); // this free the memory when im done with the class
    
    
    void draw();
    void update();
    
    enum ROBOT_PARTS{
        HEAD, NECK, BODY, HIPS, RLEG, RANKLE, RFOOT, RSHOULDER, RARM, RHAND,
        LSHOULDER, LARM, LHAND, LLEG, LANKLE, LFOOT, CHEST, LFOREARM, RFOREARM
    };
    
    Block* parts[PARTS];
    float rotations[PARTS][4];
    float positions[PARTS][3];
    float sizes[PARTS][3];
    // colors definition
    float redColor[3];   // R G B 123 17 22
    float blueColor[3];  // R G B 25 59 166
    float whiteColor[3]; // R G B 1 1 1
    float greyColor[3];  // R G B 105 105 105
    
    int dir;
    float xRot;
    float yRotation;
    float zRotation;
<<<<<<< HEAD
	float legMax;
	float leg;
	float chestrot;
	float ankle;
=======
    
>>>>>>> 5114f1b70a388dcc159027a756b98a50b2a9f1a2
};

#endif
