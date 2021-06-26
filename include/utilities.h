#ifndef UTILITIES_H
#define UTILITIES_H

namespace utilities {
    float radToDeg(float radians);
    std::unique_ptr<sf::CircleShape> creaCibo(sf::RenderWindow &finestra, bool buono, sf::Vector2f posizione = sf::Vector2f(-1, -1));
    sf::Text creaTesto(sf::Font font, std::string testo, unsigned size, sf::Vector2f Posizione = sf::Vector2f{0, 0});
} // namespace utilities

#endif
