/**
 * @file PrototypeView.h
 * @author Anthony Eid
 */
#pragma once

#include "Prototype.h"


/**
 * View class for our prototype
 */
class PrototypeView : public wxWindow
{
public:
    void Initialize(wxFrame* parent);
    void OnTimer(wxTimerEvent &event);


private:
    /// Object that represents the whole prototype
    Prototype mPrototype;

    /// Timer for the program
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long long mTime = 0;

    void OnPaint(wxPaintEvent &event);

};



