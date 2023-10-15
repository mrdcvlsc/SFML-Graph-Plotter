#include "../include/grid.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

Grid::Grid(sf::Vector2f const &dimension, float cell_size, float cell_unit) : grid_lines(sf::Lines), vectors(sf::Lines) {
    reset(dimension, cell_size, cell_unit);
}

bool Grid::reset(sf::Vector2f const &dimension, float cell_size, float cell_unit) {
    this->cell_size = cell_size;
    this->cell_unit = cell_unit;

    origin_point = {dimension.x / 2.f, dimension.y / 2.f};

    grid_lines.clear();

    // x axis line
    grid_lines.append({{0.f, origin_point.y}, sf::Color::Red});
    grid_lines.append({{dimension.x, origin_point.y}, sf::Color::Red});

    // y axis line
    grid_lines.append({{origin_point.x, 0.f}, sf::Color::Blue});
    grid_lines.append({{origin_point.x, dimension.y}, sf::Color::Blue});

    // y axis grid line from origin to the right
    for (float x = origin_point.x + cell_size; x < dimension.x; x += cell_size) {
        grid_lines.append({{x, 0.f}, sf::Color(0xd3, 0xd3, 0xd3)});
        grid_lines.append({{x, dimension.y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    // y axis grid line from origin to the left
    for (float x = origin_point.x - cell_size; x > 0.f; x -= cell_size) {
        grid_lines.append({{x, 0.f}, sf::Color(0xd3, 0xd3, 0xd3)});
        grid_lines.append({{x, dimension.y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    // x axis grid line from origin to the bottom
    for (float y = origin_point.y + cell_size; y < dimension.y; y += cell_size) {
        grid_lines.append({{0.f, y}, sf::Color(0xd3, 0xd3, 0xd3)});
        grid_lines.append({{dimension.x, y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    // x axis grid line from origin to the top
    for (float y = origin_point.y - cell_size; y > 0.f; y -= cell_size) {
        grid_lines.append({{0.f, y}, sf::Color(0xd3, 0xd3, 0xd3)});
        grid_lines.append({{dimension.x, y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    setOrigin(origin_point.x, origin_point.y);
    setPosition(origin_point);

    origin_dot.setRadius(3.f);
    origin_dot.setPosition({origin_point.x - origin_dot.getRadius(), origin_point.y - origin_dot.getRadius()});
    origin_dot.setFillColor(sf::Color::Black);

    return true;
}

void Grid::applyTransform(sf::Transform const &transformation) {
    for (std::size_t i = 0; i < grid_lines.getVertexCount(); ++i) {
        sf::Vector2f transformedPosition = (getTransform() * transformation).transformPoint(grid_lines[i].position);
        grid_lines[i].position = transformedPosition;
    }

    auto origin_trans_pos = (getTransform() * transformation).transformPoint(origin_dot.getPosition());
    origin_dot.setPosition(origin_trans_pos.x - origin_dot.getRadius(), origin_trans_pos.y - origin_dot.getRadius());

    auto bound_center = grid_lines.getBounds();
    setOrigin(bound_center.width / 2.f, bound_center.height / 2.f);
    setPosition(origin_point);
}

void Grid::setTransform(sf::Transform const &transformation) {
    reset(origin_point * 2.f, cell_size, cell_unit);
    applyTransform(transformation);
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(grid_lines, states);
    target.draw(origin_dot, states);
    target.draw(vectors, states);
}

void Grid::add_vector(sf::Vector2f const& vec, float x, float y) {
    vectors.append({
        coords(0.f, 0.f),
        sf::Color::Black
    });

    vectors.append({
        // {1.f, 1.f},
        coords(50.f, 50.f),
        sf::Color::Black
    });
}