//
//  MovingEntity.h
//  cargame
//
//  Created by Philip Routley on 3/25/17.
//  Copyright © 2017 Philip Routley. All rights reserved.
//

#ifndef MovingEntity_h
#define MovingEntity_h

#include "Entity.hpp"

#include <stdio.h>
#include <SFML/Graphics.hpp>

class MovingEntity : public Entity
{
private:
    sf::Vector2f velocity;
public:
    //=============================================
    //constructors
    MovingEntity();
    MovingEntity(const sf::Texture& entitySprite);
    
    sf::Vector2f getVelocity();
    void setVelocity(sf::Vector2f newVelocity);
    void changeVelocity(sf::Vector2f newVelocity);
    void updateLocation();
};
#endif /* MovingEntity_h */
