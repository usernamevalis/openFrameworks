//
//  ofCube.cpp
//  ofBoxExample
//
//  Created by Nathan Gates on 9/23/14.
//
//

#include "ofCube.h"

ofCube::ofCube()
{
    movementSpeed = 0.05; //dropping the speed to around .01 creates snake type animations
	cloudSize = ofGetWidth() / 2;
	maxBoxSize = 100;
	spacing = 1;
	boxCount = 1;
    boxSize = 1;
}

void ofCube::update(int loopValue){
    
    float t = (ofGetElapsedTimef() + loopValue * spacing) * movementSpeed;
    pos.set(
            ofSignedNoise(t, 0, 0),
            ofSignedNoise(0, t, 0),
            ofSignedNoise(0, 0, t));
    
    boxSize = maxBoxSize * ofNoise(pos.x, pos.y, pos.z);
    
    pos *= cloudSize;
 
}

void ofCube::draw(ofImage& blockImage){
   
    ofPushMatrix();
    //this places the boxes in the different positions across the screen
    ofTranslate(pos);
    ofRotateX(pos.x);
    ofRotateY(pos.y);
    ofRotateZ(pos.z);
    
    blockImage.bind();
    ofFill();
    ofSetColor(255);
    ofDrawBox(boxSize+50);
    blockImage.unbind();
    
    ofPushStyle();
    ofSetColor(ofColor::fromHsb(sinf(pos.x/10) * 128 + 128, 255, 255));
    ofNoFill();

    ofDrawBox((boxSize+50) * 1.1f);
    ofPopStyle();
    
    ofPopMatrix();
    
}
//OMG 'ofImage&' pass by reference is godly
//fps jumps from 30 to 60 when i pass the actual objet and dont make a copy
void ofCube::circles(ofPoint& point,ofImage& blockImage,int loopCounter){
    
    ofPushMatrix();
    ofTranslate(pos);
    ofRotateX(pos.x);
    ofRotateY(pos.y);
    ofRotateZ(pos.z);
    
    blockImage.bind();
    ofFill();
    ofSetColor(255);
    ofDrawBox(point,boxSize+50);
    blockImage.unbind();
    
    ofPushStyle();
    ofSetColor(83,104,120);
    ofNoFill();
    
    ofDrawBox(point,(boxSize+50) * 1.1f);
    ofPopStyle();
    ofPopMatrix();
    
}

void ofCube::wordsOfWisdomCube(ofImage& blockImage,ofPoint& point)
{
    ofPushMatrix();
    //    this places the boxes in the different positions across the screen
    //    used in conjucntion with the circle code it makes for interesting
    //    orbital motions
    ofTranslate(pos);
    ofRotateX(pos.x);
    ofRotateY(pos.y);
    ofRotateZ(pos.z);
    
    blockImage.bind();
    ofFill();
    ofSetColor(255);
    ofDrawBox(point,boxSize+50);
    blockImage.unbind();
    
    ofPushStyle();
    ofSetColor(ofColor::fromHsb(sinf(pos.x/10) * 128 + 128, 255, 255));
    ofNoFill();
    
    ofDrawBox(point,(boxSize+50) * 1.1f);
    ofPopStyle();
    
    ofPopMatrix();
    
}