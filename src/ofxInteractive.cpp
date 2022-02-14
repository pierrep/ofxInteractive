#include "ofxInteractive.h"

ofxInteractive::ofxInteractive()
{
    clicked = false;

    //enable events
    ofAddListener(ofEvents().mousePressed, this, &ofxInteractive::mousePressed);
    ofAddListener(ofEvents().mouseMoved, this, &ofxInteractive::mouseMoved);
    ofAddListener(ofEvents().mouseDragged, this, &ofxInteractive::mouseDragged);
    ofAddListener(ofEvents().mouseReleased, this, &ofxInteractive::mouseReleased);
}

ofxInteractive::~ofxInteractive()
{
    ofLogVerbose() << "ofxInteractive destructor called...";

    ofRemoveListener(ofEvents().mousePressed, this, &ofxInteractive::mousePressed);
    ofRemoveListener(ofEvents().mouseMoved, this, &ofxInteractive::mouseMoved);
    ofRemoveListener(ofEvents().mouseDragged, this, &ofxInteractive::mouseDragged);
    ofRemoveListener(ofEvents().mouseReleased, this, &ofxInteractive::mouseReleased);
}

ofxInteractive::ofxInteractive(const ofxInteractive &parent)
{
    ofLogVerbose() << "ofxInteractive copy constructor called";

    clicked = parent.clicked;
    x = parent.x;
    y = parent.y;
    width = parent.width;
    height = parent.height;

    //enable events
    ofAddListener(ofEvents().mousePressed, this, &ofxInteractive::mousePressed);
    ofAddListener(ofEvents().mouseMoved, this, &ofxInteractive::mouseMoved);
    ofAddListener(ofEvents().mouseDragged, this, &ofxInteractive::mouseDragged);
    ofAddListener(ofEvents().mouseReleased, this, &ofxInteractive::mouseReleased);
}

void ofxInteractive::mouseMoved(ofMouseEventArgs &args) {
    int x = args.x;
    int y = args.y;
    int button = args.button;
}

void ofxInteractive::mousePressed(ofMouseEventArgs &args) {
    if(inside(args.x, args.y)) {
        clicked = true;
        offsetx = x - args.x;
        offsety = y - args.y;
        ofNotifyEvent(clickedEvent, args.button);
    }
}

void ofxInteractive::mouseDragged(ofMouseEventArgs &args) {
    if(clicked) {
        setX(args.x+offsetx);
        setY(args.y+offsety);
    }
}

void ofxInteractive::mouseReleased(ofMouseEventArgs &args) {
    clicked = false;
}
