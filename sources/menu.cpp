
#include "menu.hpp"

namespace snake {

    Menu::Menu(){}

    Menu::Menu(list<string> opt)
    {
        normalColor = sf::Color(216, 59, 5);
        selectedColor = sf::Color(251, 237, 11);

        font.LoadFromFile("assets/comic.ttf");

        if (buffer.LoadFromFile("assets/menu_change_option.ogg")) {
            changeSound.SetBuffer(buffer);
            changeSound.SetLoop(false);
        }

        currentOption = 0;

        for (list<string>::iterator i = opt.begin(); i != opt.end(); ++i)
        {
            sf::String op(*i, font, 50);
            op.SetColor((i == opt.begin()) ? selectedColor : normalColor);
            options.push_back(op);
        }

    }

    void Menu::nextOption()
    {
        currentOption++;
        if(currentOption > options.size() - 1){
            currentOption = 0;
        }
        changeSound.Play();

    }

    void Menu::prevOption()
    {

        if(currentOption == 0){
            currentOption = options.size() - 1;
        } else {
            currentOption--;
        }
        changeSound.Play();
    }

    string Menu::getOption()
    {
        unsigned int counter = 0;
        string opText;
        for (list<sf::String>::iterator i = options.begin();
                i != options.end(); ++i)
        {
            if (counter == currentOption){
                opText = (*i).GetText();
            }

            counter++;
        }

        return opText;
    }

    void Menu::draw(sf::RenderWindow& app)
    {
        unsigned int counter = 0;
        sf::FloatRect lastPos;

        for (list<sf::String>::iterator i = options.begin();
                i != options.end(); ++i)
        {
            if (counter == currentOption)
            {
                i->SetColor(selectedColor);
            } else {
                i->SetColor(normalColor);
            }

            i->SetPosition(60.f, 200 + (58.f * counter));

            app.Draw(*i);

            counter++;
        }
    }
}