#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>

class Wall {
public:
    Wall(float x, float y, float width, float height);
    void draw(sf::RenderWindow& window);
    sf::RectangleShape getShape();
private:
    sf::RectangleShape rectangle; // Representation of the wall
};

#endif // WALL_H
