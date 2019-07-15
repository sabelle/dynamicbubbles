#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "shapes.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	
private:
    ofxBox2d box2d; //box2d world
    std::vector<shared_ptr<bubble> > bubbles;
    std::vector<shared_ptr<ofxBox2dRect> > squares;
    std::vector<shared_ptr<star> > stars;
    std::vector<int> poems;
    std::vector<int> bubbleColors;
    std::vector<std::pair<int, int> > poemLocations;
    std::vector<unsigned> hexColors {0xebdcf2, 0xf4df8b, 0xbbf7e3};
    std::vector<string> poemCollection {
        "seeker of truth\n\n"
        "follow no paths\n"
        "all paths lead where\n\n"
        "truth is here",
        
        "love is a place\n"
        "& through this place of\n"
        "love move\n"
        "(with brightness of peace)\n"
        "all places\n\n"
        "yes is a world\n"
        "& in this world of\n"
        "yes live\n"
        "(skillfully curled)\n"
        "all worlds",
        
        "a total stranger one black day\n"
        "knocked living the hell out of me–\n\n"
        "who found forgiveness hard because\n"
        "my(as it happened)self he was\n\n"
        "-but now that fiend and i are such\n"
        "immortal friends the other’s each",
        
        "Me up at does\n\n"
        "out of the floor\n"
        "quietly Stare\n\n"
        "a poisoned mouse\n\n"
        "still who alive\n\n"
        "is asking What\n"
        "have i done that\n\n"
        "You wouldn't have"
    };
    
    ofRectangle upGravityButton;
    ofRectangle downGravityButton;
    ofRectangle legend;
    ofRectangle helpButton;
    bool upGravityButtonClicked;
    bool downGravityButtonClicked;
    bool helpButtonClicked;
};
