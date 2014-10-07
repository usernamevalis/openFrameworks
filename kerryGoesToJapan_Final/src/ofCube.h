//
//  ofCube.h
//  ofBoxExample
//
//  Created by Nathan Gates on 9/23/14.
//
//

#ifndef __ofBoxExample__ofCube__
#define __ofBoxExample__ofCube__

#include <iostream>
#include "ofMain.h"

class ofCube {
    
public: // place public functions or variables declarations here
    
    // methods, equivalent to specific functions of your class objects
    void update(int loopValue);  // update method, used to refresh your objects properties
    void draw(ofImage& blockImage);    // draw method, this where you'll do the object's drawing
    void circles(ofPoint& point,ofImage& blockImage,int loopCounter);
    void wordsOfWisdomCube(ofImage& blockImage,ofPoint& point);
    
    // variables    
    ofVec3f pos;
    
    float movementSpeed;
	float cloudSize ;
	float maxBoxSize;
	float spacing ;
	int boxCount;
    float boxSize;
    
    ofCube(); // constructor - used to initialize an object, if no properties are passed
    //               the program sets them to the default value
    
private: // place private functions or variables declarations here
    
}; // dont't forget the semicolon!!

#endif /* defined(__ofBoxExample__ofCube__) */
