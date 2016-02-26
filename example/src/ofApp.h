#pragma once

#include "ofMain.h"
#include "ofxScheduleEvent.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void exit();
    void update();
    void draw();
    
    void onEvent();
    
private:
    ofxScheduleEvent *scheduleEvent;
};
