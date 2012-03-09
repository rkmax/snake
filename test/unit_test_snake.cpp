#define BOOST_TEST_MODULE Snake
#include <boost/test/included/unit_test.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "snake.hpp"

using namespace snake;

BOOST_AUTO_TEST_CASE( Snake_move )
{
    Snake* s = new Snake();
    list<SnakeChunk> prev;

    prev = s->getChunks();

    for (std::list<SnakeChunk>::iterator i = prev.begin(); i != prev.end(); ++i)
    {
        cout << i->pos.X << ", " << i->pos.Y << std::endl;
    }

    s->move(Dir::DOWN);
    cout << "Snake.move(dir::DOWN):" << std::endl;

    prev = s->getChunks();

    for (std::list<SnakeChunk>::iterator i = prev.begin(); i != prev.end(); ++i)
    {
        cout << i->pos.X << ", " << i->pos.Y << std::endl;
    }

    s->move(Dir::DOWN);
    cout << "Snake.move(dir::DOWN):" << std::endl;

    prev = s->getChunks();

    for (std::list<SnakeChunk>::iterator i = prev.begin(); i != prev.end(); ++i)
    {
        cout << i->pos.X << ", " << i->pos.Y << std::endl;
    }

}