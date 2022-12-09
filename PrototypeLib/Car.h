/**
 * @file Car.h
 * @author Anthony Eid
 *
 * Represents a car in the Prototype
 */
#pragma once

#include "Item.h"

class Road;

/**
 * Represents a Car in prototype
 */
class Car : Item {
public:
    /// Default constructor disable
    Car() = delete;

    /// Default constructor to use
    Car(Road* road);

    /// Copy constructor (disabled)
    Car(const Car &) = delete;

    /// Assignment operator
    void operator=(const Car &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update(double elapsed) override;


private:

    /// The roads bitmap
    wxGraphicsBitmap mCarBitmap;

    /// The item image
    std::shared_ptr<wxImage> mCarImage;

    /// Car's speed
    double mSpeed = 35;
};
