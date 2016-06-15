//
//  Entity.hpp
//  cargame
//
//  Created by Philip Routley on 6/14/16.
//  Copyright © 2016 Philip Routley. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Entity {
    sf::Vector2i worldLoc;      //location of tile in world
    sf::Vector2f tileLoc;       //location within tile
    int z;                      //height
    
};

#endif /* Entity_hpp */
