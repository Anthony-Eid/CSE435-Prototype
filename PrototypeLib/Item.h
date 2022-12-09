/**
 * @file Item.h
 * @author Anthony Eid
 *
 * Base class for item on road
 */
#pragma once

// Forward Reference
class Road;


/**
 * Base clas for an item on the road
 */
class Item {

public:
    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;

    virtual ~Item();

    virtual void Update(double elapsed) {}

    /**
     * Draw this item
     * @param dc Device context to draw on
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    void SetLocation(double x, double y) { mX = x; mY = y; }

private:


    /// The Road this item is contained in
    Road   *mRoad;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    double mSpeedX;     ///< X speed of this item
    double mSpeedY = 0; ///< Y speed of this item

protected:
    Item(Road *road);
};
