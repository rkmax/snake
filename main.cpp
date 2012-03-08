
#include "main.hpp"

using namespace sf;
using namespace snake;

int main(int argc, char const *argv[])
{

    try {
        Director *director = &Director::Instance();
        director->start();
    } catch(char* err) {
        std::cerr << err << std::endl;
    }

    return EXIT_SUCCESS;
}