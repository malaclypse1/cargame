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

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>

class Component;

class Vehicle : public MovingEntity
{
    std::vector<Component> components;
};

#endif /* Vehicle_h */
