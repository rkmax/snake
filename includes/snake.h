#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <iostream>
#include <list>
#include <queue>
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
        Position(int, int);
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
        SnakeChunk()
        {
            spChunk.SetScale(1.f/4.f, 1.f/4.f);
        }
        Position pos;
        Position npos;
        int direction;
        sf::Sprite spChunk;
    };

    /**
     * Es la entidad que controlamos en el juego
    **/
    class Snake {
    public:
        Snake();

        void move(int);
        void changeDirection(const int dir);
        void grow();
        void shrink();
        void draw(sf::RenderWindow&);

        int velocity;
    private:
        list<SnakeChunk> chunks;

        sf::Image imHead;
        sf::Image imChunk;
        sf::Image imTurn;
        sf::Image imTail;

        sf::IntRect headTailDir[4];
        sf::IntRect chunkDir[4];
        sf::IntRect turnDir[4];
        int directions[4];

        std::queue<Position> movements;
    };
}
#endif