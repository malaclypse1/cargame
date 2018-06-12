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
    //in general, fwd/aft/port/stbd are used as directions
    //while front/back/left/right are used for locations
    //example layout for stbd side:
    //right armor
    //  port right weapon
    //      port driver
    //          fwd powerplant
    //          port left weapon
    //          stbd right weapon
    //          aft rear weapon
    //      stbd right armor
    //      fwd powerplant
    //          fwd front weapon
    //          ...
    //      aft rear weapon
    //  fwd front right tire
    //  aft rear right tire

};

#endif /* Component_h */
