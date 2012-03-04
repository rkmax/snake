
#include "screen.h"
#include "snake.h"

using namespace std;

namespace snake {

    WelcomeScreen::WelcomeScreen()
    {
        if(backgroundImage.LoadFromFile("assets/snake_background.png")) {
            backgroundSprite.SetImage(backgroundImage);
        }
    }

    string WelcomeScreen::getName()
    {
        return "WELCOME";
    }

    void WelcomeScreen::checkInput()
    {

        //TODO: Directivas para el menu
        if(director->application.GetInput().IsKeyDown(sf::Key::Down)) {

        }
        if(director->application.GetInput().IsKeyDown(sf::Key::Up)) {

        }
    }

    void WelcomeScreen::updateLogic()
    {

    }

    void WelcomeScreen::drawThis()
    {
        director->application.Draw(backgroundSprite);
    }
}