//
//  MovingEntity.cpp
//  cargame
//
//  Created by Philip Routley on 6/7/18.
//  Copyright © 2018 Philip Routley. All rights reserved.
//

#include "MovingEntity.hpp"

#include <stdio.h>
#include <SFML/Graphics.hpp>


void MovingEntity::setVelocity(sf::Vector2f newVelocity) { 
    velocity = newVelocity;
}

void MovingEntity::changeVelocity(sf::Vector2f newVelocity) { 
    velocity += newVelocity;
}

sf::Vector2f MovingEntity::getVelocity() { 
    return velocity;
}

MovingEntity::MovingEntity(const sf::Texture &entitySprite): Entity(entitySprite) {}

void MovingEntity::updateLocation() { 
    changeTileLoc(velocity);
}

