#ifndef _GAME_SCREEN_H
#define _GAME_SCREEN_H
#include "screen.h"
#include "snake.h"

namespace snake {
    /**
     * Clase que mantiene maneja la ventana de juego
     * Aqui se muestran Todos los niveles del juego
    **/
    class GameScreen: public Screen
    {
    public:
        GameScreen();
        virtual ~GameScreen(){};
    private:
        Snake player;

        string getName();
        void checkInput();
        void updateLogic();
        void drawThis();
    };
}
#endif
