#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main() {
    // Tạo cửa sổ game
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Animation");
    window.setFramerateLimit(60);

    // Load Sprite Sheet
    sf::Texture texture;
    if (!texture.loadFromFile("assets/player.png"))
    {
        return -1;
    }

    sf::Sprite player(texture);

    const int frameWidth = 64;
    const int frameHeight = 64;

    player.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    player.setPosition(350, 250);

    int currentFrame = 0;
    int totalFrames = 4;
    float switchTime = 1.0f;

    sf::Clock animationClock;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (animationClock.getElapsedTime().asSeconds() >= switchTime)
        {
            currentFrame++;

            if (currentFrame >= totalFrames)
            {
                currentFrame = 0;
            }

            player.setTextureRect(
                sf::IntRect(
                    currentFrame * frameWidth,
                    0,
                    frameWidth,
                    frameHeight
                )
            );

            animationClock.restart();
        }

        window.clear(sf::Color::Black);
        window.draw(player);
        window.display();
    }
	return 0;
}