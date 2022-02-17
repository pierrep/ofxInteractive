#pragma once

#include "ofMain.h"


class InteractionEventArgs : public ofEventArgs {

public:

    int id;
    int button;
};

class ofxInteractive : public ofRectangle {
public:
    ofxInteractive();
    virtual ~ofxInteractive();

    ofxInteractive(const ofxInteractive &p);
    void mouseMoved(ofMouseEventArgs &args);
    void mousePressed(ofMouseEventArgs &args);
    void mouseDragged(ofMouseEventArgs &args);
    void mouseReleased(ofMouseEventArgs &args);

    bool isMouseOver();
    bool isMouseDown() {return isClicked();}
    bool isClicked();
    int getId() {return id;}

    bool bMouseOver;
    bool bClicked;
    int offsetx, offsety;
    int id;

    //static ofEvent<int> clickedEvents;
    static ofEvent <InteractionEventArgs> clickedEvents;
    static int maxId;
};


