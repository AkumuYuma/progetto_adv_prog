#ifndef VECTORTOOL_H
#define VECTORTOOL_H

// ------------------------------ Vector tools --------------------------//
namespace vectorTools {

    float module(const sf::Vector2f vettore);
    float heading(const sf::Vector2f vettore);
    void limitVector(sf::Vector2f &vettore, float limite);
    void normalizeVector(sf::Vector2f &vettore);
    void multVector(sf::Vector2f &vettore, float scalare);
    float dist(sf::Vector2f vettore1, sf::Vector2f vettore2);

} // namespace vectorTools

#endif
