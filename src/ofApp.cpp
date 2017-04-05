#include "ofApp.h"
vector<Line> Lines;
Line::Line(){}

void Line::setup(){
    
    int a = ofRandom(0,ofGetWidth());
    int b = ofRandom(0,ofGetHeight());
    P[0]= ofPoint(a,b);
    P[1]=ofPoint(2*a,b+10);
    P[2]=ofPoint(a/2,4*b);
    P[3]=ofPoint(a+30,b);

    pos1 = ofPoint(ofGetWidth(), ofGetHeight(), 0);
    fallSpeed = ofRandom(0.5,0.9);
    fallWiggle = ofRandom(2,5);

    r = ofRandom(0,255);
    g = ofRandom(0,255);
    b = ofRandom(0,255);

    
    P0 = ofPoint(10,10);
    dim = 10;
    P1 = ofPoint(0,10);
    P2 = ofPoint(10,0);
}

void Line::update(){
    
    r = ofRandom(0,255);
    g = ofRandom(0,255);
    b = ofRandom(0,255);
    
    float time = ofGetElapsedTimef();
    
    rX1 = ofSignedNoise(time * 0.7) * 180.0;
    rY1 = ofSignedNoise(time * 0.3) * 180.0;
    rZ1 = ofSignedNoise(time * 0.5) * 180.0;
    
    rX2 = ofSignedNoise(time * 0.4) * 360.0;
    rY2 = ofSignedNoise(time * 0.7) * 360.0;
    rZ2 = ofSignedNoise(time * 0.5) * 360.0;
    
    rX3 = ofSignedNoise(time * 0.5) * 180.0;
    rY3 = ofSignedNoise(time * 0.7) * 180.0;
    rZ3 = ofSignedNoise(time * 0.4) * 180.0;
    
    float z = ofMap(ofSignedNoise(time * 0.5), -1, 1, -800, 800);
    pos1 = ofPoint(ofGetWidth(), ofGetHeight(), z);

    float x2 = ofMap(ofSignedNoise(time * 0.6), -1, 1, 0, ofGetWidth());
    float y2 = ofMap(ofSignedNoise(time * 0.5), -1, 1, 0, ofGetHeight());
    float z2 = ofMap(ofSignedNoise(time * 0.7), -1, 1, -800, 800);

    pos2 = ofPoint(x2, y2, z2);
    
    fallSpeed = ofSignedNoise(time * 0.3)*ofRandom(0.1,0.8);
    fallWiggle = ofSignedNoise(time * 0.6)*ofRandom(5,10);



    P0.x += fallWiggle * ofRandom(-1,0);
    dim = ofMap(ofSignedNoise(time * 0.5), -1, 1, 0, 20);
    P1.x += fallWiggle * ofRandom(0,1);
    P2.x += fallWiggle * ofRandom(-1,1);
}

void Line::move1(){
    
    ofTranslate(pos1);
    ofRotateX(rX1);
    ofRotateY(rY1);
    ofRotateZ(rZ1);
}

void Line::move2(){
    
    ofTranslate(pos1);
    ofRotateX(rX1);
    ofRotateY(rY1);
    ofRotateZ(rZ1);
}

void Line::move3(){

    ofTranslate(pos2);
    ofRotateX(rX3);
    ofRotateY(rY3);
    ofRotateX(rZ3);
}

void Line::move4(){

    ofTranslate(pos2);
    ofRotateX(rX1);
    ofRotateY(rY1);
    ofRotateY(rZ1);
}

void Line::draw1(){
    
    ofPushMatrix();
    move1();
    ofPushStyle();
    ofSetColor(255,255,30);
    ofDrawLine(P[2], P[3]);
    ofPopStyle();
    ofPopMatrix();
}



void Line::draw2(){
    
    ofPushMatrix();
    move2();
    ofPushStyle();
    ofSetColor(r,0,255);
    ofDrawTriangle(P[0], P[1], P[2]);
    ofPopStyle();
    ofPopMatrix();
}

void Line::draw3(){

    ofPushMatrix();
    move3();
    ofPushStyle();
    ofSetColor(255,115,0);
    ofDrawCircle(P0,dim);
    ofPopStyle();
    ofPopMatrix();
}

void Line::draw4(){
    ofPushMatrix();
    move4();
    ofPushStyle();
    ofSetColor(255,g,0);
    ofDrawEllipse(P[3], 30, 80);
    ofPopStyle();
    ofPopMatrix();
}

void Line::draw5(){

    ofPushMatrix();
    move4();
    ofPushStyle();
    ofSetColor(0,255,b);
    ofDrawCircle(P[2],dim);
    ofPopStyle();
    ofPopMatrix();
}

ofFbo fbo;
ofColor black(0,0,0);

void ofApp::add(ofPoint l1,ofPoint l2){

    Line newLine;
    newLine.P0 = l1;
    newLine.P1 = l2;
    Lines.push_back(newLine);
}

//--------------------------------------------------------------

void ofApp::setup(){
    
    myLine.setup();
    myTriangle.setup();
    myCircle1.setup();
    myEllipse.setup();
    myCircle2.setup();
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    ofSetBackgroundColor(black);

}



//--------------------------------------------------------------

void ofApp::update(){
    
    myLine.update();
    myTriangle.update();
    myCircle1.update();
    myEllipse.update();
    myCircle2.update();
}



//--------------------------------------------------------------

void ofApp::draw(){
    
    fbo.begin();
    ofPushStyle();
    ofSetColor(0,0,0,1);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();
    
    myLine.draw1();
    myTriangle.draw2();
    myCircle1.draw3();
    myCircle2.draw4();
    myEllipse.draw5();
    
    fbo.end();
    fbo.draw(0,0);
    
}



//--------------------------------------------------------------

void ofApp::keyPressed(int key){
    
    
    
}



//--------------------------------------------------------------

void ofApp::keyReleased(int key){
    
    
    
}



//--------------------------------------------------------------

void ofApp::mouseMoved(int x, int y ){
    
    
    
}



//--------------------------------------------------------------

void ofApp::mouseDragged(int x, int y, int button){
    
    
    
}



//--------------------------------------------------------------

void ofApp::mousePressed(int x, int y, int button){
    
    add(ofPoint(-20,0),ofPoint(20,0));
    
}



//--------------------------------------------------------------

void ofApp::mouseReleased(int x, int y, int button){
    
    
    
}



//--------------------------------------------------------------

void ofApp::mouseEntered(int x, int y){
    
    
    
}



//--------------------------------------------------------------

void ofApp::mouseExited(int x, int y){
    
    
    
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
