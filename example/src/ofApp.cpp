#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofxScheduleEvent *scheduleEvent = new ofxScheduleEvent(2);
    scheduleEvent->addSchedule(0, 20);
    scheduleEvent->addSchedule(0, 21);
    scheduleEvent->startThread();
    
    ofAddListener(scheduleEvent->onEvent, this, &ofApp::onEvent);
}

//--------------------------------------------------------------
void ofApp::onEvent() { ofLogNotice() << "onEvent!!"; }

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {}
