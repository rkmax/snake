
#include "main.h"

using namespace sf;

int main(int argc, char const *argv[])
{

    snake::Director *director = &snake::Director::Instance();

    try {
        director->start();
    } catch(char* e) {
        std::cerr << "Haocurrio un error: " << e << std::endl;
    }

    return EXIT_SUCCESS;
}