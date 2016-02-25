#pragma once

#include "ofMain.h"

class ofxScheduleEvent : public ofThread {
   public:
    ofxScheduleEvent(int interval = 1);

    void addSchedule(int hour, int minute);
    void addSchedule(int minute);

    void threadedFunction();
    void update();

    ofEvent<void> onEvent;

   private:
    int interval;
    vector<int> times;
    int lastCheckAppExitMin;
};
