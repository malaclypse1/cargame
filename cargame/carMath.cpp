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
    return inputVector/magnitude(inputVector);
}

float magnitude(sf::Vector2f inputVector) {
    return sqrt(magSqr(inputVector));
}

float magSqr(sf::Vector2f inputVector) {
    return inputVector.x * inputVector.x + inputVector.y * inputVector.y;
}

float direction(sf::Vector2f inputVector) {
    return 90.0f - atan2(-inputVector.y, inputVector.x) / degreesToRadians;
    //-y, 0x return 0, +y,0x return 180, 0y,+x return 90
}

float dotProduct(sf::Vector2f vector1, sf::Vector2f vector2) {
    return vector1.x * vector2.x + vector1.y * vector2.y;
}

float mph(float mps) {
    return mps * 2.23694f;
}

sf::Vector2f unitVector(float heading) {
    float angle = heading * degreesToRadians;
    sf::Vector2f returnVector;
    returnVector.x = sin(angle);
    returnVector.y = -cos(angle);
    return returnVector;
}

sf::Vector2f unitVector(sf::Vector2f inputVector) {
    return normalizeV2f(inputVector);
}

sf::Vector2f proj(sf::Vector2f vector1, sf::Vector2f vector2) {
    return dotProduct(vector2, vector1) / (magnitude(vector2) * magnitude(vector2)) * vector2;
}
