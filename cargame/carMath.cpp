//
//  carMath.cpp
//  cargame
//
//  Created by Philip Routley on 6/11/18.
//  Copyright © 2018 Philip Routley. All rights reserved.
//

#include <stdio.h>

#include "carMath.hpp"

sf::Vector2f normalizeV2f(sf::Vector2f inputVector) {
    float magnitude = sqrt(inputVector.x * inputVector.x + inputVector.y * inputVector.y);
    return inputVector/magnitude;
}
