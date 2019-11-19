#include "block.h"
#define GL_SILENCE_DEPRECATION
Block::Block(float colors[3], float positions[3], float sizes[3], float rotations[4]){ // like init
    position[0] = positions[0];
    position[1] = positions[1];
    position[2] = positions[2]; // x y z
    color[0] = colors[0];
    color[1] = colors[1];
    color[2] = colors[2]; // r g b
    size[0] = sizes[0];
    size[1] = sizes[1];
    size[2] = sizes[2];
    rotation[0] = rotations[0]; //angle
    rotation[1] = rotations[1]; //x
    rotation[2] = rotations[2]; // y
    rotation[3] = rotations[3]; // z
    
    
}

Block::~Block(){
    
}

void Block::draw(float rotations[4]){ // display()
    // color
    glColor3f(color[0],color[1],color[2]);
    // translate
    glTranslatef(position[0], position[1], position[2]);
    
    // rotate
    glRotatef(rotation[0], rotation[1], rotation[2], rotation[3]);
    //glRotatef(rotations[0], rotations[1], rotations[2], rotations[3]);
    
    glPushMatrix();
    {
        // scale
        glScalef(size[0],size[1],size[2]);
        
        glutSolidCube(1);
    }
    glPopMatrix();
    
}

void Block::update(){ // update
}

