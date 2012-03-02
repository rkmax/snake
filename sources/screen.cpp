
#include "../includes/screen.h"

namespace snake {

    void Screen::run(Event ev) {

        checkInput();
        updateLogic();
        drawThis();
    }
}