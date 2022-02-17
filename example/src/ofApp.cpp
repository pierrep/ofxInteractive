#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofTrueTypeFont myfont;
    myfont.load("nofont",14);

    for(unsigned int i=0;i < 4;i++) {
        buttons.emplace_back();
        buttons.back().set(100+i*150,100,50,30);
        buttons.back().setRoundedCorners(true);
        buttons.back().setRollOverColour(ofColor(0,255,0));
        buttons.back().setText("Button "+ofToString(i+1),myfont,ofColor(0));
    }

    ofAddListener(ofxInteractive::clickedEvents,this,&ofApp::buttonClicked);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(unsigned int i=0;i < buttons.size();i++) {
        buttons[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::buttonClicked(InteractionEventArgs & args)
{
    ofLogNotice() << "Button clicked on id = "<< args.id << ". Mouse button: " << args.button;
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
