/**
 * @file Item.cpp
 * @author Anthony Eid
 */
#include "pch.h"

#include "Item.h"
#include "Road.h"


/**
 * Constructor
 * @param road The road this item is on
 */
Item::Item(Road *road) : mRoad(road)
{

}

/**
 * Destructor
 */
Item::~Item() {

}


