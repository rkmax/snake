#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <iostream>
#include <list>
#include <queue>
#include <SFML/Graphics.hpp>

#include "position.hpp"

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
        sf::Sprite spChunk;
    };

    /**
     * Es la entidad que controlamos en el juego
    **/
    class Snake {
    public:
        Snake();

        void move(int);
        void move();
        void changeDirection(const int dir);
        void grow();
        void shrink();
        void draw(sf::RenderWindow&);
        list<SnakeChunk> getChunks();

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