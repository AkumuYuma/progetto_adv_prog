// Funzioni utili
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

#include <memory.h>
#include "utilities.h"
#include "../randomTools/randomTools.h"
#include <cmath>
#define _USE_MATH_DEFINES

float utilities::radToDeg(float radians) {
  // ritorna l'angolo trasformato in gradi
  // :param: radians -> Angolo in radianti
  // :return: angolo in gradi
  return (radians * 180) / M_PI;
}

std::unique_ptr<sf::CircleShape> utilities::creaCibo(sf::RenderWindow &finestra, bool buono, sf::Vector2f posizione) {
  // Restituisce un puntatore unico a un cibo in una posizione random dello
  // schermo :param: buono, se vero crea un cibo, altrimenti crea un veleno
  // :param: posizione, se viene passato lo usa per creare nella posizione,
  // altrimenti crea random
  std::unique_ptr<sf::CircleShape> cibo{new sf::CircleShape{2}};

  if (posizione.x >= 0 && posizione.y >= 0) {
    cibo->setPosition(posizione.x, posizione.y);
  } else {
    cibo->setPosition(randomTools::randomFloat(0, finestra.getSize().x), randomTools::randomFloat(0, finestra.getSize().y));
  }

  if (buono) {
    cibo->setFillColor(sf::Color::Green);
  } else {
    cibo->setFillColor(sf::Color::Red);
  }

  return cibo;
}

sf::Text utilities::creaTesto(sf::Font font, std::string testo, unsigned size, sf::Vector2f Posizione) {
  // :param: font -> font da usare
  // :param: testo -> stringa da scrivere
  // :param: size -> dimensione dei caratteri
  // :param: Posizione -> Posizione nella finestra in cui disegnare
  // :return: -> oggetto testo da disegnare sulla finestra
  sf::Text nuovoTesto;
  nuovoTesto.setFont(font);
  nuovoTesto.setPosition(Posizione);
  nuovoTesto.setString(testo);
  nuovoTesto.setCharacterSize(size);
  nuovoTesto.setFillColor(sf::Color::White);
  return nuovoTesto;
}
