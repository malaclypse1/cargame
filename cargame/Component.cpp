//
//  Component.cpp
//  cargame
//
//  Created by Philip Routley on 3/31/17.
//  Copyright © 2017 Philip Routley. All rights reserved.
//

#include "Component.hpp"
#include "Vehicle.hpp"

//#include <stdio.h>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

Component* Component::nextHit(float damageDir)
{
    float relDamDir = damageDir - ofVehicle->getHeading();
    //damage at 90 degree increments should pass straight through. At inbetween angles, should have a chance
    //of going sideways
    //generate random float between 0 and 90
    float randDegree = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX)) * 90.0f;
    //cardinal direction of damage (0 = N, 1 = E, etc) - closest cardinal counterclockwise
    int cardinal = ((int) relDamDir/90)%4;
    //angle between cardinal and damage direction 0-90
    float acute = fmod(relDamDir, 90.0f);
    switch (cardinal)
    {
        case 0:
            if (acute <= randDegree)
                return fwd;
            else
                return stbd;
            break;
        case 1:
            if (acute <= randDegree)
                return stbd;
            else
                return aft;
            break;
        case 2:
            if (acute <= randDegree)
                return aft;
            else
                return port;
            break;
        case 3:
            if (acute <= randDegree)
                return port;
            else
                return fwd;
            break;
    }
    //something went wrong - should never get here
    std::cerr << "error Component.cpp: should never not exit on switch";
    return nullptr;
}
