#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Cube.h"
using namespace sf; // Utiliser le namespace SFML

bool checkCollision(const sf::RectangleShape& a, const sf::RectangleShape& b) {
    return a.getGlobalBounds().intersects(b.getGlobalBounds()); // V�rifie si les deux rectangles se chevauchent
}


int main()
{
    // Cr�er une fen�tre
    RenderWindow window(VideoMode(800, 600), "Moving cube with collisions");

    // Walls
    Wall wall1(200.f, 150.f, 100.f, 20.f); // Position (200, 150) avec une largeur de 100 et une hauteur de 20
    Wall wall2(400.f, 500.f, 200.f, 20.f); // Un autre mur

    // Cr�er un cube noir (rectangle)
    Cube cube(50.f, 50.f); // Taille du cube

    // Vitesse de d�placement
    float speed = 0.05f;

    // Boucle principale
    while (window.isOpen())
    {
        // Traiter les �v�nements
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // Contr�ler le cube avec les fl�ches
        float dx = 0;
        float dy = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            dx = -speed; // D�placer � gauche
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            dx = speed; // D�placer � droite
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            dy = -speed; // D�placer vers le haut
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            dy = speed; // D�placer vers le bas
        }

        // D�placer le cube temporairement
        cube.move(dx, dy);

        // V�rifier les collisions avec les murs
        if (checkCollision(cube.getShape(), wall1.getShape())) {
            // Si collision, annuler le mouvement
            cube.move(-dx, -dy);
        }
        if (checkCollision(cube.getShape(), wall2.getShape())) {
            cube.move(-dx, -dy);
        }

        // Effacer la fen�tre avec une couleur
        window.clear(Color(100, 100, 100)); // Couleur de fond

        // Dessiner le cube
        cube.draw(window);

        // Dessiner les murs
        wall1.draw(window);
        wall2.draw(window);

        // Afficher le contenu de la fen�tre
        window.display();
    }

    return 0;
}