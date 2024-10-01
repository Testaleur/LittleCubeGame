#include "Cube.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Cube::Cube(float x, float y) {
    rectangle.setSize(sf::Vector2f(x, y)); // Taille du joueur
    rectangle.setFillColor(sf::Color::Black); // Couleur verte
    rectangle.setPosition(x, y);
}

void Cube::draw(sf::RenderWindow& window) {
    window.draw(rectangle);
}

void Cube::move(float dx, float dy) {
    rectangle.move(dx, dy); // Déplace le joueur
}

sf::RectangleShape Cube::getShape() {
    return rectangle; // Retourne la forme du joueur
}
