
#include "screen.h"
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
        application.Create(sf::VideoMode(640, 480), "Snake");
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