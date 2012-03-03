
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

        if(im.LoadFromFile("./assets/snake_title.png")) {
            title = sf::Sprite(im);
        }

        normalColor = sf::Color(216, 59, 5);
        selectedColor = sf::Color(251, 237, 11);

        option = 0;

        options[0] = "Nuevo Juego";
        options[1] = "Puntuaciones";
        options[2] = "Salir";
    }

    string WelcomeScreen::getName()
    {
        return "WELCOME";
    }

    void WelcomeScreen::checkInput()
    {
        int t_options = sizeof(options) - 1;
        if (director->getInputManager().IsKeyDown(sf::Key::Down))
        {
            ++option;
            if (option > t_options ) option = 0;

        }
        if (director->getInputManager().IsKeyDown(sf::Key::Up))
        {
            --option;
            if (option < 0 ) option = t_options;
        }
    }

    void WelcomeScreen::updateLogic()
    {

    }

    void WelcomeScreen::drawThis()
    {

    }
}