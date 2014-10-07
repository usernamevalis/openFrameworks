#pragma once

#include "ofMain.h"

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
    
    ofImage ofLogo; // the OF logo
    ofLight light; // creates a light and enables lighting
    ofEasyCam cam; // add mouse controls for camera movement
    
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