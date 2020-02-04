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

void MovingEntity::changeVelocity(sf::Vector2f addVelocity) {
    velocity += addVelocity;
}

void MovingEntity::setAngularVelocity(float newAngularVelocity) {
    angularVelocity = newAngularVelocity;
}

void MovingEntity::changeAngularVelocity(float addAngularVelocity) {
    angularVelocity += addAngularVelocity;
}


sf::Vector2f MovingEntity::getVelocity() { 
    return velocity;
}

MovingEntity::MovingEntity(const sf::Texture &entityTexture): Entity(entityTexture) {
    Cdrag = 0.4257f;
    Crr = 12.8f;
    mass = 1000.0f;
    inertia = 20.0f/12.0f * mass; //4m x 2m car: 4^2 + 2^2 = 20
    angularVelocity = 0.0f; //rads/s
}

void MovingEntity::updateLocation(sf::Time lastFrameTime) { 
    changeTileLoc(getVelocity() * lastFrameTime.asSeconds());
}

float MovingEntity::getCdrag() { 
    return Cdrag;
}

float MovingEntity::getCrr() { 
    return Crr;
}

float MovingEntity::getMass() {
    return mass;
}

float MovingEntity::getInertia() {
    return inertia;
}

float MovingEntity::getAngularVelocity() {
    return angularVelocity;
}


