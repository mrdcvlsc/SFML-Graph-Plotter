#ifndef MRDCVLSC_SFML_GRAPHING_CLI
#define MRDCVLSC_SFML_GRAPHING_CLI

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <vector>

class Grid : public sf::Sprite {
    public:

    Grid(sf::Vector2f const &dimension, float cell_size, float cell_unit);

    /// \brief update the grid.
    /// \param dimension window instance dimension size.
    /// \param cell_size this is the size of the side of a square on a cartesian plane.
    /// \param cell_unit the number of units in one cell, if both cell_size and cell_unit is equal to 1 this would mean one sqaure per one unit.
    bool reset(sf::Vector2f const &dimension, float cell_size, float cell_unit);

    void applyTransform(sf::Transform const &transformation);
    void setTransform(sf::Transform const &transformation);

    void add_vector(sf::Vector2f const& vec, float x = 0.f, float y = 0.f);

    private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::Vector2f coords(sf::Vector2f const& coordinates) {
        return {
            (origin_point.x + coordinates.x) * cell_size,
            (origin_point.y - coordinates.y) * cell_size
        };
    }

    sf::Vector2f coords(float x, float y) {
        return {
            (origin_point.x + x) * cell_size,
            (origin_point.y - y) * cell_size
        };
    }

    sf::Vector2f    origin_point;
    sf::CircleShape origin_dot;

    sf::VertexArray grid_lines;

    sf::VertexArray vectors;

    /// cell square side size.
    float cell_size;

    /// units per cell.
    float cell_unit;
};

#endif