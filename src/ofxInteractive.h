#pragma once

#include "ofMain.h"

class ofxInteractive : public ofRectangle {
public:
    ofxInteractive();
    virtual ~ofxInteractive();

    ofxInteractive(const ofxInteractive &p);
    void mouseMoved(ofMouseEventArgs &args);
    void mousePressed(ofMouseEventArgs &args);
    void mouseDragged(ofMouseEventArgs &args);
    void mouseReleased(ofMouseEventArgs &args);

    bool clicked;
    int offsetx, offsety;

    ofEvent<int> clickedEvent;
};
