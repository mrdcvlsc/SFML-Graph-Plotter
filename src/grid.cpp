#include "../include/grid.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

Grid::Grid(sf::Vector2f const &dimension, float pdpc, float vpc) : m_vertices(sf::Lines) {
    reset(dimension, pdpc, vpc);
}

bool Grid::reset(sf::Vector2f const &dimension, float pdpc, float vpc) {
    this->pdpc = pdpc;
    this->vpc = vpc;

    window_center = {dimension.x / 2.f, dimension.y / 2.f};

    m_vertices.clear();

    // x axis line
    m_vertices.append({{0.f, window_center.y}, sf::Color::Red});
    m_vertices.append({{dimension.x, window_center.y}, sf::Color::Red});

    // y axis line
    m_vertices.append({{window_center.x, 0.f}, sf::Color::Blue});
    m_vertices.append({{window_center.x, dimension.y}, sf::Color::Blue});

    // y axis grid line from origin to the right
    for (float x = window_center.x + pdpc; x < dimension.x; x += pdpc) {
        m_vertices.append({{x, 0.f}, sf::Color(0xd3, 0xd3, 0xd3)});
        m_vertices.append({{x, dimension.y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    // y axis grid line from origin to the left
    for (float x = window_center.x - pdpc; x > 0.f; x -= pdpc) {
        m_vertices.append({{x, 0.f}, sf::Color(0xd3, 0xd3, 0xd3)});
        m_vertices.append({{x, dimension.y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    // x axis grid line from origin to the bottom
    for (float y = window_center.y + pdpc; y < dimension.y; y += pdpc) {
        m_vertices.append({{0.f, y}, sf::Color(0xd3, 0xd3, 0xd3)});
        m_vertices.append({{dimension.x, y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    // x axis grid line from origin to the top
    for (float y = window_center.y - pdpc; y > 0.f; y -= pdpc) {
        m_vertices.append({{0.f, y}, sf::Color(0xd3, 0xd3, 0xd3)});
        m_vertices.append({{dimension.x, y}, sf::Color(0xd3, 0xd3, 0xd3)});
    }

    setOrigin(window_center.x, window_center.y);
    setPosition(window_center);

    origin.setRadius(3.f);
    origin.setPosition({window_center.x - origin.getRadius(), window_center.y - origin.getRadius()});
    origin.setFillColor(sf::Color::Black);

    return true;
}

void Grid::applyTransform(sf::Transform const &transformation) {
    for (std::size_t i = 0; i < m_vertices.getVertexCount(); ++i) {
        sf::Vector2f transformedPosition = (getTransform() * transformation).transformPoint(m_vertices[i].position);
        m_vertices[i].position = transformedPosition;
    }

    auto origin_trans_pos = (getTransform() * transformation).transformPoint(origin.getPosition());
    origin.setPosition(origin_trans_pos.x - origin.getRadius(), origin_trans_pos.y - origin.getRadius());

    auto bound_center = m_vertices.getBounds();
    setOrigin(bound_center.width / 2.f, bound_center.height / 2.f);
    setPosition(window_center);
}

void Grid::setTransform(sf::Transform const &transformation) {
    reset(window_center * 2.f, pdpc, vpc);
    applyTransform(transformation);
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_vertices, states);
    target.draw(origin, states.transform);
}