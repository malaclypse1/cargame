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

void Map::draw(sf::RenderWindow &win, Camera camera) { 
    //need a sprite too
    //Loop over visible tiles
    //for now, assume tile size is 256x256 - should be 3 or 4 tiles to left of center
    //top left = window size/2 - (window size/2 + camera tileLoc) = - camera tileLoc
    //top left tile = camera world loc - (window size/2 - camera tileLoc)/256
    sf::Vector2f topLeft, worldOffset;
    sf::Vector2i tlWorldOffset, brWorldOffset;

    topLeft.x = WINDOW_WIDTH/2 - (WINDOW_WIDTH/256 + camera.getTileLoc().x) * 256.0f;
    topLeft.y = WINDOW_HEIGHT/2 - (WINDOW_HEIGHT/256 + camera.getTileLoc().y) * 256.0f;

    tlWorldOffset.x = camera.getWorldLoc().x - (WINDOW_WIDTH/2 - (int) topLeft.x)/256;
    tlWorldOffset.y = camera.getWorldLoc().y - (WINDOW_HEIGHT/2 - (int) topLeft.y)/256;
    brWorldOffset.x = (WINDOW_WIDTH+256)/256;
    brWorldOffset.y = (WINDOW_HEIGHT+256)/256;

    for (int x = tlWorldOffset.x;x<brWorldOffset.x;x++)
    {
        for (int y = tlWorldOffset.y;y<brWorldOffset.y;y++)
        {
            //draw tile
            worldOffset.x = topLeft.x + x * 256;
            worldOffset.y = topLeft.y + y * 256;
            tile.setPosition(worldOffset);
            win.draw(tile);
        }
    }

}

Map::Map(sf::Texture texture) {
    tile.setTexture(texture);
}


