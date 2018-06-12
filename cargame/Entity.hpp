//
//  Entity.hpp
//  cargame
//
//  Created by Philip Routley on 6/14/16.
//  Copyright © 2016 Philip Routley. All rights reserved.
//
// an Entity is an in-game object: it could be a building, terrain feature, vehicle, projectile...
// question: do I need entity-like objects that don't appear on screen?

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Entity {
private:
    void init(); //initialize entity - load sprites, etc
    sf::Vector2i worldLoc;      //location of tile in world
    sf::Vector2f tileLoc;       //location within tile
    int z;                      //height
    float heading;              //rotation in degrees
    
protected:
    sf::Sprite mSprite; //sprite for Entity
    
public:
    //=============================================
    //constructors
    Entity();
    Entity(const sf::Texture& entitySprite);
    
    //=============================================
    //mutators
    void setWorldLoc(sf::Vector2i newWorldLoc);
    void setTileLoc(sf::Vector2f newTileLoc);
    void setHeight(int newHeight);
    void setHeading(float newHeading);
    void setWindowPosition(sf::Vector2f position);
    void changeWorldLoc(sf::Vector2i newWorldLoc);
    void changeTileLoc(sf::Vector2f newTileLoc);
    void changeHeight(int newHeight);
    void changeHeading(float newHeading);
    
    //=============================================
    //accessors
    sf::Vector2i getWorldLoc();
    sf::Vector2f getTileLoc();
    int getHeight();
    float getHeading();
    
    //=============================================
    //others
    virtual void draw(sf::RenderWindow& win);
    

};

#endif /* Entity_hpp */
