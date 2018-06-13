//
//  Camera.cpp
//  cargame
//
//  Created by Philip Routley on 6/12/18.
//  Copyright © 2018 Philip Routley. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera() {
    worldLoc.x = 127;
    worldLoc.y = 127;
    tileLoc.x = 0.5f;
    tileLoc.y = 0.5f;
}
void Camera::setWorldLoc(sf::Vector2i newWorldLoc) { 
    worldLoc = newWorldLoc;
}

void Camera::setTileLoc(sf::Vector2f newTileLoc) { 
    tileLoc = newTileLoc;
}

void Camera::setWindowPosition(sf::Vector2f position) { 
    windowPosition = position;
}

void Camera::changeWorldLoc(sf::Vector2i newWorldLoc) { 
    worldLoc += newWorldLoc;
    //need bounds checking
}

void Camera::changeTileLoc(sf::Vector2f newTileLoc) { 
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

sf::Vector2i Camera::getWorldLoc() { 
    return worldLoc;
}

sf::Vector2f Camera::getTileLoc() { 
    return tileLoc;
}

sf::Vector2f Camera::getWinPos() { 
    return windowPosition;
}



