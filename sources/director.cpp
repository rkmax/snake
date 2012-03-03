
#include "screen.h"

namespace snake {
    Director *Director::instance = 0;

    Director& Director::Instance()
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
        window = new RenderWindow(VideoMode(640, 480), "Snake");
    }

    void Director::Destroy()
    {
        if (instance != 0) delete instance;
    }

    void Director::start()
    {

    }
}