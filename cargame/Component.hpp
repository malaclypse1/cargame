//
//  Component.hpp
//  cargame
//
//  Created by Philip Routley on 3/26/17.
//  Copyright © 2017 Philip Routley. All rights reserved.
//

#ifndef Component_h
#define Component_h

#include "Vehicle.hpp"

#include <SFML/Graphics.hpp>

class Component {
    int hitPoints;
    Vehicle *ofVehicle;
    Component *fwd, *port, *stbd, *aft, *top, *bot;
    
    Component* nextHit(float damageDir);
};

#endif /* Component_h */
