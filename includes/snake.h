#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <iostream>
#include <list>

using namespace std;

namespace snake {
    /**
     * Direcciones de Snake
    **/
    namespace Dir {
        const int UP = 1;
        const int DOWN = 3;
        const int LEFT = 2;
        const int RIGHT = 4;
    }

    /**
     * Es una seccion de la serpiente
    **/
    class SnakeTail
    {
    public:
        SnakeTail(){
            std::cout << "Soy una nueva pieza" << endl;
        }
        virtual void changeDirection(const int dir){ direction = dir; }
    private:
        int direction;
    };

    /**
     * Es la entidad que controlamos en el juego
    **/
    class Snake: public SnakeTail    {
    public:
        Snake();
        Snake(unsigned int initial_tail);
    private:
        int velocity;
        int direction;
        int lives;
        std::list <SnakeTail*> tail;
    };
}
#endif