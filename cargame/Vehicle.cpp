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
    changeHeading(-turnDegrees);
}

void Vehicle::turnRight(float turnDegrees) {
    changeHeading(turnDegrees);
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
    accVector2f.x = cos(getHeading()) * acceleration;
    accVector2f.y = sin(getHeading()) * acceleration;
    changeVelocity(accVector2f);
}

Vehicle::Vehicle(const sf::Texture &entitySprite): MovingEntity(entitySprite) {}
