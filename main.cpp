#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

float getFPS(const sf::Time& time) {
    return (1.0 / time.asSeconds());
}

int main()
{
    sf::Clock clock;

    float fps;

    sf::RenderWindow window(sf::VideoMode(640,480,32),"Hello SFML");

    sf::Font font;
    font.loadFromFile("fonts/sansation.ttf");


    sf::Text textFPS("UPTIME: ", font, 25);
    textFPS.setPosition(3, 2);
    textFPS.setCharacterSize(32);



    while(window.isOpen()){


        sf::Time elapsed = clock.getElapsedTime();
        fps = elapsed.asSeconds();
        textFPS.setString("UPTIME: " + std::to_string(fps));
        window.clear(sf::Color::Black);
        window.draw(textFPS);

        window.display();

    }

    return 0;

}