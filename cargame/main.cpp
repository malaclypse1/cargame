
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "Vehicle.hpp"
#include "Camera.hpp"
#include "Config.hpp"
#include "Map.hpp"
#include "Controls.hpp"

int main(int, char const**)
{
    float turnRate = 0.3f; //temporary!
    float accel = 0.005f;
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a ground texture
    sf::Texture groundTexture;
    if (!groundTexture.loadFromFile(resourcePath() + "desert.png")) {
        return EXIT_FAILURE;
    }
    Map map(groundTexture);
    
    // Create a player car
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile(resourcePath() + "car.png")) {
        return EXIT_FAILURE;
    }
    Vehicle playerCar(playerTexture);
    Controls player;
    
    // Camera focus position (window center)
    // This might become a class
    Camera camera;
    const sf::Vector2f initCameraPos(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
    camera.setWindowPosition(initCameraPos);
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    sf::Color color(0,0,128);
    text.setFillColor(color);

    // Load a music to play
//    sf::Music music;
//    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
//        return EXIT_FAILURE;
//    }

    // Play the music
//    music.play();
    
    // initialize timing clock
    sf::Clock clock;
    sf::Time lastFrameTime;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                // Close window: exit
                case sf::Event::Closed:
                    window.close();
                
                // key pressed
                case sf::Event::KeyPressed:
                    //if key is escape, close window
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                    //toggle key control booleans
                    else if (event.key.code == player.left)
                        player.leftKey = true;
                    else if (event.key.code == player.right)
                        player.rightKey = true;
                    else if (event.key.code == player.hardLeft)
                        player.hardLeftKey = true;
                    else if (event.key.code == player.hardRight)
                        player.hardRightKey = true;
                    else if (event.key.code == player.throttleUp)
                        player.throttleUpKey = true;
                    else if (event.key.code == player.throttleDown)
                        player.throttleDownKey = true;
                    
                    break;
                case sf::Event::KeyReleased:
                //toggle key control booleans
                if (event.key.code == player.left)
                    player.leftKey = false;
                else if (event.key.code == player.right)
                    player.rightKey = false;
                else if (event.key.code == player.hardLeft)
                    player.hardLeftKey = false;
                else if (event.key.code == player.hardRight)
                    player.hardRightKey = false;
                else if (event.key.code == player.throttleUp)
                    player.throttleUpKey = false;
                else if (event.key.code == player.throttleDown)
                    player.throttleDownKey = false;
                
                break;
                default:
                    break;
            }
        }
        //ship control
        if (true /*playerCar.getState() == SS_GOOD*/) {
            
            //turns TODO: cleanup and allow cording
            if (player.leftKey)
                playerCar.turnLeft(turnRate);
            else if (player.rightKey)
                playerCar.turnRight(turnRate);
            else if (player.hardLeftKey)
                playerCar.turnLeft(turnRate*3.0f);
            else if (player.hardRightKey)
                playerCar.turnRight(turnRate*3.0f);
            else
                playerCar.straighten();

            
            //thrust
            if (player.throttleUpKey)
                playerCar.changeThrottle(accel);
            else if (player.throttleDownKey)
                playerCar.changeThrottle(-accel);
            
            //brake
            if (player.brakeKey) {
                playerCar.braking = true;
                playerCar.setThrottle(playerCar.maintenanceThrottle());
                //I'd rather only set the throttle when braking is done...
            }
            else playerCar.braking = false;
        }
        
        // center camera on player car
        camera.setTileLoc(playerCar.getTileLoc());
        camera.setWorldLoc(playerCar.getWorldLoc());
        
        
        // Clear screen
        window.clear();
        lastFrameTime = clock.restart();
        
        //testing textures
//        sf::Sprite test1(playerTexture), test2(groundTexture);
//        window.draw(test2);
//        window.draw(test1);
//        window.display();
        
        // Draw map
        map.draw(window,camera);

        // Draw the sprite
        playerCar.updateLocation(lastFrameTime);
        playerCar.draw(window);

        // Draw the string - temp fill in for UI/debugging
        std::ostringstream ss;
        sf::Vector2f vel = playerCar.getVelocity();
        sf::Vector2f tile = playerCar.getTileLoc();
        sf::Vector2i world = playerCar.getWorldLoc();
        ss << "throttle: " << playerCar.getThrottle();
        ss << " speed: " << mph(magnitude(vel)) << " mph";
        ss << " fps: " << 1.0f/lastFrameTime.asSeconds();
        ss << "\nwheelBase: " << playerCar.getWheelBase();
        ss << " heading: " << playerCar.getHeading() << "\nvelocity: " << magnitude(vel) * 256.0f;
        ss << " wheel: " << playerCar.getWheel();
        ss << "\nlocation (x: " << world.x << '/' << tile.x << " y: " << world.y << '/' << tile.y << ")";
        ss << "\ntorque: " << playerCar.torque() << " ang vel: " << playerCar.getAngularVelocity();
        ss << "\nslipAngleRear: " << playerCar.slipAngleRear() << " Front: " << playerCar.slipAngleFront();
        ss << "\ncorneringForce: x: " << playerCar.corneringForce().x << ", y: "<< playerCar.corneringForce().y;
        ss << "\nsideSlipAngle: " << playerCar.sideslipAngle() / degreesToRadians;
        std::string s(ss.str());
        text.setString(s);
        window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
