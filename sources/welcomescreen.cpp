
#include "screen.h"
#include "snake.h"

using namespace std;

namespace snake {

    WelcomeScreen::WelcomeScreen()
    {
        normalColor = sf::Color(216, 59, 5);
        selectedColor = sf::Color(251, 237, 11);

        option = 0;

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
        option = 0;
        if(director->application.GetInput().IsKeyDown(sf::Key::Down)) {
            option++;
        }
        if(director->application.GetInput().IsKeyDown(sf::Key::Up)) {
            option--;
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