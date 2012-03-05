#ifndef _WELCOME_SCREEN_H_
#define _WELCOME_SCREEN_H_

#include <screen.h>

namespace snake {
    /**
     * Clase que maneja la ventana principal del juego
     * muestra el menu principal y todas las opciones que derivan de él
    **/
    class WelcomeScreen: public Screen
    {
    public:
        WelcomeScreen();
        virtual ~WelcomeScreen(){};
    private:
        sf::Image backgroundImage;
        sf::Sprite backgroundSprite;

        sf::Image titleImage;
        sf::Sprite titleSprite;

        snake::Menu* menu;

        string getName();
        void checkInput();
        void updateLogic();
        void drawThis();
    };
}
#endif