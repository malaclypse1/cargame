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
    steeringWheel -= turnDegrees;
    //max wheel value +/- 30 degrees
    if (steeringWheel <= -MAX_WHEEL) steeringWheel = -MAX_WHEEL;
}

void Vehicle::turnRight(float turnDegrees) {
    steeringWheel += turnDegrees;
    //max wheel value +/- 30 degrees
    if (steeringWheel >= MAX_WHEEL) steeringWheel = MAX_WHEEL;
}

void Vehicle::straighten() {
    //wheel unwinds, moving closer to 0.0f
    //TODO: come up with better function for this
    steeringWheel /= 1.5f;
    if (steeringWheel <= MAX_WHEEL/10.0f) steeringWheel = 0.0f;
}

void Vehicle::brake(float brakeForce) {
    //braking applied in direction opposite to velocity
    if (magnitude(getVelocity()) > magnitude(tractionForce(-brakeForce)/getMass())) {
        changeVelocity(longitudinalForce(-brakeForce)/getMass());
    }
    else {
        setVelocity(zeroVector);
    }
    //need to make sure velocity set to 0 if brakeForce > current velocity
    //TODO: figure out backing up
}

sf::Vector2f Vehicle::tractionForce(float engineForce) {
    return unitVector(getHeading()) * engineForce;
}

sf::Vector2f Vehicle::dragForce() {
    return - getCdrag() * getVelocity() * magnitude(getVelocity());
}

sf::Vector2f Vehicle::rollingResistanceForce() {
    return - getCrr() * getVelocity();
}

sf::Vector2f Vehicle::longitudinalForce(float engineForce) {
    return tractionForce(engineForce) + dragForce() + rollingResistanceForce();
}

void Vehicle::accelerate(float acceleration) {
    changeVelocity(longitudinalForce(acceleration)/getMass());
}

float Vehicle::getWheel() {
    return steeringWheel;
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
    //need to turn car some amount depending on wheel value
    //figure car should turn 'wheel' degrees in one car length for small values of wheel
    Entity::changeHeading(steeringWheel*magnitude(getVelocity()/getWheelBase()));
    
    //need to update velocity to be in direction of heading (unless skidding)
    //new velocity = projection of old velocity onto heading
    sf::Vector2f newVelocity, headingUnitVector;
    headingUnitVector = unitVector(getHeading());
    newVelocity = dotProduct(getVelocity(), headingUnitVector) * headingUnitVector;
    
    MovingEntity::setVelocity(newVelocity);
    
    //finally call super's updateLocation function
    MovingEntity::updateLocation();
}

