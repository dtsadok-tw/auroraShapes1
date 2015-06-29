#pragma once

#include "ofMain.h"

class auroraShapes1 : public ofBaseApp{

	public:
    float scale = 1.0;
    ofColor color1, color2, color3, color4;
    int currentScene = 0;

    const int sceneTimes[4] = {0, 1500, 3000, 4500};

    void setup();
    void update();
    void draw();

    void beat();
    void drawCircles();
    void drawPattern();
    void setupAudio();

    //scenes
    void drawScene1();
    void drawScene2();
    void drawScene3();
    
    // audio sources
    ofSoundPlayer aviPlayer;
    ofSoundPlayer sofyPlayer;
    ofSoundPlayer danPlayer;
    ofSoundPlayer normPlayer;

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void drawRandomCircle(float rx, float ry);
    void drawArc12(int radius, int start, int end);
    
};
