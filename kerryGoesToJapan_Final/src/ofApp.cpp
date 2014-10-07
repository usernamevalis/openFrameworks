#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofSetDataPathRoot("../Resources/data/");
    
    ofSetBackgroundAuto(true);
    
    background.loadImage("background.png");
	ofSetVerticalSync(true);
    // draw the ofBox outlines with some weight
	ofSetLineWidth(7);
    
    //load images
    for(int i=0; i < blockAmount;i++)
    {
        portraits[i].loadImage(ofToString(i)+".jpg");
    }
    
    
    backgroundWidth = background.getWidth();
    backgroundHeight = background.getHeight();
    
    hoboTheme.loadSound("sounds/music/hobo.wav");
    hoboTheme.setLoop(true);
    
    bBaseState = true;
    bCosmicWorm=false;
    bWordsOfWisdomState = false;
    bDanceMusicState = false;
    bUpdateCircles = false;
    
    bReset = false;
    
    bHideMenu = false;
    bFrameRate = false;
    
    //initial values
	angle=0;
	cosine=0;
	sine=0;
	tangent=0;
	rotationSpeed=0.09f;
	radius = 180;
	center.set(ofGetWidth()*0.3f, ofGetHeight()*0.6f, 0);
    
    ofSetFrameRate(60);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(0);
    ofSoundUpdate();
    
    screenWidth = ofGetWidth();
    screenHeight=ofGetHeight();
    float scale = (screenWidth/background.getWidth())*0.4;
    imageScaleWidth = backgroundWidth*scale;
    imageScaleHeigth = backgroundHeight*scale;
    
    if(bUpdateCircles){
        
        circleMotion();
    }else if (!bUpdateCircles){
        
        
        for(int i = 0 ; i<blockAmount;i++)
        {
            myCubes[i].update(i);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(hoboTheme.getPosition() == 0){
        hoboTheme.play();
    }
    
    if(bBaseState){
        
        baseState();
    }
    
    if (bDanceMusicState){
        
        danceMusic();
	}
    
    if(bWordsOfWisdomState){
        
        wordsOfWisdom();
    }
    
    if (bCosmicWorm) {
        
        cosmicWorm();
    }
    
    //hobosong
    
    if (!bHideMenu) {
        
        
        stringstream hud;
        if(bFrameRate){
        hud << "Framerate: " << ofToString(ofGetFrameRate(),0) << "\n";
        }
        hud << "Keyboard Shortcuts:"<<endl<<endl;
        hud << "(f): Toggle Fullscreen"<<endl<<"(1) (2) (3) (4): Change Box Movements"<<endl<<"(h): Hide this menu"<<endl<<endl;
        hud << "Left click drag to orbit the target"<< endl<<"Right click drag to zoom in and out"<<endl<<"Double click to reset camera position"<<endl;
        ofDrawBitmapString(hud.str().c_str(), 20, 20);
        
    }
}


void ofApp::baseState()
{
     background.draw(((ofGetWidth() - imageScaleWidth)+10), ((ofGetHeight()-imageScaleHeigth)+10),imageScaleWidth,imageScaleHeigth);    ofEnableDepthTest();
    ofEnableNormalizedTexCoords();
    
    cam.begin();
    
    for(int i = 0 ; i<blockAmount;i++)
    {
        myCubes[i].movementSpeed = 0.06;
        myCubes[i].spacing=1.5;
        myCubes[i].draw(portraits[i]);
    }
    
    cam.end();
    
    ofDisableNormalizedTexCoords();
    ofDisableDepthTest();
    
}

void ofApp::wordsOfWisdom(){
    
    ofEnableDepthTest();
    ofEnableNormalizedTexCoords();
    
    cam.begin();
    
    for(int i = 0 ; i<blockAmount;i++)
    {
        myCubes[i].movementSpeed = 0.08;
        myCubes[i].spacing=1;
        myCubes[i].wordsOfWisdomCube(portraits[i],point);
    }
    
    cam.end();
    
    ofDisableNormalizedTexCoords();
    ofDisableDepthTest();
    
    background.draw(((ofGetWidth() - imageScaleWidth)+10), ((ofGetHeight()-imageScaleHeigth)+10),imageScaleWidth,imageScaleHeigth);

    
}

void ofApp::danceMusic()
{
   background.draw(((ofGetWidth() - imageScaleWidth)+10), ((ofGetHeight()-imageScaleHeigth)+10),imageScaleWidth,imageScaleHeigth);
    ofEnableDepthTest();
    ofEnableNormalizedTexCoords();
    
    cam.begin();
    
    for(int i = 0 ; i<blockAmount;i++)
    {
        
        myCubes[i].movementSpeed = 0.01;
        myCubes[i].spacing=1;
        myCubes[i].wordsOfWisdomCube(portraits[i], point);
    }
    
    cam.end();
    
    ofDisableNormalizedTexCoords();
    ofDisableDepthTest();
    
}

void ofApp::cosmicWorm(){
    
  background.draw(((ofGetWidth() - imageScaleWidth)+10), ((ofGetHeight()-imageScaleHeigth)+10),imageScaleWidth,imageScaleHeigth);
    ofEnableDepthTest();
    ofEnableNormalizedTexCoords();
    
    cam.begin();
    
    for(int i = 0 ; i<blockAmount;i++)
    {
        
        myCubes[i].movementSpeed = 0.06;
        myCubes[i].spacing=100;
        myCubes[i].wordsOfWisdomCube(portraits[i], point);
        
    }
    
    cam.end();
    
    ofDisableNormalizedTexCoords();
    ofDisableDepthTest();
    
}

void ofApp::circleMotion(){
    
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
void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case '1':
            bUpdateCircles = true;
            
            bDanceMusicState=true;
            bWordsOfWisdomState=false;
            bBaseState = false;
            bCosmicWorm = false;
            break;
        case '2':
            bUpdateCircles = false;
            
            bWordsOfWisdomState=true;
            bBaseState = false;
            bDanceMusicState=false;
            bCosmicWorm = false;
            break;
        case '3':
            bUpdateCircles = false;
            
            bBaseState = true;
            bReset = true;
            
            bWordsOfWisdomState=false;
            bDanceMusicState=false;
            bCosmicWorm = false;
            break;
        case '4':
            bUpdateCircles = false;
            
            bCosmicWorm = true;
            bReset = true;
            
            bBaseState = false;
            bWordsOfWisdomState=false;
            bDanceMusicState=false;
            break;
        case 'h':
            bHideMenu =! bHideMenu;
        case 'r':
            bFrameRate =! bFrameRate;

    }
}

//--------------------------------------------------------------

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

