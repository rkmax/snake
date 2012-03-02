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

        void setCurrentScreen(Screen &scr){ screen = &scr;}
        Screen *getCurrentScreen(){ return screen;}
        void setInputManager(Input &in){ input = &in; }
    private:

        Screen *screen;
        Input *input;

        static Director *instance;
        static void Destroy();
        Director(const Director& d){}
        Director();
    };
}
#endif