#define BOOST_TEST_MODULE Position
#include <boost/test/included/unit_test.hpp>

#include "position.hpp"

using namespace snake;

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

BOOST_AUTO_TEST_CASE( Operador_Resta )
{
    Position p1(1, 2);
    Position p2(2, 3);
    Position p3(1, 1);

    p1 = p2 - p1;

    BOOST_CHECK_EQUAL( p3.X, p1.X );
    BOOST_CHECK_EQUAL( p3.Y, p1.Y );
}

BOOST_AUTO_TEST_CASE( Operador_Asignacion_Suma )
{
    Position p1(1, 2);
    Position p2(2, 3);
    Position p3(3, 5);

    p1 += p2;

    BOOST_CHECK_EQUAL( p3.X, p1.X );
    BOOST_CHECK_EQUAL( p3.Y, p1.Y );
}

BOOST_AUTO_TEST_CASE( Operador_Asignacion_Resta )
{
    Position p1(1, 2);
    Position p2(2, 3);
    Position p3(1, 1);

    p2 -= p1;

    BOOST_CHECK_EQUAL( p3.X, p2.X );
    BOOST_CHECK_EQUAL( p3.Y, p2.Y );
}


BOOST_AUTO_TEST_CASE( Operador_Igualdad )
{
    Position p1(1, 2);
    Position p2(2, 3);
    Position p3(1, 2);

    BOOST_CHECK_EQUAL( p1 == p3, true );
    BOOST_CHECK_EQUAL( p1 == p2, false );
}

BOOST_AUTO_TEST_CASE( Operador_Desigualdad )
{
    Position p1(1, 2);
    Position p2(2, 3);
    Position p3(1, 2);

    BOOST_CHECK_EQUAL( p1 != p3, false );
    BOOST_CHECK_EQUAL( p1 != p2, true );
}

//

BOOST_AUTO_TEST_CASE( Operador_Suma_Int )
{
    Position p1(1, 2);
    Position p2(6, 7);

    p1 = p1 + 5;

    BOOST_CHECK_EQUAL( p2.X, p1.X );
    BOOST_CHECK_EQUAL( p2.Y, p1.Y );
}

BOOST_AUTO_TEST_CASE( Operador_Resta_Int )
{
    Position p1(6, 7);
    Position p2(1, 2);

    p1 = p1 - 5;

    BOOST_CHECK_EQUAL( p2.X, p1.X );
    BOOST_CHECK_EQUAL( p2.Y, p1.Y );
}

BOOST_AUTO_TEST_CASE( Operador_Asignacion_Suma_Int )
{
    Position p1(1, 2);
    Position p2(6, 7);

    p1 += 5;

    BOOST_CHECK_EQUAL( p2.X, p1.X );
    BOOST_CHECK_EQUAL( p2.Y, p1.Y );
}

BOOST_AUTO_TEST_CASE( Operador_Asignacion_Resta_Int )
{
    Position p1(6, 7);
    Position p2(1, 2);

    p1 -= 5;

    BOOST_CHECK_EQUAL( p2.X, p1.X );
    BOOST_CHECK_EQUAL( p2.Y, p1.Y );
}