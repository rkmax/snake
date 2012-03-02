
#include "snake.h"

namespace snake {
    Snake::Snake(){
        Snake(3);
    }

    Snake::Snake(unsigned int initial_tail)
    {
        std::cout << "Voy a crear " << initial_tail << " partes" << std::endl;
        lives = 3;

        for (unsigned int i = 0; i < initial_tail; ++i)
        {
            tail.push_front( new SnakeTail() );
        }

    }
}