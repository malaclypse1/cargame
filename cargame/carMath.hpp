//
//  carMath.hpp
//  cargame
//
//  Created by Philip Routley on 6/11/18.
//  Copyright © 2018 Philip Routley. All rights reserved.
//

#ifndef carMath_h
#define carMath_h

#include <cmath>
#include <SFML/Graphics.hpp>

sf::Vector2f normalizeV2f(sf::Vector2f inputVector);
const float degreesToRadians = 3.14159265358979323846f/180.0f;
const sf::Vector2f zeroVector(0.0f, 0.0f);

//Polar here meaning north at 0 degrees, angle going clockwise
float magnitude(sf::Vector2f inputVector);
float magSqr(sf::Vector2f inputVector);
float direction(sf::Vector2f inputVector); //output compass heading in degrees
float dotProduct(sf::Vector2f vector1, sf::Vector2f vector2);
float mph(float mps);
sf::Vector2f unitVector(float heading);
sf::Vector2f unitVector(sf::Vector2f inputVector);
sf::Vector2f proj(sf::Vector2f vector1, sf::Vector2f vector2); //projection of vector1 onto vector2

#endif /* carMath_h */
