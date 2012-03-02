
#include "screen.h"

namespace snake {


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