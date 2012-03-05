
#include "welcomescreen.h"
#include "snake.h"

using namespace std;

namespace snake {

    WelcomeScreen::WelcomeScreen()
    {
        if(backgroundImage.LoadFromFile("assets/snake_background.png")) {
            backgroundSprite.SetImage(backgroundImage);
        }

        if(titleImage.LoadFromFile("assets/snake_title.png")) {
            titleSprite.SetImage(titleImage);
        }

        titleSprite.Move(50.f, 50.f);

        list<string> opciones;
        opciones.push_back("Nuevo juego");
        opciones.push_back("Puntajes");
        opciones.push_back("Salir");
        menu = new Menu(opciones);
    }

    string WelcomeScreen::getName()
    {
        return "WELCOME";
    }

    void WelcomeScreen::checkInput()
    {
        if (director->application.GetInput().IsKeyDown(sf::Key::Down)) {
            menu->nextOption();
        } else if (director->application.GetInput().IsKeyDown(sf::Key::Up)) {
            menu->prevOption();
        } else if (director->application.GetInput().IsKeyDown(sf::Key::Return)) {
            std::cout << "Has seleccionado la opcion: " << menu->getOption() << std::endl;
        }
    }

    void WelcomeScreen::updateLogic()
    {

    }

    void WelcomeScreen::drawThis()
    {
        director->application.Draw(backgroundSprite);
        director->application.Draw(titleSprite);
        menu->draw(director->application);
    }
}