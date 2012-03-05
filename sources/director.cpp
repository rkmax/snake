
#include "welcomescreen.h"
#include "director.h"

namespace snake {
    Director *Director::instance = 0;

    Director& Director::Instance()
    {
        if(0 == instance) {
            instance = new Director();

            atexit(&Destroy);
        }

        return *instance;
    }

    Director::Director()
    {
        screen = 0;

        sf::WindowSettings Settings;
        Settings.DepthBits         = 24; // Request a 24 bits depth buffer
        Settings.StencilBits       = 8;  // Request a 8 bits stencil buffer
        Settings.AntialiasingLevel = 2;  // Request 2 levels of antialiasing
        application.Create(sf::VideoMode(640, 480), "Snake", sf::Style::Close, Settings);
        application.SetFramerateLimit(60);
    }

    void Director::Destroy()
    {
        if (instance != 0) delete instance;
    }

    void Director::setCurrentScreen(Screen &scr)
    {
        screen = &scr;
        screen->setDirector(this);
    }

    void Director::start()
    {
        screen = new WelcomeScreen();
        screen->setDirector(this);

        screen->run();

    }
}