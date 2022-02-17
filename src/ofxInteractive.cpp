#include "ofxInteractive.h"

ofEvent<InteractionEventArgs> ofxInteractive::clickedEvents;
int ofxInteractive::maxId = 0;

ofxInteractive::ofxInteractive()
{
    bClicked = false;
    bMouseOver = false;
    id = maxId++;
    cout << "id = " << id << endl;

    //enable events
    ofAddListener(ofEvents().mousePressed, this, &ofxInteractive::mousePressed);
    ofAddListener(ofEvents().mouseMoved, this, &ofxInteractive::mouseMoved);
    ofAddListener(ofEvents().mouseDragged, this, &ofxInteractive::mouseDragged);
    ofAddListener(ofEvents().mouseReleased, this, &ofxInteractive::mouseReleased);
}

//--------------------------------------------------------------
ofxInteractive::~ofxInteractive()
{
    ofLogVerbose() << "ofxInteractive destructor called...";

    ofRemoveListener(ofEvents().mousePressed, this, &ofxInteractive::mousePressed);
    ofRemoveListener(ofEvents().mouseMoved, this, &ofxInteractive::mouseMoved);
    ofRemoveListener(ofEvents().mouseDragged, this, &ofxInteractive::mouseDragged);
    ofRemoveListener(ofEvents().mouseReleased, this, &ofxInteractive::mouseReleased);
}

//--------------------------------------------------------------
ofxInteractive::ofxInteractive(const ofxInteractive &parent)
{
    ofLogVerbose() << "ofxInteractive copy constructor called";

    bClicked = parent.bClicked;
    bMouseOver = parent.bClicked;
    x = parent.x;
    y = parent.y;
    width = parent.width;
    height = parent.height;
    id = parent.id;

    //enable events
    ofAddListener(ofEvents().mousePressed, this, &ofxInteractive::mousePressed);
    ofAddListener(ofEvents().mouseMoved, this, &ofxInteractive::mouseMoved);
    ofAddListener(ofEvents().mouseDragged, this, &ofxInteractive::mouseDragged);
    ofAddListener(ofEvents().mouseReleased, this, &ofxInteractive::mouseReleased);
}

//--------------------------------------------------------------
void ofxInteractive::mouseMoved(ofMouseEventArgs &args) {

    if(inside(args.x, args.y)) {
        bMouseOver = true;
    } else {
        bMouseOver = false;
    }

}

//--------------------------------------------------------------
void ofxInteractive::mousePressed(ofMouseEventArgs &args) {
    if(inside(args.x, args.y)) {
        bClicked = true;
        offsetx = x - args.x;
        offsety = y - args.y;
        InteractionEventArgs interaction;
        interaction.button = args.button;
        interaction.id = getId();
        ofNotifyEvent(clickedEvents, interaction);
    }
}

//--------------------------------------------------------------
void ofxInteractive::mouseDragged(ofMouseEventArgs &args) {
    if(bClicked) {
        setX(args.x+offsetx);
        setY(args.y+offsety);
    }
}

//--------------------------------------------------------------
void ofxInteractive::mouseReleased(ofMouseEventArgs &args) {
    bClicked = false;
}

//--------------------------------------------------------------
bool ofxInteractive::isMouseOver() {
    return bMouseOver;
}

//--------------------------------------------------------------
bool ofxInteractive::isClicked() {
    return bClicked;
}
