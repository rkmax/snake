
#include "screen.h"

namespace snake {

    void Screen::run() {

        checkInput();
        updateLogic();
        drawThis();
    }
}