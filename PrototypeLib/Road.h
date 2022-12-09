/**
 * @file Road.h
 * @author Anthony Eid
 *
 *
 */

#pragma once

#include <memory>
#include <vector>

#include "RoadLine.h"

/**
 * The road in our prototype
 */
class Road {
public:

    Road();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void Update(double elapse);

private:

    /// The roads bitmap
    wxGraphicsBitmap mRoadBitmap;

    /// The item image
    std::shared_ptr<wxImage> mRoadImage;

    /// The Road Line
    RoadLine mRoadLine;

};
