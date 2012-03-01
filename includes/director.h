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

        void setCurrentScreen(Screen &screen);
        Screen *getCurrentScreen();
    private:

        Screen *screen;

        static Director *instance;
        static void Destroy();
        Director();
        Director(const Director& d){}
    };
}
#endif