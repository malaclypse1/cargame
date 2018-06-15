//
//  Entity.cpp
//  cargame
//
//  Created by Philip Routley on 6/14/16.
//  Copyright © 2016 Philip Routley. All rights reserved.
//

#include "Entity.hpp"

#include <stdio.h>
#include <SFML/Graphics.hpp>

void Entity::init() {
    
}
Entity::Entity(const sf::Texture& entityTexture) {
    Entity();
    mSprite.setTexture(entityTexture);
    //origin set to center, but consider using center of mass or center of rear axle
    mSprite.setOrigin(mSprite.getLocalBounds().width/2,mSprite.getLocalBounds().height/2);
    mSprite.setScale(sf::Vector2f(0.2f,0.2f));
    mSprite.setPosition(800.0f,600.0f);
}
void Entity::draw(sf::RenderWindow& win) {
    mSprite.setRotation(heading);
    win.draw(mSprite);
}

Entity::Entity() { 
    heading = 0.0f;
    worldLoc.x = 127;
    worldLoc.y = 127;
    tileLoc.x = 0.5f;
    tileLoc.y = 0.5f;
}


float Entity::getHeading() { 
    return heading;
}


int Entity::getHeight() { 
    return z;
}


sf::Vector2f Entity::getTileLoc() {
    return tileLoc;
}


sf::Vector2i Entity::getWorldLoc() { 
    return worldLoc;
}


void Entity::changeHeading(float newHeading) { 
    heading += newHeading;
}


void Entity::changeHeight(int newHeight) { 
    z += newHeight;
}


void Entity::changeTileLoc(sf::Vector2f newTileLoc) {
    sf::Vector2i deltaWorld(0,0);
    tileLoc += newTileLoc;
    
    //check bounds, move to new tile if necessary
    //do we need loop to look for extreme location values?
    if (tileLoc.x >= 1.0f) {
        tileLoc.x -= 1.0f;
        deltaWorld.x = 1;
    } else if (tileLoc.x < 0.0f) {
        tileLoc.x += 1.0f;
        deltaWorld.x = -1;
    }
    if (tileLoc.y >= 1.0f) {
        tileLoc.y -= 1.0f;
        deltaWorld.y = 1;
    } else if (tileLoc.y < 0.0f) {
        tileLoc.y += 1.0f;
        deltaWorld.y = -1;
    }
    changeWorldLoc(deltaWorld);
}


void Entity::changeWorldLoc(sf::Vector2i newWorldLoc) { 
    worldLoc += newWorldLoc;
    //need bounds checking
}


void Entity::setHeading(float newHeading) { 
    heading = newHeading;
}


void Entity::setHeight(int newHeight) { 
    z = newHeight;
}


void Entity::setTileLoc(sf::Vector2f newTileLoc) {
    tileLoc = newTileLoc;
}


void Entity::setWorldLoc(sf::Vector2i newWorldLoc) { 
    worldLoc = newWorldLoc;
}

void Entity::setWindowPosition(sf::Vector2f position) { 
    //need camera?
    mSprite.setPosition(position);
}


