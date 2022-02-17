#pragma once

#include "ofxInteractive.h"


class ofxButton: public ofxInteractive {
    public:
        void setRoundedCorners(bool value) {bRoundedCorners = value;}
        void setColour(ofColor c) {bgColour = c;}
        void setPadding(int p) {padding = p;}
        void setVerticalPadding(int p) {vpadding = p;}
        void setRollOverColour(ofColor c) {rollOverColour = c;}
        void setText(string s, ofTrueTypeFont& _font,ofColor c) {
            textColour = c;
            font = _font;
            text = s;
            textWidth = font.getStringBoundingBox(text,position.x,position.y).getWidth();
            textHeight = font.getStringBoundingBox(text,position.x,position.y).getHeight();
            ofLogNotice() << "beforeText() height:" << getHeight() << " textHeight: " << textHeight;
            if(getHeight() < (textHeight+vpadding*2)){
                setHeight(textHeight+vpadding*2);
            }
            setWidth(textWidth+padding*2);
            ofLogNotice() << "setText() height:" << getHeight() << " textHeight: " << textHeight;
        }
        void setCentred() {
            position.x = position.x - getWidth()/2.0f;
        }

        void draw() {
            ofPushStyle();

            if(isMouseOver()) {
                ofSetColor(rollOverColour);
            } else {
                ofSetColor(bgColour);
            }
            if(bRoundedCorners) {
                ofDrawRectRounded(position.x,position.y,width,height,5);
            } else {
                ofDrawRectangle(position.x,position.y,width,height);
            }

            ofSetColor(textColour);

            if(font.isLoaded()) {
//                font.drawString(text,position.x + padding, position.y + getHeight()/2.0f + padding);
                  font.drawString(text,position.x + padding, position.y + getHeight() - textHeight/2.0f);
            }

            ofPopStyle();
        }


    private:
        ofTrueTypeFont font;
        ofColor bgColour;
        ofColor rollOverColour;
        ofColor textColour;
        string text;
        int textWidth;
        int textHeight;
        int padding = 10;
        int vpadding = 5;
        bool bRoundedCorners;
    };
