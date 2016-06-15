//
//  Map.hpp
//  
//
//  Created by Philip Routley on 6/14/16.
//
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Map {
private:
    u_short tiles[256][256];        //2d array of u_short indexed tiles
    u_short persis[256][256];       //2d array of u_short indexed persistant overlays
    u_short shadow[16][256][256];       //5am to 8pm + night 2d array of shadows
    
public:
    //return appropriate map tile index
    u_short getTile(sf::Vector2i loc);
    
    //return appropriate persistance map index
    u_short getPersis(sf::Vector2i loc);
    
    //convert time to hour and return appropriate shadow map index
    u_short getShadow(int time, sf::Vector2i loc);
};
#endif /* Map_hpp */
