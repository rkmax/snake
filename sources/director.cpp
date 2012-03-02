
#include "director.h"

namespace snake {
    Director *Director::instance = 0;

    Director &Director::Instance()
    {
        if(0 == instance) {
            instance = new Director();

            atexit(&Destroy);
        }

        return *instance;
    }

    Director::Director()
    {
        screen = 0;
    }

    void Director::Destroy()
    {
        if (instance != 0) delete instance;
    }
}