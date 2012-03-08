
#include "gamescreen.hpp"

namespace snake {
    GameScreen::GameScreen()
    {
        direction = Dir::DOWN;
    }

    string GameScreen::getName()
    {
        return "GAME";
    }

    void GameScreen::checkInput()
    {
        // TODO: remover esta entrada
        if (director->application.GetInput().IsKeyDown(sf::Key::Escape)) {
            director->application.Close();
        }
        if (director->application.GetInput().IsKeyDown(sf::Key::Down))
        {
            if (direction == Dir::LEFT || direction == Dir::RIGHT) {
                direction = Dir::DOWN;
            }

        }

        if (director->application.GetInput().IsKeyDown(sf::Key::Up))
        {
            if (direction == Dir::LEFT || direction == Dir::RIGHT) {
                direction = Dir::UP;
            }
        }

        if (director->application.GetInput().IsKeyDown(sf::Key::Left))
        {
            if (direction == Dir::UP || direction == Dir::DOWN) {
                direction = Dir::LEFT;
            }

        }

        if (director->application.GetInput().IsKeyDown(sf::Key::Right))
        {
            if (direction == Dir::UP || direction == Dir::DOWN) {
                direction = Dir::RIGHT;
            }
        }

    }

    void GameScreen::updateLogic()
    {
        player.move(direction);
    }

    void GameScreen::drawThis()
    {
        player.draw(director->application);
    }
}