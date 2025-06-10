#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    sf::Texture texture;
    if (!texture.loadFromFile("assets/th.png")) // Cambia la ruta por tu imagen
        return -1;

    sf::Sprite sprite(texture);
    sprite.setPosition(100, 100);

    sf::Vector2f velocity(3.f, 2.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        sprite.move(velocity);
        sf::Vector2f pos = sprite.getPosition();
        sf::FloatRect bounds = sprite.getGlobalBounds();

        if (pos.x <= 0 || pos.x + bounds.width >= 800)
            velocity.x = -velocity.x;
        if (pos.y <= 0 || pos.y + bounds.height >= 600)
            velocity.y = -velocity.y;

        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}