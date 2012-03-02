#include <stdlib.h>
#include "screen.h"
#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

namespace snake {

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
        void run();
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