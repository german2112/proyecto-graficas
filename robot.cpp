#include "robot.h"
#define GL_SILENCE_DEPRECATION

Robot::Robot(){ // like init
    
    // variables for rotation
<<<<<<< HEAD
    xRot = 0;
    yRotation = 0;
    zRotation = 0;
	dir = 1; //  1 front -1 back
	leg = 0;
	chestrot = 0;
	ankle = 0;
	legMax = 90;
=======
    dir = 1; //  1 front -1 back
    xRot = 0;
    yRotation = 0;
    zRotation = 0;
    
>>>>>>> 5114f1b70a388dcc159027a756b98a50b2a9f1a2
    
    // color definition
    whiteColor[0]=1.0f;
    whiteColor[1]=1.0f;
    whiteColor[2]=1.0f;
    
    redColor[0]=0.48f;
    redColor[1]=0.06f;
    redColor[2]=0.08f;
    
    blueColor[0]=0.09f;
    blueColor[1]=0.23f;
    blueColor[2]=0.65f;
    
    greyColor[0]=0.41f;
    greyColor[1]=0.41f;
    greyColor[2]=0.41f;
    
    // size of parts definition
    sizes[HIPS][0] =      2.0f;
    sizes[HIPS][1] =      0.5f;
    sizes[HIPS][2] =      1.0f;
    
    sizes[BODY][0] =      1.5f;
    sizes[BODY][1] =      1.0f;
    sizes[BODY][2] =      1.0f;
    
    sizes[CHEST][0] =     2.5f;
    sizes[CHEST][1] =     1.0f;
    sizes[CHEST][2] =     1.5f;
    
    sizes[NECK][0] =      0.5f;
    sizes[NECK][1] =      0.3f;
    sizes[NECK][2] =      1.0f;
    
    sizes[HEAD][0] =      1.0f;
    sizes[HEAD][1] =      1.0f;
    sizes[HEAD][2] =      1.0f;
    
    sizes[RLEG][0] =      0.7f;
    sizes[RLEG][1] =      1.5f;
    sizes[RLEG][2] =      1.0f;
    sizes[LLEG][0] =      sizes[RLEG][0];
    sizes[LLEG][1] =      sizes[RLEG][1];
    sizes[LLEG][2] =      sizes[RLEG][2];
    
    sizes[RANKLE][0] =    0.9f;
    sizes[RANKLE][1] =    1.5f;
    sizes[RANKLE][2] =    1.2f;
    sizes[LANKLE][0] =    sizes[RANKLE][0];
    sizes[LANKLE][1] =    sizes[RANKLE][1];
    sizes[LANKLE][2] =    sizes[RANKLE][2];
    
    sizes[RFOOT][0] =     0.9f;
    sizes[RFOOT][1] =     0.4f;
    sizes[RFOOT][2] =     1.6f;
    sizes[LFOOT][0] =     sizes[RFOOT][0];
    sizes[LFOOT][1] =     sizes[RFOOT][1];
    sizes[LFOOT][2] =     sizes[RFOOT][2];
    
    sizes[RSHOULDER][0] = 1.0f;
    sizes[RSHOULDER][1] = 1.0f;
    sizes[RSHOULDER][2] = 1.0f;
    
    sizes[LSHOULDER][0] = sizes[RSHOULDER][0];
    sizes[LSHOULDER][1] = sizes[RSHOULDER][1];
    sizes[LSHOULDER][2] = sizes[RSHOULDER][2];
    
    sizes[RFOREARM][0] =  1.5f;
    sizes[RFOREARM][1] =  1.0f;
    sizes[RFOREARM][2] =  1.0f;
    
    sizes[LFOREARM][0] =  sizes[RFOREARM][0];
    sizes[LFOREARM][1] =  sizes[RFOREARM][1];
    sizes[LFOREARM][2] =  sizes[RFOREARM][2];
    
    sizes[RARM][0] =      0.5f;
    sizes[RARM][1] =      0.6f;
    sizes[RARM][2] =      0.5f;
    
    sizes[LARM][0] =      sizes[RARM][0];
    sizes[LARM][1] =      sizes[RARM][1];
    sizes[LARM][2] =      sizes[RARM][2];
    
    sizes[RHAND][0] =     0.4f;
    sizes[RHAND][1] =     0.3f;
    sizes[RHAND][2] =     0.3f;
    sizes[LHAND][0] =     sizes[RHAND][0];
    sizes[LHAND][1] =     sizes[RHAND][1];
    sizes[LHAND][2] =     sizes[RHAND][2];
    
    //relative to neck
    positions[HEAD][0] = 0;
    positions[HEAD][1] = (sizes[NECK][1]/2)+(sizes[HEAD][1]/2);
    positions[HEAD][2] = 0;
    
    //relative to chest
    positions[NECK][0] =      0;
    positions[NECK][1] =      (sizes[CHEST][1]/2)+(sizes[NECK][1]/2);
    positions[NECK][2] =      0;
    
    //relative to body
    positions[CHEST][0] =     0;
    positions[CHEST][1] =     (sizes[BODY][1]/2)+(sizes[CHEST][1]/2);
    positions[CHEST][2] =     0;
    
    //Center
    positions[BODY][0] =      0;
    positions[BODY][1] =      0;
    positions[BODY][2] =      0;
    
    // relative to body center
    positions[HIPS][0] =      0;
    positions[HIPS][1] =      (sizes[BODY][1]/2 + sizes[HIPS][1]/2)*-1;
    positions[HIPS][2] =      0;
    
    // position related to hips
    positions[RLEG][0] =      ((sizes[HIPS][0]/2)-sizes[RLEG][0])+(sizes[RLEG][0]/2);
    positions[RLEG][1] =      ((sizes[HIPS][1]/2)+(sizes[RLEG][1]/2))*-1;
    positions[RLEG][2] =      0;
    
    positions[LLEG][0] =      positions[RLEG][0]*-1;
    positions[LLEG][1] =      positions[RLEG][1];
    positions[LLEG][2] =      0;
    
    // position related to Leg
    positions[RANKLE][0] =    0;
    positions[RANKLE][1] =    ((sizes[RLEG][1]/2)+(sizes[RANKLE][1]/2)) *-1;
    positions[RANKLE][2] =    0;
    
    positions[LANKLE][0] =    0;
    positions[LANKLE][1] =    positions[RANKLE][1];
    positions[LANKLE][2] =    0;
    
    // position related to ankle
    positions[RFOOT][0] =     0;
    positions[RFOOT][1] =     ((sizes[RANKLE][1]/2)+(sizes[RFOOT][1]/2))*-1;
    positions[RFOOT][2] =     (sizes[RFOOT][2]-sizes[RANKLE][2])/2;
    
    positions[LFOOT][0] =     0;
    positions[LFOOT][1] =     positions[RFOOT][1];
    positions[LFOOT][2] =     positions[RFOOT][2];
    
    //relative to chest
    positions[RSHOULDER][0] = (sizes[CHEST][0]/2)+(sizes[RSHOULDER][0]/2);
    positions[RSHOULDER][1] = 0;
    positions[RSHOULDER][2] = 0;
    
    positions[LSHOULDER][0] = positions[RSHOULDER][0]*-1;
    positions[LSHOULDER][1] = 0;
    positions[LSHOULDER][2] = 0;
    
    //relative  to shoulder
    positions[RARM][0] =      (sizes[RSHOULDER][0]/2)+(sizes[RARM][0]/2);
    positions[RARM][1] =      0;
    positions[RARM][2] =      0;
    
    positions[LARM][0] =      positions[RARM][0]*-1;
    positions[LARM][1] =      0;
    positions[LARM][2] =      0;
    
    //relative to arm
    positions[RFOREARM][0] =  (sizes[RARM][0]/2)+(sizes[RFOREARM][0]/2);
    positions[RFOREARM][1] =  0;
    positions[RFOREARM][2] =  0;
    
    positions[LFOREARM][0] =  positions[RFOREARM][0]*-1;
    positions[LFOREARM][1] =  0;
    positions[LFOREARM][2] =  0;
    
    //relative to forearm
    positions[RHAND][0] =     (sizes[RFOREARM][0]/2)+(sizes[RHAND][0]/2);
    positions[RHAND][1] =     0;
    positions[RHAND][2] =     0;
    
    positions[LHAND][0] =     positions[RHAND][0]*-1;
    positions[LHAND][1] =     0;
    positions[LHAND][2] =     0;
    
    
    // define initial rotations x y z
    rotations[HIPS][0] =      0;
    rotations[HIPS][1] =      0;
    rotations[HIPS][2] =      0;
    rotations[HIPS][3] =      0;
    
    rotations[BODY][0] =      0;
    rotations[BODY][1] =      0;
    rotations[BODY][2] =      0;
    rotations[BODY][3] =      0;
    
    rotations[CHEST][0] =     0;
    rotations[CHEST][1] =     0;
    rotations[CHEST][2] =     0;
    rotations[CHEST][3] =     0;
    
    rotations[NECK][0] =      0;
    rotations[NECK][1] =      0;
    rotations[NECK][2] =      0;
    rotations[NECK][3] =      0;
    
    rotations[HEAD][0] =      0;
    rotations[HEAD][1] =      0;
    rotations[HEAD][2] =      0;
    rotations[HEAD][3] =      0;
    
    rotations[RLEG][0] =      0;
    rotations[RLEG][1] =      0;
    rotations[RLEG][2] =      0;
    rotations[RLEG][3] =      0;
    rotations[LLEG][0] =      rotations[RLEG][0];
    rotations[LLEG][1] =      rotations[RLEG][1];
    rotations[LLEG][2] =      rotations[RLEG][2];
    rotations[LLEG][3] =      rotations[RLEG][3];
    
    rotations[RANKLE][0] = 0;
    rotations[RANKLE][1] = 0;
    rotations[RANKLE][2] = 0;
    rotations[RANKLE][3] = 0;
    rotations[LANKLE][0] = rotations[RANKLE][0];
    rotations[LANKLE][1] = rotations[RANKLE][1];
    rotations[LANKLE][2] = rotations[RANKLE][2];
    rotations[LANKLE][3] = rotations[RANKLE][3];
    
    rotations[RFOOT][0] = 0;
    rotations[RFOOT][1] = 0;
    rotations[RFOOT][2] = 0;
    rotations[RFOOT][3] = 0;
    rotations[LFOOT][0] = rotations[RFOOT][0];
    rotations[LFOOT][1] = rotations[RFOOT][1];
    rotations[LFOOT][2] = rotations[RFOOT][2];
    rotations[LFOOT][3] = rotations[RFOOT][3];
    
    rotations[RSHOULDER][0] = 0;
    rotations[RSHOULDER][1] = 0;
    rotations[RSHOULDER][2] = 0;
    rotations[RSHOULDER][3] = 1;
    rotations[LSHOULDER][0] = rotations[RSHOULDER][0];
    rotations[LSHOULDER][1] = rotations[RSHOULDER][1];
    rotations[LSHOULDER][2] = rotations[RSHOULDER][2];
    rotations[LSHOULDER][3] = rotations[RSHOULDER][3];
    
    rotations[RFOREARM][0] = 0;
    rotations[RFOREARM][1] = 0;
    rotations[RFOREARM][2] = 1;
    rotations[RFOREARM][3] = 1;
    rotations[LFOREARM][0] = rotations[RFOREARM][0];
    rotations[LFOREARM][1] = rotations[RFOREARM][1]*-1;
    rotations[LFOREARM][2] = rotations[RFOREARM][2]*-1;
    rotations[LFOREARM][3] = rotations[RFOREARM][3]*-1;
    
    rotations[RARM][0] = 0;
    rotations[RARM][1] = 0;
    rotations[RARM][2] = 0;
    rotations[RARM][3] = 0;
    rotations[LARM][0] = rotations[RARM][0];
    rotations[LARM][1] = rotations[RARM][1];
    rotations[LARM][2] = rotations[RARM][2];
    rotations[LARM][3] = rotations[RARM][3];
    

    
    //    Head
    parts[HEAD] = new Block(blueColor, positions[HEAD],sizes[HEAD],rotations[HEAD]);
    //    Neck
    parts[NECK] = new Block(whiteColor,positions[NECK],sizes[NECK],rotations[NECK]);
    //    Hips
    parts[HIPS] = new Block(greyColor,positions[HIPS],sizes[HIPS],rotations[HIPS]);
    //    Body
    parts[BODY] = new Block(whiteColor,positions[BODY],sizes[BODY],rotations[BODY]);
    
    
    //    RightSide
    parts[RLEG] = new Block(whiteColor,positions[RLEG],sizes[RLEG],rotations[RLEG]);
    parts[RANKLE] = new Block(blueColor,positions[RANKLE],sizes[RANKLE],rotations[RANKLE]);
    parts[RFOOT] = new Block(blueColor,positions[RFOOT],sizes[RFOOT],rotations[RFOOT]);
    parts[RSHOULDER] = new Block(redColor,positions[RSHOULDER],sizes[RSHOULDER],rotations[RSHOULDER]);
    parts[RARM] = new Block(whiteColor,positions[RARM],sizes[RARM],rotations[RARM]);
    parts[RHAND] = new Block(blueColor,positions[RHAND],sizes[RHAND],rotations[RHAND]);
    parts[RFOREARM] = new Block(redColor,positions[RFOREARM],sizes[RFOREARM],rotations[RFOREARM]);
   
    //    Chest
    parts[CHEST] = new Block(redColor,positions[CHEST],sizes[CHEST],rotations[CHEST]);
    
    //    LeftSide
    parts[LSHOULDER] = new Block(redColor,positions[LSHOULDER],sizes[LSHOULDER],rotations[LSHOULDER]);
    parts[LARM] = new Block(whiteColor,positions[LARM],sizes[LARM],rotations[LARM]);
    parts[LFOREARM] = new Block(redColor,positions[LFOREARM],sizes[LFOREARM],rotations[LFOREARM]);
    parts[LHAND] = new Block(blueColor,positions[LHAND],sizes[LHAND],rotations[LHAND]);
    parts[LLEG] = new Block(whiteColor,positions[LLEG],sizes[LLEG],rotations[LLEG]);
    parts[LANKLE] = new Block(blueColor,positions[LANKLE],sizes[LANKLE],rotations[LANKLE]);
    parts[LFOOT] = new Block(blueColor,positions[LFOOT],sizes[LFOOT],rotations[LFOOT]);
   
    
    
    
    
    
    
    
}

Robot::~Robot(){
    
}

void Robot::draw(){ // display()
    
    
    // Center
    parts[BODY]->draw(rotations[BODY]);
    glPushMatrix();
    {
        parts[HIPS]->draw(rotations[HIPS]);
        
        // RIGHT SIDE LEGS
        glPushMatrix();
        {
<<<<<<< HEAD
			glRotatef(leg, 1, 0, 0);
			parts[RLEG]->draw(rotations[RLEG]);
			glRotatef(ankle, 1, 0, 0);
			parts[RANKLE]->draw(rotations[RANKLE]);
			parts[RFOOT]->draw(rotations[RFOOT]);
=======
            parts[RLEG]->draw(rotations[RLEG]);
            parts[RANKLE]->draw(rotations[RANKLE]);
            parts[RFOOT]->draw(rotations[RFOOT]);
>>>>>>> 5114f1b70a388dcc159027a756b98a50b2a9f1a2
            
        }
        glPopMatrix();
        
        // LEFT SIDE LEGS
        glPushMatrix();
        {
<<<<<<< HEAD
			glRotatef(-leg, 1, 0, 0);
			parts[LLEG]->draw(rotations[LLEG]);
			glRotatef(ankle, 1, 0, 0);
			parts[LANKLE]->draw(rotations[LANKLE]);
			parts[LFOOT]->draw(rotations[LFOOT]);
        }
        glPopMatrix();
		/*if (leg == 90) {
			glPushMatrix();
			{
				glRotatef(180, 1, 0, 0);
				parts[LANKLE]->draw(rotations[LANKLE]);
			}
			glPopMatrix();
		}*/
=======
            parts[LLEG]->draw(rotations[LLEG]);
            parts[LANKLE]->draw(rotations[LANKLE]);
            parts[LFOOT]->draw(rotations[LFOOT]);
        }
        glPopMatrix();
        
>>>>>>> 5114f1b70a388dcc159027a756b98a50b2a9f1a2
        
        
    }glPopMatrix();
    
    glPushMatrix();
    {
<<<<<<< HEAD
		glRotatef(chestrot, 0, 0, 1);
        parts[CHEST]->draw(rotations[CHEST]);	
=======
        parts[CHEST]->draw(rotations[CHEST]);
        
>>>>>>> 5114f1b70a388dcc159027a756b98a50b2a9f1a2
        //ARMS
        
        // RIGHT ARM
        glPushMatrix();
        {
            parts[RSHOULDER]->draw(rotations[RSHOULDER]);
            parts[RARM]->draw(rotations[RARM]);
            parts[RFOREARM]->draw(rotations[RFOREARM]);
            parts[RHAND]->draw(rotations[RHAND]);
        }
        glPopMatrix();
        
        // LEFT ARM
        glPushMatrix();
        {
            parts[LSHOULDER]->draw(rotations[LSHOULDER]);
            parts[LARM]->draw(rotations[LARM]);
            parts[LFOREARM]->draw(rotations[LFOREARM]);
            parts[LHAND]->draw(rotations[LHAND]);
        }
        glPopMatrix();
        
        
        
        // NECK
        parts[NECK]->draw(rotations[NECK]);
        // HEAD
        parts[HEAD]->draw(rotations[HEAD]);
        
        
    }
    glPopMatrix();
    
    
    
    
}

void Robot::update(){ // update
<<<<<<< HEAD
    
		leg += dir * 0.03;

	
	if (leg > 90) {
		leg = legMax;
	}

	/*ankle += dir * 0.03;
	if (ankle > 20 || ankle < -20) {
		dir = -dir;
	}*/
=======
    zRotation += dir *0.01; //
    
    if(zRotation > 10 || zRotation < 0){
        dir = -dir;
    }
    
    xRot += dir *0.01;
    if(xRot > 10 || xRot < 0){
        dir = -dir;
    }
>>>>>>> 5114f1b70a388dcc159027a756b98a50b2a9f1a2
}




<<<<<<< HEAD

=======
>>>>>>> 5114f1b70a388dcc159027a756b98a50b2a9f1a2
