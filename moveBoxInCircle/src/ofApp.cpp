#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
    
	// this uses depth information for occlusion
	// rather than always drawing things on top of each other
	ofEnableDepthTest();
	
	// ofBox uses texture coordinates from 0-1, so you can load whatever
	// sized images you want and still use them to texture your box
	// but we have to explicitly normalize our tex coords here
	ofEnableNormalizedTexCoords();
	
	// loads the OF logo from disk
	ofLogo.loadImage("of.png");
	
	// draw the ofBox outlines with some weight
	ofSetLineWidth(10);
    
    
    //initial values
	angle=0;
	cosine=0;
	sine=0;
	tangent=0;
	rotationSpeed=0.09f;
	radius = 180;
	center.set(ofGetWidth()*0.3f, ofGetHeight()*0.6f, 0);
	
	ofSetCircleResolution(40);
	
	
	angleArc.setArcResolution(360);
	angleArc.setFilled(true);
	angleArc.setColor(ofColor(240, 130, 10));
}

//--------------------------------------------------------------
void ofApp::update(){
    
 
		angle+=rotationSpeed;//at each update the angle get's incremented
	
	if (angle>=TWO_PI) { //if the angle is more than or equal to two PI (a full rotation measured in Radians) then make it zero.
		angle=0;
	}
    
	//here we get the sine and cosine values for the angle
	cosine=cos(angle);
	sine=sin(angle);
	tangent=tan(angle);
	
	
	point.set(cosine * radius, sine * radius, 0);//here we set the cyan circle position
	
	//this is just to draw the arc that represents the angle
	angleArc.clear();
	angleArc.arc( 0,  0, radius * 0.5f, radius * 0.5f, 0, ofRadToDeg(angle));
	angleArc.close();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);
	
	float movementSpeed = .1;
	float cloudSize = ofGetWidth() / 2;
	float maxBoxSize = 100;
	float spacing = 1;
	int boxCount = 5;
    
    
	
	cam.begin();
	for(int i =0;i<boxCount;i++){
	
    ofPushMatrix();

    float boxSize =100;
    
    ofLogo.bind();
    ofFill();
    ofSetColor(255);
    ofDrawBox(point+(i*100),boxSize);
    ofLogo.unbind();
    
    ofNoFill();
    ofSetColor(50,50,50);
    ofDrawBox(point+(i*100),boxSize * 1.1f);
    
    ofPopMatrix();
    }
    
	cam.end();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
