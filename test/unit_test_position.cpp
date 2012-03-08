#define BOOST_TEST_MODULE Position
#include <boost/test/included/unit_test.hpp>


class Position {
public:
    Position(){}
    Position(int x, int y)
    {
        X = x;
        Y = y;
    }

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

BOOST_AUTO_TEST_CASE( Operador_Asignacion )
{
    Position p1(1, 2);
    Position p2;

    p2 = p1;

    BOOST_CHECK_EQUAL( p2.X, p1.X );
    BOOST_CHECK_EQUAL( p2.Y, p1.Y );
}

BOOST_AUTO_TEST_CASE( Operador_Suma )
{
    Position p1(1, 2);
    Position p2(2, 3);
    Position p3(3, 5);

    p1 = p1 + p2;

    BOOST_CHECK_EQUAL( p3.X, p1.X );
    BOOST_CHECK_EQUAL( p3.Y, p1.Y );
}