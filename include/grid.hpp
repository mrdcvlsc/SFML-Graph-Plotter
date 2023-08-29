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
#include <SFML/Window/Window.hpp>
#include <iostream>

class Grid : public sf::Sprite {
    public:

    Grid(sf::Vector2f const &dimension, float pdpc, float vpc);

    /// \brief update the grid.
    /// \param window an sfml window instance.
    /// \param pdpc Pixel Dimension Per Cell, this is the size of the side of a
    /// square on a cartesian plane. \param vpc Value Per Cell, this is the number
    /// of units in one cell, if both pdpc and vpc is equal to 1 this would mean
    /// one sqaure per one unit.
    bool reset(sf::Vector2f const &dimension, float pdpc, float vpc);

    void applyTransform(sf::Transform const &transformation);
    void setTransform(sf::Transform const &transformation);

    sf::CircleShape origin;

    private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::Vector2f    window_center;
    sf::VertexArray m_vertices;

    float pdpc;
    float vpc;
};

#endif