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
        static Director &Instance();
        virtual ~Director(){};

        void setCurrentScreen(Screen &scr){
             screen = &scr;
        }
        Screen *getCurrentScreen(){ return screen;}
        void setInputManager(const sf::Input &in){ input = &in;}
        Input const& getInputManager() const { return *input; }
    private:

        Screen *screen;
        const Input *input;

        static Director *instance;
        static void Destroy();
        Director(const Director& d){}
        Director();
    };
}
#endif