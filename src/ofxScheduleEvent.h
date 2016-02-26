#pragma once

#include "ofMain.h"

class ofxScheduleEvent : public ofThread {
   public:
    // constructor, destructor
    ofxScheduleEvent(int interval = 1) : interval(max(0, interval)) {}
    ~ofxScheduleEvent();

    // add schedule event
    void addSchedule(int hour, int minute);
    void addSchedule(int minute);

    // thread main
    void threadedFunction();

    // event handler
    ofEvent<void> onEvent;

   private:
    int interval;
    vector<int> times;
    int lastCheckAppExitMin;

    // thread update
    void threadedUpdate();
};
