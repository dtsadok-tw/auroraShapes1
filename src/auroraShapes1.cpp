#include "auroraShapes1.h"

void auroraShapes1::setup(){

    white = ofColor(255, 255, 255);
    color1 = ofColor(64, 64, ofRandom( 128, 255 ) );
    color2 = ofColor(ofRandom( 128, 255 ), 64, 64 );
    color3 = ofColor(64, ofRandom( 128, 255 ), ofRandom( 128, 255 ) );
    color4 = ofColor(64, 64, ofRandom( 128, 255 ) );
    setupAudio();
}

void auroraShapes1::setupAudio(){
    aviPlayer.loadSound("sounds/Avi Heart#03.aif");
    aviPlayer.setVolume(1.0f);
    aviPlayer.setMultiPlay(false);
//    aviPlayer.setPosition(0.1);
    
    sofyPlayer.loadSound("sounds/Sofy Heart#01.aif");
    sofyPlayer.setVolume(1.0f);
    sofyPlayer.setMultiPlay(false);
//    sofyPlayer.setPosition(0.5);
    
    danPlayer.loadSound("sounds/Pedro Heart#05.aif");
    danPlayer.setVolume(1.0f);
    danPlayer.setMultiPlay(false);
    
    normPlayer.loadSound("sounds/Norm#02.aif");
    normPlayer.setVolume(1.0f);
    normPlayer.setMultiPlay(false);

}

void auroraShapes1::update(){
    beat();

    int newScene = getSceneNumber();

    if (newScene != currentScene) //transition?
    {
        //triggerAudioFor(newScene);
        currentScene = newScene;
        triggerAudio(newScene);
    }
}

void auroraShapes1::draw(){
    ofBackground(0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //ofScale(50*scale, 50*scale);
    //ofScale(50, 50);

    switch (currentScene) {
        case 1:
            drawScene1();
            break;

        case 2:
            drawScene2();
            break;

        case 3:
            drawScene3();
            break;

        case 4:
            drawScene4();
            break;

        default:
            ofBackground(0);
            break;
    }
}

//simulate heartbeat
void auroraShapes1::beat(){
    if (ofGetFrameNum() % 45 < 5)
        scale = 0.95;
    else
        scale = 1.00;
}

int auroraShapes1::getSceneNumber(){
    int sceneTimesLength = sizeof(sceneTimes)/sizeof(sceneTimes[0]);
    for (int i=sceneTimesLength-1; i >= 0; i--)
    {
        if (ofGetElapsedTimeMillis() >= sceneTimes[i])
            return i;
    }
}

void auroraShapes1::drawScene1(){
    ofBackground(0);
    ofSetColor(white);

    ofPolyline line;
    int radius = 80*scale;
    line.arc(0, 0, radius, radius, 0, 360, 100);
    line.draw();
}

void auroraShapes1::drawScene2(){
    ofBackground(color2);
    ofSetColor(white);

    int radius = 40*scale;
    ofPolyline circle1, circle2;
    circle1.arc(2*radius, 2*radius, radius, radius, 0, 360, 100);
    circle1.draw();
    circle2.arc(-2*radius, -2*radius, radius, radius, 0, 360, 100);
    circle2.draw();
}

void auroraShapes1::drawScene3(){
    ofBackground(color3);
    ofSetColor(white);

    int numCircles = 4;
    int radius = 25*scale;
    int centers[4][2] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

    for (int i=0; i< numCircles; i++)
    {
        ofPolyline circle;
        circle.arc(centers[i][0]*4*radius, centers[i][1]*4*radius,
                   radius, radius, 0, 360, 100);
        circle.draw();
    }
}

void auroraShapes1::drawScene4(){
    ofSetColor(0);
}

void auroraShapes1::drawRandomCircle(float r0, float r1) {
    ofPolyline line;

    for (float j=0; j < TWO_PI+0.1; j+= 0.05) {
        float r = ofRandom(r0, r1);
        float x = r * cos(j);
        float y = r * sin(j);
        
        //line.addVertex(x, y); //pointy
        line.curveTo(x, y); //curvy
    }
    
    line.draw();
}

//start, end: 0-11 (end > start)
void auroraShapes1::drawArc12(int radius, int start, int end) {
    ofPolyline line;
    
    float rscale = 1/15.0;
    
    float angleBegin = 0, angleEnd = 0;
    if (start != 12) angleBegin = (start * 360/12) % 360;
    if (end   != 12) angleEnd   = (end   * 360/12) % 360;

    line.arc(0, 0, radius * rscale, radius * rscale, angleBegin, angleEnd, 100);
    line.draw();
}

void auroraShapes1::drawCircles(){
    ofSetColor(color1);
    drawRandomCircle(0.85, 0.85);
    
    ofSetColor(color2);
    drawRandomCircle(0.85, 1.0);
    
    ofSetColor(color3);
    drawRandomCircle(1.0, 1.25);
    
    ofSetColor(color4);
    drawRandomCircle(1.25, 1.25);
}

void auroraShapes1::drawPattern(){
    int last = 0;
    int digits[] = {3, 1, 4, 1, 5, 9};
    for (int i=0; i < 7; i++)
    {
        int start = last;
        int end = (last+digits[i]); // % 12;
        last = end;
        
        drawArc12(i+1, start, end);
    }
}

void auroraShapes1::triggerAudio(int sceneNum){
    switch (sceneNum) {
        case 1:
            sofyPlayer.play();
            break;
        case 2:
            danPlayer.play();
            break;
        case 3:
            aviPlayer.play();
            break;
        case 4:
            normPlayer.play();
            break;
        default:
            break;
    }
}

void auroraShapes1::gotMessage(ofMessage msg){

}
