#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

#ifndef _SCREEN_H
#define _SCREEN_H

namespace snake {

    /**
     * Clase abstracta que maneja las pantallas
     * Cualquier pantalla del juego debe derivar de esta
     * ya que asi la logica del juego se encuentra completamente organizada
    **/
    class Screen
    {
    public:
        Screen(){};
        virtual ~Screen(){};
        virtual void run(Event ev);
    private:
        virtual string getName() = 0;
        virtual void checkInput() = 0;
        virtual void updateLogic() = 0;
        virtual void drawThis() = 0;
    };

    /**
     * Clase que maneja la ventana principal del juego
     * muestra el menu principal y todas las opciones que derivan de él
    **/
    class WelcomeScreen: public Screen
    {
    public:
        WelcomeScreen(){};
        virtual ~WelcomeScreen(){};
    private:
        string getName();
        void checkInput();
        void updateLogic();
        void drawThis();
    };

    /**
     * Clase que mantiene maneja la ventana de juego
     * Aqui se muestran Todos los niveles del juego
    **/
    class GameScreen: public Screen
    {
    public:
        GameScreen(){};
        virtual ~GameScreen(){};
    private:
        string getName();
        void checkInput();
        void updateLogic();
        void drawThis();
    };

    /**
     * Clase que mantiene los puntajes
     * Muestra un listado de los puntajes de Mayor a menor
    **/
    class ScoreScreen: public Screen
    {
    public:
        ScoreScreen(){};
        virtual ~ScoreScreen(){};
    private:
        string getName();
        void checkInput();
        void updateLogic();
        void drawThis();
    };
}
#endif