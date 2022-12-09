/**
 * @file Road.cpp
 * @author Anthony Eid
 */
#include "pch.h"

#include <vector>
#include <memory>
#include <string>

#include "Road.h"

// Consts
/// Path to road image relative to Root directory
const std::wstring fileName = L"images/road.png";

/**
 * Road Constructor
 */
Road::Road() : mRoadLine(this)
{
    mRoadImage = std::make_shared<wxImage>(fileName, wxBITMAP_TYPE_ANY);
}


/**
 * Draw the road onto the graphics context
 * @param graphics
 */
void Road::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    // Lazy constructor for road bitmap
    if (mRoadBitmap.IsNull())
    {
        mRoadBitmap = graphics->CreateBitmapFromImage(*mRoadImage);
    }

    graphics->DrawBitmap(mRoadBitmap, -675, 500 - mRoadImage->GetHeight(), 1250 + mRoadImage->GetWidth(), mRoadImage->GetHeight() * 2);
    mRoadLine.Draw(graphics);

}

/**
 * Update the road
 * @param elapse The time that passed
 */
void Road::Update(double elapse)
{
    mRoadLine.Update(elapse);
}


