/**
 * @file RoadLine.cpp
 * @author Anthony Eid
 */
#include "pch.h"

#include "RoadLine.h"

const int BlockLength = 40;

/**
 * Constructor to use
 * @param road The road this road line is apart of
 */
RoadLine::RoadLine(Road* road) : Item(road)
{

}


/**
 * Draw the road line
 * @param graphics
 */
void RoadLine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    int width = 1200; // will change to asking road for this
    int height = 20;

    // We want to draw a line with gaps
    // -600 is to the left and 600 is all the way to the right
    // let's make each block 40 pixels long


    // Draw a filled rectangle multiple times
    for (int i = 600 + BlockLength + mSpeed; i >= -640; i -= BlockLength * 2)
    {

        wxBrush rectBrush(*wxYELLOW);
        graphics->SetBrush(rectBrush);
        graphics->SetPen(wxNullGraphicsPen);
        graphics->DrawRectangle(i, 490, 40, 15);
    }
}


void RoadLine::Update(double elapsed)
{
    mSpeed = mSpeed + elapsed * 50;
    mSpeed = (int)mSpeed % (BlockLength * 2);
}
