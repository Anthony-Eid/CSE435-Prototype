/**
 * @file Car.cpp
 * @author Anthony Eid
 */
#include "pch.h"

#include <memory>
#include <string>

#include "Car.h"

// Consts
/// Path to Car image relative to Root directory
const std::wstring carFileName = L"images/redCar.png";

/**
 * Default constructor for car
 */
Car::Car(Road* road) : Item(road)
{
    mCarImage = std::make_shared<wxImage>(carFileName, wxBITMAP_TYPE_ANY);
}


/**
 * Draw this Car
 * @param dc The device context to draw on
 */
void Car::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    // Lazy constructor for car bitmap
    if (mCarBitmap.IsNull())
    {
        mCarBitmap = graphics->CreateBitmapFromImage(*mCarImage);
    }

    graphics->DrawBitmap(mCarBitmap, 0, 390, 130, 90);
}

void Car::Update(double elapsed)
{

}

