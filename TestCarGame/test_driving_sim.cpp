//
//  test_driving_sim.cpp
//  cargame
//
//  Created by Philip Routley on 4/25/19.
//  Copyright © 2019 Philip Routley. All rights reserved.
//

#define CATCH_CONFIG_MAIN

#include <stdio.h>

#include "catch.hpp"
#include "Vehicle.hpp"

TEST_CASE("Testing Vehicle") {
    Vehicle tv;
    
    SECTION("Testing carMath") {
        sf::Vector2f vec = sf::Vector2f(2.0f,0.0f);
        REQUIRE(magSqr(vec) == 4.0f);
    }
}
