#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <cmath>
#include <cstddef>

#include <grid.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML-Graphing-CLI");
    sf::View         view = window.getDefaultView();

    window.setFramerateLimit(128);

    Grid grid_original(sf::Vector2f(window.getSize().x, window.getSize().y), 50, 50);

    Grid grid_transformed(sf::Vector2f(window.getSize().x, window.getSize().y), 50, 50);

    // sf::Transform transformation(1.f, 0.f, 0.f, 0.2f, 1.f, 0.f, 0.f, 0.f, 1.f);

    grid_original.add_vector({1.f, 1.f});

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

                grid_original.reset(sf::Vector2f(view.getSize().x, view.getSize().y), 32, 32);

                grid_transformed.reset(sf::Vector2f(view.getSize().x, view.getSize().y), 32, 32);

                // grid_transformed.applyTransform(transformation);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
            grid_transformed.rotate(0.2f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
            grid_transformed.rotate(-0.2f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
            grid_transformed.scale(1.01f, 1.01f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
            grid_transformed.scale(0.99f, 0.99f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Q)) {
            // grid_transformed.setTransform(transformation);
        }

        window.clear(sf::Color::White);

        // draw
        window.draw(grid_transformed);
        window.draw(grid_original);

        window.display();
    }

    return 0;
}