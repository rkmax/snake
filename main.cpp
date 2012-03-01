
#include "main.h"

using namespace sf;
using namespace snake;

int main(int argc, char const *argv[])
{
    RenderWindow App(VideoMode(640, 480), "Snake");

    Director director = Director::Instance();

    Screen *initialScreen = new WelcomeScreen();

    director->setCurrentScreen(initialScreen);

    while(App.IsOpened())
    {
        Event Event;

        while(App.GetEvent(Event))
        {
            if (Event.Type == Event::Closed) {
                App.Close();
            }
        }

        App.Clear();
        App.Draw(Welcome);
        App.Display();

    }

    return EXIT_SUCCESS;
}