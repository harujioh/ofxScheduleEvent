#include "ofxScheduleEvent.h"

ofxScheduleEvent::ofxScheduleEvent(int interval) : interval(max(0, interval)) {}

void ofxScheduleEvent::addSchedule(int hour, int minute) { this->addSchedule(hour * 60 + minute); }

void ofxScheduleEvent::addSchedule(int minute) {
    if (!isThreadRunning()) {
        this->times.push_back(minute);
    }
}

void ofxScheduleEvent::threadedFunction() {
    // no times
    if (this->times.size() == 0) {
        return;
    }

    this->lastCheckAppExitMin = -1;
    while (isThreadRunning()) {
        while (isThreadRunning()) {
            if (lock()) {
                this->update();
                unlock();
                sleep(interval * 1000);
            }
        }
    }
}
void ofxScheduleEvent::update() {
    int exitMin = ofGetHours() * 60 + ofGetMinutes();
    if (this->lastCheckAppExitMin >= 0 && this->lastCheckAppExitMin == exitMin) {
        return;
    }

    // check [last checked time ~ now time]
    int startCheckExitMin = this->lastCheckAppExitMin < 0 ? exitMin : this->lastCheckAppExitMin + 1;
    this->lastCheckAppExitMin = exitMin;
    for (int min = startCheckExitMin;; min = (min + 1) % (60 * 24)) {
        for (int i = 0; i < this->times.size(); i++) {
            // app exit
            if (min == times[i]) {
                ofLogNotice("ofxScheduleEvent") << "event!";
                ofNotifyEvent(this->onEvent);
            }
        }
        if (min == exitMin) {
            return;
        }
    }
}