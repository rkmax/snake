#ifndef _POSITION_H_
#define _POSITION_H_

namespace snake {
    class Position {
    public:
        Position();
        Position(int, int);

        int X;
        int Y;
        const Position &operator=(const Position &);
        const Position &operator+=(const Position &);
        const Position &operator+(const Position &);
        const Position &operator-=(const Position &);
        const Position &operator-(const Position &);
        const bool operator==(const Position &);
        const bool operator!=(const Position &);
    };
}
#endif