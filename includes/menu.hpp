#ifndef _MENU_H_
#define _MENU_H_

#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

namespace snake {
    class Menu
    {
    public:
        Menu();
        Menu(list<string>);
        ~Menu(){}
        void nextOption();
        void prevOption();

        void draw(sf::RenderWindow&);

        string getOption();
    private:
        sf::Color normalColor;
        sf::Color selectedColor;
        sf::Font font;

        sf::SoundBuffer buffer;
        sf::Sound changeSound;

        unsigned int currentOption;

        list<sf::String> options;
    };
}
#endif