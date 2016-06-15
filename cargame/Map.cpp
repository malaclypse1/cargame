//
//  Map.cpp
//  
//
//  Created by Philip Routley on 6/14/16.
//
//

#include "Map.hpp"
#include "Config.hpp"



//256x256 tiles, each 256x256 = 65,536 x 65,536 pixel map = ~4 gigapixels

//return appropriate map tile index
u_short Map::getTile(sf::Vector2i loc) {
    return tiles[loc.x][loc.y];
}

//return appropriate persistance map index
u_short Map::getPersis(sf::Vector2i loc) {
    return persis[loc.x][loc.y];
}

//convert time to hour and return appropriate shadow map index
u_short Map::getShadow(int time, sf::Vector2i loc) {
    int hour = time / TICS_PER_HOUR - 4;
    if (hour < 1 || hour > 15) hour = 0;
    return shadow[hour][loc.x][loc.y];
}
