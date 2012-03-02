
#include "main.h"

using namespace sf;
using namespace snake;

int main(int argc, char const *argv[])
{
    RenderWindow App(VideoMode(640, 480), "Snake");

    Director *director = &Director::Instance();

    WelcomeScreen *initialScreen = new WelcomeScreen();

    director->setCurrentScreen(*initialScreen);

    while(App.IsOpened())
    {
        Event event;

        while(App.GetEvent(event))
        {
            // LLama ejecuta la logica de la pantalla actual
            director->getCurrentScreen()->run(event);

            // TODO: Pendiente configurar que la salida de la aplicacion sea manejado por Director

            if (event.Type == Event::Closed) {
                App.Close();
            }
        }

        App.Clear();
        App.Display();

    }

    return EXIT_SUCCESS;
}