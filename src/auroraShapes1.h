#pragma once

#include "ofMain.h"

class auroraShapes1 : public ofBaseApp{

	public:
    float scale = 1.0;
    ofColor white, color1, color2, color3, color4;
    int currentScene = 0;

    const int sceneTimes[5] = {0, 1000, 3000, 6000, 9000};

    void setup();
    void update();
    void draw();

    //scenes
    int getSceneNumber();
    void drawScene1();
    void drawScene2();
    void drawScene3();
    void drawScene4();
    
    // audio sources
    ofSoundPlayer aviPlayer;
    ofSoundPlayer sofyPlayer;
    ofSoundPlayer danPlayer;
    ofSoundPlayer normPlayer;
    
    void setupAudio();
    void triggerAudio(int sceneNum);

    void beat();
    void drawCircles();
    void drawPattern();
    void drawRandomCircle(float rx, float ry);
    void drawArc12(int radius, int start, int end);


    void gotMessage(ofMessage msg);
    
};
