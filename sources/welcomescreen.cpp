
#include "screen.h"
#include "snake.h"

using namespace std;

namespace snake {

    WelcomeScreen::WelcomeScreen()
    {
        if(backgroundImage.LoadFromFile("assets/snake_background.png")) {
            backgroundSprite.SetImage(backgroundImage);
        }

        list<string> opciones;
        opciones.push_back("Nuevo juego");
        opciones.push_back("Salir");
        menu = new Menu(opciones);
    }

    string WelcomeScreen::getName()
    {
        return "WELCOME";
    }

    void WelcomeScreen::checkInput()
    {

        //TODO: Directivas para el menu
        if(director->application.GetInput().IsKeyDown(sf::Key::Down)) {
            menu->nextOption();
        }
        if(director->application.GetInput().IsKeyDown(sf::Key::Up)) {
            menu->prevOption();
        }

        if(director->application.GetInput().IsKeyDown(sf::Key::Return)) {
            std::cout << "Has seleccionado la opcion" << menu->getOption() << std::endl;
        }
    }

    void WelcomeScreen::updateLogic()
    {

    }

    void WelcomeScreen::drawThis()
    {
        director->application.Draw(backgroundSprite);
        menu->draw(director->application);
    }
}