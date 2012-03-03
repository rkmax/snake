#ifndef _DIRECTOR_APP_H_
#define _DIRECTOR_APP_H_

using namespace sf;

namespace snake {
    // Definicion previa de Screen para evitar dependencias circulares
    class Screen;

    /**
     * Clase singleton que maneja las pantallas
     * Se encarga de centralizar los recursos que manejan la diferentes pantallas
     * del juego como son las Entradas de teclado
    **/
    class DirectorApp: public sf::RenderWindow
    {
    public:

        /**
         * Cambia la pantalla actual que maneja el director
        **/
        void setCurrentScreen(Screen &scr){
             screen = &scr;
        }

        /**
         * Devuelve la pantalla actual del director
        **/
        Screen *getCurrentScreen(){ return screen;}

    private:
        /**
         * Un puntero hacia la pantalla actual
         */
        Screen *screen;
    };
}
#endif