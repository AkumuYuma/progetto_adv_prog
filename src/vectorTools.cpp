// Operazioni utili sui vettori di float 2d della libreria sfml

#include <SFML/System/Vector2.hpp>
#include "../include/vectorTools.h"
// Includo libreria matematica
#include <cmath>
// Uso le costanti matematiche
#define _USE_MATH_DEFINES

// ------------------------------- Definizioni -------------------------//
float vectorTools::module(const sf::Vector2f vettore) {
  // Calcola il modulo del vettore
  // :param: vettore
  // :return: modulo del vettore
  return sqrt(pow(vettore.x, 2) + pow(vettore.y, 2));
}

float vectorTools::heading(const sf::Vector2f vettore) {
  // Calcola l'angolo in radianti tra il vettore e l'asse x
  // :param: vettore -> di cui calcolare l'angolo
  // :return: angolo in radianti tra il vettore e l'asse x
  float angle = atan(vettore.y / vettore.x);
  if (vettore.x < 0) {
    angle += M_PI;
  }
  return angle;
}

void vectorTools::limitVector(sf::Vector2f &vettore, float limite) {
  // Se il modulo del vettore supera il valore limite, lo blocca sul limite
  // :param: vettore -> di cui limitare il modulo
  // :param: limite -> valore limite
  float modulo = sqrt(pow(vettore.x, 2) + pow(vettore.y, 2));
  if (modulo > limite) {
    // Setto i valori di x e y tali che l'angolo resti lo stesso ma il modulo
    // sia uguale a limite
    vettore.x *= limite / modulo;
    vettore.y *= limite / modulo;
  }
}

void vectorTools::normalizeVector(sf::Vector2f &vettore) {
  // Setta il modulo del vettore a 1
  // :param: vettore -> da normalizzare
  limitVector(vettore, 1);
}

void vectorTools::multVector(sf::Vector2f &vettore, float scalare) {
  // Moltiplica il vettore per lo scalare
  // :param: vettore -> da moltiplicare
  // :param: scalare -> da moltiplicare
  vettore.x *= scalare;
  vettore.y *= scalare;
}

float vectorTools::dist(sf::Vector2f vettore1, sf::Vector2f vettore2) {
  // Calcola la distanza tra i due punti passati come vettori
  // :param: vettore1 -> inizio
  // :param: vettore2 -> fine
  // :return: distanza tra i due vettori
  sf::Vector2f diff = vettore1 - vettore2;
  return vectorTools::module(diff);
}

//-----------------------------------------------------------------------//
