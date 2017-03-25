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
    sf::Vector2f velocity;
};
#endif /* MovingEntity_h */
