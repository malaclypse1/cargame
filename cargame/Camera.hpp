//
//  Camera.hpp
//  cargame
//
//  Created by Philip Routley on 6/12/18.
//  Copyright © 2018 Philip Routley. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Camera {
private:
    sf::Vector2i worldLoc;      //location of tile in world
    sf::Vector2f tileLoc;       //location within tile
    sf::Vector2f windowPosition;//should be center of game window
    
public:
    //=============================================
    //constructors
    Camera();

    //=============================================
    //mutators
    void setWorldLoc(sf::Vector2i newWorldLoc);
    void setTileLoc(sf::Vector2f newTileLoc);
    void setWindowPosition(sf::Vector2f position);
    void changeWorldLoc(sf::Vector2i newWorldLoc);
    void changeTileLoc(sf::Vector2f newTileLoc);

    //=============================================
    //accessors
    sf::Vector2i getWorldLoc();
    sf::Vector2f getTileLoc();
    sf::Vector2f getWinPos();
    
    //=============================================
    //others
};
#endif /* Camera_hpp */
