#include "../include/grid.hpp"
#include <SFML/Graphics/Color.hpp>
#include <iostream>

Grid::Grid(sf::Vector2f const& dimension, float pdpc, float vpc) : vertices(sf::Lines) {
    update(dimension, pdpc, vpc);
}

bool Grid::update(sf::Vector2f const& dimension, float pdpc, float vpc) {
    sf::Vector2f origin = {dimension.x / 2.f, dimension.y / 2.f};

    vertices.clear();

    // x axis line
    vertices.append({{0.f, origin.y}, sf::Color::Red});
    vertices.append({{dimension.x, origin.y}, sf::Color::Red});

    // y axis line
    vertices.append({{origin.x, 0.f}, sf::Color::Blue});
    vertices.append({{origin.x, dimension.y}, sf::Color::Blue});

    // y axis grid line from origin to the right
    for (float x = origin.x + pdpc; x < dimension.x; x += pdpc) {
        vertices.append({{x, 0.f}, sf::Color(0xd3, 0xd3, 0xd3)});
        vertices.append({{x, dimension.y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    // y axis grid line from origin to the left
    for (float x = origin.x - pdpc; x > 0.f; x -= pdpc) {
        vertices.append({{x, 0.f}, sf::Color(0xd3, 0xd3, 0xd3)});
        vertices.append({{x, dimension.y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    // x axis grid line from origin to the bottom
    for (float y = origin.y + pdpc; y < dimension.y; y += pdpc) {
        vertices.append({{0.f, y}, sf::Color(0xd3, 0xd3, 0xd3)});
        vertices.append({{dimension.x, y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    // x axis grid line from origin to the top
    for (float y = origin.y - pdpc; y > 0.f; y -= pdpc) {
        vertices.append({{0.f, y}, sf::Color(0xd3, 0xd3, 0xd3)});
        vertices.append({{dimension.x, y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    return true;
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform() * transform;
    target.draw(vertices, states);
}