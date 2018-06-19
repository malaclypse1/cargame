//
//  Controls.cpp
//  cargame
//
//  Created by Philip Routley on 6/19/18.
//  Copyright © 2018 Philip Routley. All rights reserved.
//

#include "Controls.hpp"

Controls::Controls() {
    left = sf::Keyboard::Q;
    right = sf::Keyboard::E;
    hardLeft = sf::Keyboard::A;
    hardRight = sf::Keyboard::D;
    accelerate = sf::Keyboard::W;
    brake = sf::Keyboard::S;
}
