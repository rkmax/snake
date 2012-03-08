
#include "snake.hpp"

namespace snake {

    Position::Position(){}

    Position::Position(int x, int y){
        X = x;
        Y = y;
    }

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
            directions[i] = (i % 2 == 0) ? -1 : 1;
        }
        chunkDir[1] = chunkDir[0];
        chunkDir[3] = chunkDir[2];

        // Initial Chunks
        for (int i = 1; i <= 3; ++i)
        {
            SnakeChunk ch;
            ch.pos = Position(0, i * 64);
            movements.push(ch.pos);
            ch.direction = Dir::DOWN;
            chunks.push_front(ch);
        }

        // Initial
        velocity = 5;

    }

    void Snake::draw(sf::RenderWindow& app)
    {

        list<SnakeChunk>::iterator it;

        for(it = chunks.begin(); it != chunks.end(); ++it) {

            if (it == chunks.begin()) {
                it->spChunk.SetImage(imHead);
                it->spChunk.SetSubRect(headTailDir[it->direction]);
            } else if (it == (--chunks.end())) {
                it->spChunk.SetImage(imTail);
                it->spChunk.SetSubRect(headTailDir[it->direction]);
            } else {
                it->spChunk.SetImage(imChunk);
                it->spChunk.SetSubRect(chunkDir[it->direction]);
            }
            it->spChunk.SetX(it->pos.X);
            it->spChunk.SetY(it->pos.Y);
            app.Draw(it->spChunk);
        }
    }

    void Snake::move(int newDir)
    {
        std::list<SnakeChunk>::iterator it;

        it = chunks.begin();

        if (it->direction == Dir::LEFT ||
            it->direction == Dir::RIGHT) {
            it->pos.X += velocity * directions[it->direction];
        }

        if (it->direction == Dir::UP ||
            it->direction == Dir::DOWN) {
            it->pos.Y += velocity * directions[it->direction];
        }
        it->direction = newDir;
        movements.push(it->pos);

        it++;
        while(it != chunks.end()) {
            it->pos = movements.front();
            movements.push(it->pos);
            movements.pop();

            ++it;
        }

        it = chunks.end();
        --it;
        it->pos = movements.front();
        movements.pop();


        cout << "----------------" << endl;
        it = chunks.begin();
        while(it != chunks.end()) {
            cout << "P: " << it->pos.Y << endl;
            ++it;
        }

    }
}