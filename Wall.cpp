#include "Wall.h"
#include <SFML/Graphics.hpp>
using namespace sf; // Utiliser le namespace SFML

Wall::Wall(float x, float y, float width, float height) {
    // Set the size and position of the wall
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setFillColor(sf::Color::White); // Black color
    rectangle.setPosition(x, y);
}

void Wall::draw(sf::RenderWindow& window) {
    // Draw the wall in the window
    window.draw(rectangle);
}

RectangleShape Wall::getShape() {
    return rectangle; // Retourne la forme du joueur
}