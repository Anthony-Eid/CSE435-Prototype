/**
 * @file Prototype.h
 * @author Anthony Eid
 *
 * Prototype Class
 */
#pragma once

#include <memory>

#include "Road.h"
#include "Car.h"

/**
 * Represents Prototype in our application
 */
class Prototype {
public:

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void Update(double elapsed);


private:

    /// The road in the prototype
    Road mRoad;

    /// The Target Vehicle
    Car mTargetVehicle = Car(&mRoad);

    double mScale; ///< Scale of virtual pixels window
    double mXOffset; ///< Offset of the X axis
    double mYOffset; ///< Offset of the Y axis
};
