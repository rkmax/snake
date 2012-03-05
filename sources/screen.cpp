
#include "screen.h"

namespace snake {

    void Screen::run() {

        sf::Clock clock;

        while(director->application.IsOpened()) {

            sf::Event event;

            while(director->application.GetEvent(event)){
                checkInput();
            }

            updateLogic();

            director->application.Clear();
            drawThis();
            director->application.Display();
        }

    }
}