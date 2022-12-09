//
// Created by Anthony Eid on 12/8/22.
//
#include "pch.h"

#include <wx/dcbuffer.h>

#include "PrototypeView.h"

/// Frame duration in milliseconds
const int FrameDuration = 120;

/**
 * Initialize the Prototype view class.
 * @param parent The parent window for this class
 */
void PrototypeView::Initialize(wxFrame *parent)
{
    Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    // Events
    Bind(wxEVT_PAINT, &PrototypeView::OnPaint, this);
    Bind(wxEVT_TIMER, &PrototypeView::OnTimer, this);

    // Start timer and tell frame
    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}

void PrototypeView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void PrototypeView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    // Since the last call to OnPaint
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime -mTime) * 0.001;
    mTime = newTime;

    // Update objects in prototype to reflex time that passed
    mPrototype.Update(elapsed);

    // Double buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear image to white
    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    wxRect rect = GetRect();
    mPrototype.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
}

