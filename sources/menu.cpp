

namespace snake {
    Menu::Menu(const list<string>& options)
    {
        normalColor = sf::Color(216, 59, 5);
        selectedColor = sf::Color(251, 237, 11);

        font.LoadfromFile("assets/commic.ttf");


        for (list<string>::iterator i = options.begin(); i != options.end(); ++i)
        {
            sf::Text op(i, font, 18)
            op.SetColor((i == options.begin()) ? selectedColor : normalColor);
            options.push_back(op);
        }

    }

    void Menu::nextOption()
    {

    }

    void Menu::prevOption()
    {

    }
}