
#include "main.h"

using namespace sf;
using namespace snake;

int main(int argc, char const *argv[])
{
    RenderWindow App(VideoMode(640, 480), "Snake");
    WelcomeScreen welcomeScr;
    welcomeScr.run();

    Director &director = Director::Instance();

    // Aqui paso algo

    Image image;

    if (!image.LoadFromFile("/home/julian/Imágenes/snake_screen.jpg"))
    {
        return EXIT_FAILURE;
    }

    Sprite Welcome(image);

    Font comicTff;

    if (!comicTff.LoadFromFile("./assets/comic.ttf"))
    {
        return EXIT_FAILURE;
    }

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