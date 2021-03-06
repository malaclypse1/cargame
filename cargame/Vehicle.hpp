//
//  Vehicle.hpp
//  cargame
//
//  Created by Philip Routley on 3/25/17.
//  Copyright © 2017 Philip Routley. All rights reserved.
//

#ifndef Vehicle_h
#define Vehicle_h

#include "Entity.hpp"
#include "MovingEntity.hpp"
#include "carMath.hpp"

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>

const float MAX_WHEEL = 30.0f;

class Component;

class Vehicle : public MovingEntity
{
    //std::vector<Component> components;
    //others
public:
    //=============================================
    //constructors
    Vehicle();
    Vehicle(const sf::Texture& entityTexture);
    
    void turnLeft(float turnDegrees);
    void turnRight(float turnDegrees);
    void straighten();
    void brake(float brakeForce);
    void accelerate(float acceleration);
    void updateLocation();
    float getWheel();
    float getWheelBase();
    
private:
    float baseAcceleration;
    float baseBrakeForce;
    float baseTurnRate;
    float wheel;            //relative direction of wheels to heading
    float wheelBase;        //should be roughly length of car/tile size
};



#endif /* Vehicle_h */
