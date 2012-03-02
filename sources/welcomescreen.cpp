
#include "screen.h"
#include "snake.h"

using namespace std;

namespace snake {

    WelcomeScreen::WelcomeScreen()
    {
        sf::Image im;
        if(im.LoadFromFile("./assets/snake_background.png")) {
            background = sf::Sprite(im);
        }
    }

    string WelcomeScreen::getName()
    {
        return "WELCOME";
    }

    void WelcomeScreen::checkInput()
    {
        if (director->getInputManager().IsKeyDown(sf::Key::Down))
        {
            cout << "Pulsata fecha hacia abajo" << endl;
        }
    }

    void WelcomeScreen::updateLogic()
    {

    }

    void WelcomeScreen::drawThis()
    {

    }
}