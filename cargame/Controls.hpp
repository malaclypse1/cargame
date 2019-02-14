//
//  Controls.hpp
//  cargame
//
//  Created by Philip Routley on 6/19/18.
//  Copyright © 2018 Philip Routley. All rights reserved.
//

#ifndef Controls_hpp
#define Controls_hpp

#include <stdio.h>
#include <SFML/Window.hpp>

class Controls {
public:
    Controls();
    sf::Keyboard::Key left, right, hardLeft, hardRight, throttleUp, throttleDown, brake;
};
    
#endif /* Controls_hpp */
