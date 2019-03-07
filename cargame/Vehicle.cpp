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

// physics cribbed from:
// http://www.asawicki.info/Mirror/Car%20Physics%20for%20Games/Car%20Physics%20for%20Games.html
// variables needed:
//  mass
//  center of mass location
//  wheel locations
//  weight on each wheel
//  engine force
//  throttle
//  braking force

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

sf::Vector2f Vehicle::brakingForce() {
    // naive solution puts braking in direction opposite heading
    // this causes: reversing after stop, inappropriate direction if moving in reverse
    // return - unitVector(getHeading()) * brakeForce;
    
    // instead, project velocity to heading (and reverse)
    sf::Vector2f velocityBrakingVector = - proj(getVelocity(), unitVector(getHeading()));
    
    //that works for small magnitudes of velocity, but needs to be capped so we don't overbrake:
    if (magnitude(velocityBrakingVector) > 1)
        velocityBrakingVector = unitVector(velocityBrakingVector);
                                                
    return velocityBrakingVector * brakeForce;
}

sf::Vector2f Vehicle::tractionForce() {
    return unitVector(getHeading()) * engineForce * throttle;
}

sf::Vector2f Vehicle::dragForce() {
    return - getCdrag() * getVelocity() * magnitude(getVelocity());
}

sf::Vector2f Vehicle::rollingResistanceForce() {
    return - getCrr() * getVelocity();
    // maybe this should only be in direction of heading? revisit when we do cornering
}

sf::Vector2f Vehicle::longitudinalForce() {
    return (braking ? brakingForce() : tractionForce()) + dragForce() + rollingResistanceForce();
}

float Vehicle::maintenanceThrottle() {
    sf::Vector2f maintenanceForce = - proj(dragForce()+rollingResistanceForce(),unitVector(getHeading()));
    return magnitude(maintenanceForce) / engineForce;
}

void Vehicle::changeThrottle(float deltaThrottle) {
    throttle += deltaThrottle;
    if (throttle < 0.0f) throttle = 0.0f;  // maybe make minimum negative for reversing?
    if (throttle > 1.0f) throttle = 1.0f;
}

void Vehicle::setThrottle(float newThrottle) {
    throttle = newThrottle;
}

float Vehicle::getThrottle() {
    return throttle;
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
    engineForce = 4000.0f;
    braking = false;
    brakeForce = 8000.0f;
}

void Vehicle::updateLocation(sf::Time lastFrameTime) {
    //need to turn car some amount depending on wheel value
    //figure car should turn 'wheel' degrees in one car length for small values of wheel
    Entity::changeHeading(steeringWheel*magnitude(getVelocity()/getWheelBase())*lastFrameTime.asSeconds());
    
    //need to update velocity to be in direction of heading (unless skidding)
    //new velocity = projection of old velocity onto heading
//    sf::Vector2f newVelocity, headingUnitVector;
//    headingUnitVector = unitVector(getHeading());
//    newVelocity = dotProduct(getVelocity(), headingUnitVector) * headingUnitVector ;
    
    MovingEntity::changeVelocity(longitudinalForce()/getMass()*lastFrameTime.asSeconds());
    
    //finally call super's updateLocation function
    MovingEntity::updateLocation(lastFrameTime);
}

