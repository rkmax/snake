
#include "screen.h"

namespace snake {

    void Screen::run() {

        sf::Clock clock;
        int FPS = 1000 / 60;
        float next_tick = clock.GetElapsedTime() * 1000;


        while(true) {
            next_tick += FPS;
            while((clock.GetElapsedTime() * 1000) < next_tick) {
                checkInput();
                if (!director->application.IsOpened()) return;

                sf::Sleep(10 / 1000);

                updateLogic();

                director->application.Clear();
                drawThis();
                director->application.Display();
            }
        }

    }
}