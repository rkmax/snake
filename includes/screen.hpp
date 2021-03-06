#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "director.hpp"

using namespace std;
using namespace sf;

#ifndef _SCREEN_H
#define _SCREEN_H

namespace snake {

    /**
     * Clase abstracta que maneja la logica de una pantalla
     * Cualquier pantalla del juego debe derivar de esta
     * ya que asi la logica del juego se encuentra completamente organizada
    **/
    class Screen
    {
    public:
        /**
         * Constructur por defecto de la clase
        **/
        Screen(){};

        /**
         * Desructor virtual de la clase
        **/
        virtual ~Screen(){};

        /**
         * Metodo que se ejecuta desde el bucle pricipal de la aṕlicacion
         * tiene la logica a ejecutar de la pantalla
        **/
        virtual void run();

        /**
         * Fija el puntero hacia el director de pantallas, esto le permite a la
         * pantalla tener acceso a todos los recursos que tenga el director de
         * ventanas
        **/
        virtual void setDirector(Director *dir){ director = dir;}

        /**
         * Puntero hacia el director de pantallas
        **/
        Director *director;

        /**
         * Determina si la pantalla esta ejecutandose
        **/
        bool isRunning;

    private:
        /**
         * Metodo virtual que devuelve una cadena con el nombre de la pantalla
        **/
        virtual string getName() = 0;

        /**
         * Este metodo virtual se ejecuta dentro del metodo run(), y tiene toda la
         * logica que la pantalla necesita respecto a la entrada
        **/
        virtual void checkInput() = 0;

        /**
         * Metodo virtual que realiza la realiza de toda la logica, aqui va
         * todo lo que sucede en la pantalla, este metodo es llamado desde el
         * metodo run()
        **/
        virtual void updateLogic() = 0;

        /**
         * Este metodo pinta todo en pantalla, este metdoo es llamado desde el
         * metodo run()
        **/
        virtual void drawThis() = 0;
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