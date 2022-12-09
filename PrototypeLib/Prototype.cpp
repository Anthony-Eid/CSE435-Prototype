/**
 * @file Prototype.cpp
 * @author Anthony Eid
 */
#include "pch.h"

#include "Prototype.h"

// Consts
/// Prototype width in virtual pixels
const static int Width = 1250;

/// Prototype height in virtual pixels
const static int Height = 1000;


/**
 * Draw the Prototype area
 * @param graphics The graphics context to draw on
 * @param width Width of the client window
 * @param height Height of the client window
 */
void Prototype::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(Width);
    auto scaleY = double(height) / double(Height);
    mScale = std::min(scaleX, scaleY);

    mXOffset = width / 2;
    mYOffset = 0;

    if (height > Height * mScale) {
        mYOffset = (float)((height - Height * mScale) / 2);
    }

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(scaleX, scaleY);

    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT YOUR DRAWING CODE HERE
    mRoad.Draw(graphics);
    mTargetVehicle.Draw(graphics);

    graphics->PopState();
}



/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Prototype::Update(double elapsed)
{
    mTargetVehicle.Update(elapsed);
    mRoad.Update(elapsed);
}


