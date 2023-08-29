#ifndef MRDCVLSC_SFML_GRAPHING_CLI
#define MRDCVLSC_SFML_GRAPHING_CLI

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Window.hpp>

class Grid : public sf::Drawable, public sf::Transformable {
    public:

    Grid(sf::Vector2f const& dimension, float pdpc, float vpc);

    /// \brief update the grid.
    /// \param window an sfml window instance.
    /// \param pdpc Pixel Dimension Per Cell, this is the size of the side of a
    /// square on a cartesian plane. \param vpc Value Per Cell, this is the number
    /// of units in one cell, if both pdpc and vpc is equal to 1 this would mean
    /// one sqaure per one unit.
    bool update(sf::Vector2f const& dimension, float pdpc, float vpc);

    private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::Transform transform;
    sf::VertexArray vertices;
};

#endif