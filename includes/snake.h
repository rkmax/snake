#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

using namespace std;

namespace snake {
    /**
     * Direcciones de Snake
    **/
    namespace Dir {
        const int UP = 0;
        const int DOWN = 1;
        const int LEFT = 2;
        const int RIGHT = 3;
    }

    class Position {
    public:
        Position();
        int X;
        int Y;
        const Position &operator=(const Position &npos)
        {
            if(this == &npos) {
                return *this;
            }
            (*this).X = npos.X;
            (*this).Y = npos.Y;

            return *this;
        }

        const Position &operator+(const Position &npos)
        {
            (*this).X += npos.X;
            (*this).Y += npos.Y;

            return *this;
        }

        const Position &operator-(const Position &npos)
        {
            (*this).X -= npos.X;
            (*this).Y -= npos.Y;

            return *this;
        }

    };

    /**
     * Es una seccion de la serpiente
    **/
    class SnakeChunk
    {
    public:
        SnakeChunk(){}
        Position pos;
    };

    /**
     * Es la entidad que controlamos en el juego
    **/
    class Snake: public SnakeChunk    {
    public:
        Snake();

        void move();
        void changeDirection(const int dir);
        void grow();
        void shrink();
        void draw(sf::RenderWindow&);
    private:
        int direction;
        list<SnakeChunk> chunks;

        sf::Image imHead;
        sf::Sprite spHead;

        sf::Image imChunk;
        sf::Sprite spChunk;

        sf::Image imTurn;
        sf::Sprite spTurn;

        sf::Image imTail;
        sf::Sprite spTail;

        sf::IntRect headTailDir[4];
        sf::IntRect chunkDir[4];
        sf::IntRect turnDir[4];
    };
}
#endif