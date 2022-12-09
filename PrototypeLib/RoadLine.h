/**
 * @file RoadLine.h
 * @author Anthony Eid
 *
 * Represents a yellow block line on the road
 */
#pragma once

#include "Item.h"


/**
 * Represents a yellow block on the road
 */
class RoadLine : public Item {
public:

    RoadLine(Road* road);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Update(double elapsed) override;

private:

    /// Speed the car is going
    double mSpeed = 0;

};
