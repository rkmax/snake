#ifndef _MENU_H_
#define _MENU_H_

#include <list>
#include <SFML/Graphics.hpp>

using namespace std;

namespace snake {
    class Menu
    {
    public:
        Menu(const list<string>& options);
        ~Menu();
        void nextOption();
        void prevOption();
    private:
        sf::Color normalColor;
        sf::Color selectedColor;
        sf::Font font;

        int currentOption;

        list<sf::Text> options;
    };
}
#endif