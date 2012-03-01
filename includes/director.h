
#include <stdlib.h>

namespace snake {

    class Director
    {
    public:
        static Director &Instance();
        virtual ~Director(){};

        //void setScreen(Screen &screen);
    private:

        //Screen *screen;

        static Director *instance;
        static void Destroy();
        Director(){};
        Director(const Director& d){}
    };
}