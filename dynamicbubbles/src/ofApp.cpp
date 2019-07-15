#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackgroundHex(0xffffff);
    ofSetLogLevel(OF_LOG_NOTICE);
    
    box2d.init();
    box2d.setGravity(0, 0);
    box2d.createBounds();
    box2d.setFPS(60.0);
    box2d.registerGrabbing();
    
    upGravityButton.set(50, 50, 100, 50);
    downGravityButton.set(155, 50, 100, 50);
    helpButton.set(50, 670, 135, 50);
    
    upGravityButtonClicked = false;
    downGravityButtonClicked = false;
    helpButtonClicked = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
    
    if (upGravityButtonClicked) {
        downGravityButtonClicked = false;
        box2d.setGravity(0, -5);
    } else if (downGravityButtonClicked) {
        upGravityButtonClicked = false;
        box2d.setGravity(0, 5);
    } else {
        upGravityButtonClicked = false;
        downGravityButtonClicked = false;
        box2d.setGravity(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //shapes
    for (int i = 0; i < bubbles.size(); i++) {
        ofSetHexColor(hexColors[bubbleColors[i]]);
        ofFill();
        bubbles[i].get()->draw();
    }
    
    for (int i = 0; i < squares.size(); i++) {
        ofSetHexColor(0xcdd4d8);
        ofFill();
        squares[i].get()->draw();
    }
    
    for (int i = 0; i < stars.size(); i++) {
        ofSetHexColor(0xe0baf2);
        ofFill();
        stars[i].get()->draw();
    }
    
    for (int i = 0; i < poems.size(); i++) {
        ofSetColor(ofColor::lightCoral);
        ofDrawBitmapString(poemCollection[poems[i]], poemLocations[i].first, poemLocations[i].second);
    }
    
    //buttons
    ofFill();
    if (upGravityButtonClicked) ofSetHexColor(0xf29393);
    else ofSetHexColor(0xf7c0c0);
    ofRectRounded(upGravityButton, 5, 5, 5, 5);
    
    if (downGravityButtonClicked) ofSetHexColor(0xf29393);
    else ofSetHexColor(0xf7c0c0);
    ofRectRounded(downGravityButton, 5, 5, 5, 5);
    
    
    //legend
    string info = "";
    if (helpButtonClicked) {
        ofSetHexColor(0xbbe1f7);
        ofRectRounded(helpButton, 5, 5, 5, 5);
        
        info =
        "key controls\n"
        "[1] bubbles\n"
        "[2] squares\n"
        "[3] poems\n"
        "[t] toggle\n"
        "[x] clear";
        
        ofSetHexColor(0x6d6a67);
        ofDrawBitmapString(info, 67, 580);
        
    } else {
        ofSetHexColor(0xe0f0f9);
        ofRectRounded(helpButton, 5, 5, 5, 5);
        
        info = "";
        ofSetHexColor(0x6d6a67);
        ofDrawBitmapString(info, 67, 580);
    }
    
    string up = "up";
    string down = "down";
    string help = "help";
    
    ofSetHexColor(0x6d6a67);
    ofDrawBitmapString(up, 92, 80);
    ofDrawBitmapString(down, 186, 80);
    ofDrawBitmapString(help, 102, 698);
    
    //ground
    box2d.drawGround();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        int randomColor = ofRandom(0, hexColors.size());
        bubbleColors.push_back(randomColor);
        
        float r = ofRandom(40, 60);
        bubbles.push_back(shared_ptr<bubble>(new bubble));
        bubble *bubble = bubbles.back().get();
        bubble->setPhysics(2.0, 0.6, 0);
        bubble->setup(box2d.getWorld(), mouseX, mouseY, r);
    }
    
    if (key == '2') {
        float l = ofRandom(20, 40);
        squares.push_back(shared_ptr<ofxBox2dRect>(new ofxBox2dRect));
        squares.back().get()->setPhysics(4.0, 0.6, 0.5);
        squares.back().get()->setup(box2d.getWorld(), mouseX, mouseY, l, l);
    }
    
    if (key == '3') {
        int randomPoem = ofRandom(0, poemCollection.size());
        poems.push_back(randomPoem);
        poemLocations.push_back(std::make_pair(mouseX, mouseY));
    }
    
    if (key == '4') {
        stars.push_back(shared_ptr<star>(new star));
        stars.back().get()->setPhysics(1.5, 0.25, 0.1);
        stars.back().get()->setup(box2d.getWorld(), mouseX, mouseY);
    }
    
    if (key == 't') {
        ofToggleFullscreen();
    }
    
    if (key == 'x') {
        bubbles.clear();
        poems.clear();
        squares.clear();
    }
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
    //https://gist.github.com/firmread/10641924
    if (upGravityButton.inside(x, y)) {
        upGravityButtonClicked = !upGravityButtonClicked;
    }
    
    if (downGravityButton.inside(x, y)) {
        downGravityButtonClicked = !downGravityButtonClicked;
    }
    
    if (helpButton.inside(x, y)) {
        helpButtonClicked = !helpButtonClicked;
    }
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
