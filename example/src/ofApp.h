#pragma once

#include "ofMain.h"
#include "ofxInteractive.h"

class ofxButton: public ofxInteractive {
public:
    void draw() {
        ofDrawRectRounded(position.x,position.y,0,width,height,5);
    };
};

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

        void buttonClicked(int & value);
		
        ofxButton button;
};
