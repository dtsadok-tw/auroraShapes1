#include "auroraShapes1.h"

//--------------------------------------------------------------
void auroraShapes1::setup(){

    color1 = ofColor(0, 0, ofRandom( 128, 255 ) );
    color2 = ofColor(ofRandom( 128, 255 ), 0, 0 );
    color3 = ofColor(0, ofRandom( 128, 255 ), ofRandom( 128, 255 ) );
    color4 = ofColor(0, 0, ofRandom( 128, 255 ) );
    
    color1.setBrightness(255);
    color2.setBrightness(255);
    color3.setBrightness(255);
    color4.setBrightness(255);
    color1.setSaturation(255);
}

//--------------------------------------------------------------
void auroraShapes1::update(){
    if (ofGetFrameNum() % 45 < 5)
        scale = 0.8;
    else
        scale = 1.0;
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

//--------------------------------------------------------------
void auroraShapes1::draw(){
    ofBackground(0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(200*scale, 200*scale);

    ofSetColor(color1);
    drawRandomCircle(0.85, 0.85);

    ofSetColor(color2);
    drawRandomCircle(0.85, 1.0);

    ofSetColor(color3);
    drawRandomCircle(1.0, 1.25);

    ofSetColor(color4);
    drawRandomCircle(1.25, 1.25);
}

//--------------------------------------------------------------
void auroraShapes1::keyPressed(int key){

}

//--------------------------------------------------------------
void auroraShapes1::keyReleased(int key){

}

//--------------------------------------------------------------
void auroraShapes1::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void auroraShapes1::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void auroraShapes1::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void auroraShapes1::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void auroraShapes1::windowResized(int w, int h){

}

//--------------------------------------------------------------
void auroraShapes1::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void auroraShapes1::dragEvent(ofDragInfo dragInfo){ 

}
