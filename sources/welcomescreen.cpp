
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
        if (director->application.GetInput().IsKeyDown(sf::Key::Down))
        {
            std::cout << "Pulsada tecla Flecha abajo" << std::endl;

        }
        if (director->application.GetInput().IsKeyDown(sf::Key::Up))
        {
            std::cout << "Pulsada tecla Flecha arriba" << std::endl;
        }
    }

    void WelcomeScreen::updateLogic()
    {

    }

    void WelcomeScreen::drawThis()
    {
        director->application.Draw(background);
    }
}