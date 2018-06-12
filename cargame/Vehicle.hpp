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

class Component;

class Vehicle : public MovingEntity
{
    //std::vector<Component> components;
    //others
    public:
        //=============================================
        //constructors
        Vehicle();
        Vehicle(const sf::Texture& entitySprite);
    
        void turnLeft(float turnDegrees);
        void turnRight(float turnDegrees);
        void brake(float brakeForce);
        void accelerate(float acceleration);
};



#endif /* Vehicle_h */
