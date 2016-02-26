#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    scheduleEvent = new ofxScheduleEvent(2);
    scheduleEvent->addSchedule(0, 20);
    scheduleEvent->addSchedule(0, 21);
    scheduleEvent->startThread();
    
    ofAddListener(scheduleEvent->onEvent, this, &ofApp::onEvent);
}

//--------------------------------------------------------------
void ofApp::exit() { delete scheduleEvent; }

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {}

void ofApp::onEvent() { ofLogNotice() << "onEvent!!"; }