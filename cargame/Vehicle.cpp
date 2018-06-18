//
//  Vehicle.cpp
//  cargame
//
//  Created by Philip Routley on 6/7/18.
//  Copyright © 2018 Philip Routley. All rights reserved.
//

#include <stdio.h>

#include "Vehicle.hpp"
#include "carMath.hpp"

// turn rate should be dependent on velocity:
// vehicle not moving, can't turn
// moving slow, turn slow
// moving fast, turn fast
// moving really fast, skid!
// probably should reduce effect of inputs at high speed to make sure steering is still possible

void Vehicle::turnLeft(float turnDegrees) {
    wheel -= turnDegrees;
    //max wheel value +/- 30 degrees
    if (wheel <= -MAX_WHEEL) wheel = -MAX_WHEEL;
}

void Vehicle::turnRight(float turnDegrees) {
    wheel += turnDegrees;
    //max wheel value +/- 30 degrees
    if (wheel >= MAX_WHEEL) wheel = MAX_WHEEL;
}

void Vehicle::straighten() {
    //wheel unwinds, moving closer to 0.0f
    //TODO: come up with better function for this
    wheel /= 1.5f;
    if (wheel <= MAX_WHEEL/10.0f) wheel = 0.0f;
}

void Vehicle::brake(float brakeForce) {
    //braking applied in direction opposite to velocity
    changeVelocity(normalizeV2f(-getVelocity())*brakeForce);
    //need to make sure velocity set to 0 if brakeForce > current velocity
}

void Vehicle::accelerate(float acceleration) {
    //acceleration applied in direction of heading;
    sf::Vector2f accVector2f;
    //find directional components of acceleration
    accVector2f.x = sin(getHeading()*degreesToRadians) * acceleration;
    accVector2f.y = -cos(getHeading()*degreesToRadians) * acceleration;
    changeVelocity(accVector2f);
}

float Vehicle::getWheel() {
    return wheel;
}

float Vehicle::getWheelBase() {
    return wheelBase;
}

Vehicle::Vehicle(const sf::Texture &entityTexture): MovingEntity(entityTexture) {
    sf::Vector2f centerOfTile(0.5f, 0.5f);
    sf::Vector2i centerOfWorld(127, 127);
    setTileLoc(centerOfTile);
    setWorldLoc(centerOfWorld);
    wheelBase = Entity::mSprite.getLocalBounds().height * Entity::mSprite.getScale().y / 256.0f;
}

void Vehicle::updateLocation() {
    //need to turn car some ammount depending on wheel value
    //figure car should turn 'wheel' degrees in one car length for small values of wheel
    Entity::changeHeading(wheel*magnitude(getVelocity()/getWheelBase()));
    
    //need to update velocity to be in direction of heading (unless skidding)
    //new velocity = projection of old velocity onto heading
    sf::Vector2f newVelocity, headingUnitVector;
    headingUnitVector = unitVector(getHeading());
    newVelocity = dotProduct(getVelocity(), headingUnitVector) * headingUnitVector;
    
    MovingEntity::setVelocity(newVelocity);
    
    //finally call super's updateLocation function
    MovingEntity::updateLocation();
}

