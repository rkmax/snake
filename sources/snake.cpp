
#include "snake.hpp"

namespace snake {

    Snake::Snake()
    {
        imHead.LoadFromFile("assets/snake_head.png");
        imChunk.LoadFromFile("assets/snake_chunk.png");
        imTurn.LoadFromFile("assets/snake_turn.png");
        imTail.LoadFromFile("assets/snake_tail.png");

        //Sprite sheets
        for (int i = Dir::UP; i <= Dir::RIGHT; ++i)
        {
            chunkDir[i] = headTailDir[i] = sf::IntRect(i * 256, 0, 256 + (i * 256), 256);
        }

        // Initial
        velocity = 5;


        directions[Dir::UP] = -1;
        directions[Dir::DOWN] = 1;
        directions[Dir::LEFT] = -1;
        directions[Dir::RIGHT] = 1;

        chunkDir[1] = chunkDir[0];
        chunkDir[3] = chunkDir[2];

        // Initial Chunks
        for (int i = 3; i >= 1; --i)
        {
            SnakeChunk ch;
            ch.pos = Position(0, i * 64);
            ch.pos.direction = Dir::DOWN;
            chunks.push_back(ch);

            if(i > 1) movements.push(ch.pos);
        }
    }

    void Snake::draw(sf::RenderWindow& app)
    {

        list<SnakeChunk>::iterator it;

        for(it = chunks.begin(); it != chunks.end(); ++it) {

            if (it == chunks.begin()) {
                it->spChunk.SetImage(imHead);
                it->spChunk.SetSubRect(headTailDir[it->pos.direction]);
            } else if (it == (--chunks.end())) {
                it->spChunk.SetImage(imTail);
                it->spChunk.SetSubRect(headTailDir[it->pos.direction]);
            } else {
                it->spChunk.SetImage(imChunk);
                it->spChunk.SetSubRect(chunkDir[it->pos.direction]);
            }
            it->spChunk.SetX(it->pos.X);
            it->spChunk.SetY(it->pos.Y);
            app.Draw(it->spChunk);
        }
    }

    void Snake::move()
    {
        move(-1);
    }

    void Snake::move(int newDir)
    {
        std::list<SnakeChunk>::iterator it, end;
        end = chunks.end();
        --end;

        for (it = chunks.begin(); it != chunks.end(); ++it)
        {
            // Solo la cabeza cambia de direccion
            if (it == chunks.begin()) {
                if (newDir >= 0) {
                    it->pos.direction = newDir;
                }
                // Calcula la nueva posicion basado en la velocidad
                if (it->pos.direction == Dir::LEFT ||
                        it->pos.direction == Dir::RIGHT) {
                    it->pos.X += velocity * directions[it->pos.direction];
                }

                if (it->pos.direction == Dir::UP ||
                            it->pos.direction == Dir::DOWN) {
                    it->pos.Y += velocity * directions[it->pos.direction];
                }
            } else {
                // Todos los demas seleccionan nuevas posiciones
                it->pos = movements.front();
                movements.pop();
            }

            // Todos menos la cola añaden posiciones
            if (it != end) {
                movements.push(it->pos);
            }
        }
    }

    list<SnakeChunk> Snake::getChunks()
    {
        return chunks;
    }
}