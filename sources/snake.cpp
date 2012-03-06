
#include "snake.h"

namespace snake {

    Position::Position(){}

    Snake::Snake()
    {
        if(imHead.LoadFromFile("assets/snake_head.png")) {
            spHead.SetImage(imHead);
            spHead.SetScaleX(1.f/4.f);
            spHead.SetScaleY(1.f/4.f);
        }

        if(imChunk.LoadFromFile("assets/snake_chunk.png")) {
            spChunk.SetImage(imChunk);
            spChunk.SetScaleX(1.f/4.f);
            spChunk.SetScaleY(1.f/4.f);
        }

        if(imTurn.LoadFromFile("assets/snake_turn.png")) {
            spTurn.SetImage(imTurn);
            spTurn.SetScaleX(1.f/4.f);
            spTurn.SetScaleY(1.f/4.f);
        }

        if(imTail.LoadFromFile("assets/snake_tail.png")) {
            spTail.SetImage(imTail);
            spTail.SetScaleX(1.f/4.f);
            spTail.SetScaleY(1.f/4.f);
        }

        // Chunk sprite sheet
        for (int i = Dir::UP; i <= Dir::RIGHT; ++i)
        {
            headTailDir[i] = sf::IntRect(i * 256, 0, 256 + (i * 256), 256);
        }

        // Chunks sprite sheet
        for (int i = Dir::UP; i <= Dir::LEFT; i+=2)
        {
            chunkDir[i] = sf::IntRect(i * 256, 0, 256 + (i * 256), 256);
        }
        chunkDir[1] = chunkDir[0];
        chunkDir[3] = chunkDir[2];

        // Tail sprite sheet is same head


        // Initial Chunks
        for (int i = 3; i > 0; --i)
        {
            SnakeChunk ch;
            ch.pos.X = 64;
            ch.pos.Y = i * 64;
            chunks.push_back(ch);
        }



        // Initial Direction
        direction = Dir::DOWN;

    }

    void Snake::draw(sf::RenderWindow& app)
    {
        std::list<SnakeChunk>::iterator i;


        for (i = chunks.begin(); i != chunks.end(); ++i)
        {
            if(i == chunks.begin()) {
                spHead.SetX(i->pos.X);
                spHead.SetY(i->pos.Y);
                spHead.SetSubRect(headTailDir[direction]);
                app.Draw(spHead);

            } else if(i == chunks.end()) {
                spTail.SetX(i->pos.X);
                spTail.SetY(i->pos.Y);
                spTail.SetSubRect(headTailDir[direction]);
                app.Draw(spTail);
            } else {
                spChunk.SetX(i->pos.X);
                spChunk.SetY(i->pos.Y);
                spChunk.SetSubRect(chunkDir[direction]);
                app.Draw(spChunk);
            }
        }
    }

    void Snake::move()
    {
        std::list<SnakeChunk>::iterator i;

        Position tmp, tmp2;
        for (i = chunks.begin(); i != chunks.end(); ++i)
        {
            if(i == chunks.begin()) {
                tmp.X = (*i).pos.X;
                tmp.Y = (*i).pos.Y;

            } else if(i == chunks.end()) {
                (*i).pos = tmp;
            } else {
                tmp2 = (*i).pos;
                (*i).pos = tmp;
                tmp = tmp2;
            }
        }
    }
}