#ifndef CUBE_H
#define CUBE_H

#include <SFML/Graphics.hpp>

class Cube {
public:
    Cube(float x, float y);
    void draw(sf::RenderWindow& window);
    void move(float dx, float dy);
    sf::RectangleShape getShape(); // Pour obtenir la forme du joueur pour la collision

private:
    sf::RectangleShape rectangle; // Représentation du joueur
};

#endif // CUBE_H
