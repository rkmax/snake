#include "position.hpp"

namespace snake {

    Position::Position(){}

    Position::Position(int x, int y)
    {
        X = x;
        Y = y;
    }

    const Position &Position::operator=(const Position &npos)
    {
        if(this == &npos) {
            return *this;
        }
        (*this).X = npos.X;
        (*this).Y = npos.Y;

        return *this;
    }

    const Position &Position::operator+=(const Position &npos)
    {
        (*this).X += npos.X;
        (*this).Y += npos.Y;

        return *this;
    }

    const Position &Position::operator+(const Position &npos)
    {
        return *this += npos;
    }


    const Position &Position::operator-=(const Position &npos)
    {
        (*this).X -= npos.X;
        (*this).Y -= npos.Y;

        return *this;
    }

    const Position &Position::operator-(const Position &npos)
    {
        return *this -= npos;
    }

    const bool Position::operator==(const Position &npos)
    {
        return (this->X == npos.X && this->Y == npos.Y);
    }

    const bool Position::operator!=(const Position &npos)
    {
        return !(*this == npos);
    }

}