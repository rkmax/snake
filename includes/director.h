#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

using namespace sf;

namespace snake {
    // Definicion previa de Screen para evitar dependencias circulares
    class Screen;

    /**
     * Clase singleton que maneja las pantallas
     * Se encarga de centralizar los recursos que manejan la diferentes pantallas
     * del juego como son las Entradas de teclado
    **/
    class Director
    {
    public:
        /**
         * Metodo que devuelve la instancia de director, si exta no existe, crea
         * una nueva
        **/
        static Director &Instance();

        /**
         * Destructur de la clase
        **/
        virtual ~Director(){};

        /**
         * Cambia la pantalla actual que maneja el director
        **/
        void setCurrentScreen(Screen &scr);

        /**
         * Devuelve la pantalla actual del director
        **/
        Screen *getCurrentScreen(){ return screen; }

        void start();

        RenderWindow application;
    private:
        /**
         * Un puntero hacia la pantalla actual
         */
        Screen *screen;

        /**
         * Un puntero hacia el Gestor de entradas de la aplicacion
         */
        const Input *input;

        /**
         * Mantiene la unica instancia del director de ventanas
         */
        static Director *instance;

        /**
         * Se asegura de destruir la instancia al salir de la aplicacion
        **/
        static void Destroy();

        /**
         * Constructur auxiliar
        **/
        Director(const Director& d){}

        /**
         * Constructur por defecto de la clase
        **/
        Director();
    };
}
#endif