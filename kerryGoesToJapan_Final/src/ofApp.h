#pragma once

#include "ofMain.h"
#include "ofCube.h"
#define blockAmount 40

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void cosmicWorm();
    void circleMotion();
    
    void wordsOfWisdom();
    void danceMusic();
    void baseState();
    
    int screenWidth;
    int screenHeight;
    float imageScaleWidth;
    float imageScaleHeigth;
    int backgroundWidth;
    int backgroundHeight;
    
    ofImage background;//background iamge
    ofEasyCam cam; // add mouse controls for camera movement
    
    ofSoundPlayer hoboTheme;
    
    bool bWordsOfWisdomState;
    bool bDanceMusicState;
    bool bBaseState;
    bool bCosmicWorm;
    bool bReset;
    bool bUpdateCircles;
    
    bool bHideMenu;
    bool bFrameRate;

    ofCube myCubes[blockAmount];
    ofImage portraits[blockAmount];
    
    //for the circle motion
    float angle;
    float sine;
    float cosine;
    float tangent;
    float rotationSpeed;
    
    int radius;
    ofPoint center;
    ofPoint point;
    ofPath angleArc;

};
