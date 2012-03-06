
#include "snake.h"

namespace snake {

    Position::Position(){}

    Snake::Snake()
    {
        if(imHead.LoadFromFile("assets/snake_head.png")) {
            spHead.SetImage(imHead);
            spHead.SetScaleX(1.f/8.f);
            spHead.SetScaleY(1.f/8.f);
        }

        SnakeChunk head;
        head.pos.X = 10;
        head.pos.Y = 10;

        for (int i = Dir::UP; i <= Dir::RIGHT; ++i)
        {
            headDir[i] = sf::IntRect(i * 256, 0, 256 + (i * 256), 256);
        }

        spHead.SetSubRect(headDir[Dir::LEFT]);

        chunks.push_front(head);
    }

    void Snake::draw(sf::RenderWindow& app)
    {
        std::list<SnakeChunk>::iterator i;


        for (i = chunks.begin(); i != chunks.end(); ++i)
        {
            if(i == chunks.begin()) {
                spHead.SetX(i->pos.X);
                spHead.SetY(i->pos.Y);

                app.Draw(spHead);

            } else if(i == chunks.end()) {

            } else {

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