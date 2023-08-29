#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <cmath>
#include <cstddef>

#include <grid.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML-Graphing-CLI");
    sf::View         view = window.getDefaultView();

    window.setFramerateLimit(30);

    Grid grid(sf::Vector2f(window.getSize().x, window.getSize().y), 50, 50);

    while (window.isOpen()) {
        sf::Event events;
        while (window.pollEvent(events)) {
            if (events.type == sf::Event::Closed) {
                window.close();
            }

            if (events.type == sf::Event::Resized) {
                sf::Vector2f new_dim(static_cast<float>(events.size.width), static_cast<float>(events.size.height));
                view.setCenter(new_dim / 2.f);
                view.setSize(new_dim);
                window.setView(view);
                grid.update(sf::Vector2f(view.getSize().x, view.getSize().y), 50, 50);
            }
        }

        window.clear(sf::Color::White);

        // draw
        window.draw(grid);

        window.display();
    }

    return 0;
}