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

#include "../randomTools/randomTools.h"
#include "../utilities/utilities.h"
#include "../vectorTools/vectorTools.h"
#include "veichle.h"

using namespace vectorTools;
using namespace utilities;
using namespace randomTools;


// Variabile di debug
bool Veichle::debug{false};


// Costruttore.
Veichle::Veichle(float x, float y, std::vector<float> newDna) {
  // :param: x,y -> Posizione iniziale
  // :param: newDna -> Dna con cui creare il veicolo, opzionale.

  // Se il parametro dna non viene passato, lo inizializzo con valori random
  if (newDna.size() > 0) {
    dna = newDna;
  } else {
    // Inizializzo il dna con pesi a caso
    dna[0] = randomFloat(-5, 5);
    dna[1] = randomFloat(-5, 5);
    dna[2] = randomFloat(1, 100);
    dna[3] = randomFloat(1, 100);
  }

  // La figura deve essere un triangolo quindi setto 3 punti
  triangolo.setPointCount(3);
  // Setto l'origine al centro del triangolo
  triangolo.setOrigin(raggio, raggio / 2);
  // Setto la posizione ai parametri dati
  triangolo.setPosition(x, y);
  triangolo.setOutlineThickness(1);
  // Setto i vertici (in senso orario)
  triangolo.setPoint(0, sf::Vector2f(raggio, 0));
  triangolo.setPoint(1, sf::Vector2f(-raggio, raggio / 2));
  triangolo.setPoint(2, sf::Vector2f(-raggio, -raggio / 2));
}

void Veichle::show(sf::RenderWindow &finestra) {
  finestra.draw(triangolo);
  if (debug) {
    // DEBUG
    // Disegno intorno al triangolo un cerchio di raggio pari alla visuale
    // Disegno una linea di lunghezza proporzionale all'affinità al cibo o al
    // veleno
    sf::RectangleShape rectCibo{sf::Vector2f(dna[0] * 10, 2)};
    rectCibo.setPosition(triangolo.getPosition());
    rectCibo.setFillColor(sf::Color::Green);
    finestra.draw(rectCibo);

    sf::RectangleShape rectVeleno{sf::Vector2f(dna[1] * 10, 1)};
    rectVeleno.setPosition(triangolo.getPosition());
    rectVeleno.setFillColor(sf::Color::Red);
    finestra.draw(rectVeleno);

    sf::CircleShape cerchioCibo{};
    cerchioCibo.setRadius(dna[2]);
    cerchioCibo.setOrigin(dna[2], dna[2]);
    cerchioCibo.setPosition(triangolo.getPosition());
    cerchioCibo.setFillColor(sf::Color(0, 0, 0, 0));
    cerchioCibo.setOutlineThickness(2);
    cerchioCibo.setOutlineColor(sf::Color::Green);
    finestra.draw(cerchioCibo);

    sf::CircleShape cerchioVeleno{};
    cerchioVeleno.setRadius(dna[3]);
    cerchioVeleno.setOrigin(dna[3], dna[3]);
    cerchioVeleno.setPosition(triangolo.getPosition());
    cerchioVeleno.setFillColor(sf::Color(0, 0, 0, 0));
    cerchioVeleno.setOutlineThickness(2);
    cerchioVeleno.setOutlineColor(sf::Color::Red);
    finestra.draw(cerchioVeleno);
  }
}

void Veichle::update() {
  // Aggiornamento da fare ad ogni ciclo

  // Riduco la vita a ogni ciclo
  health -= 0.01;
  // I veicoli scompaiono al calare della vita
  triangolo.setFillColor(sf::Color((1 - health) * 255, health * 255, 0));
  // triangolo.setOutlineColor(sf::Color(255, 255, 255, 255 * health));
  // Setto l'origine delle rotazioni
  triangolo.setOrigin(0, 0);
  // Ruoto nella direzionde di movimento
  float angle = heading(vel);
  triangolo.setRotation(radToDeg(angle));
  // Applico l'accelerazione
  vel += acc;
  // Limito la velocità
  limitVector(vel, velocitalimite);
  // Muovo l'oggetto
  triangolo.move(vel);
  // Resetto l'accelerazione a 0
  multVector(acc, 0);
}

void Veichle::applyForce(sf::Vector2f force) {
  // Aggiunge la forza passata in input all'accelerazione
  // :param: force -> forza da applicare
  acc += force;
}

sf::Vector2f Veichle::seek(sf::Vector2f oggetto) {
  // Restituisce una forza che generata con un algoritmo di steering
  // :param: oggetto -> da cercare
  // :return: vettore che rappresenta la forza di attrazione verso l'oggetto

  // La velocità desiderata è un vettore che punta verso l'oggetto
  sf::Vector2f velIdeale = oggetto - triangolo.getPosition();
  // Limito anche la velocià ideale a quella limite
  limitVector(velIdeale, velocitalimite);
  // Genero una forza di attrazione come velocità attuale - velocità desiderata
  sf::Vector2f attrazione = velIdeale - vel;
  // Limito il modulo della forza
  float limiteForza = 0.1;
  limitVector(attrazione, limiteForza);
  return attrazione;
}

bool Veichle::dead() {
  // Verifica che la vita del veicolo sia finita
  // :return: booleano, vero se il veicolo è morto
  return (health <= 0);
}

sf::Vector2f
Veichle::cercaVicino(std::vector<std::unique_ptr<sf::CircleShape>> &lista, float valoreNutrizionale, float percezione) {
  // Cerca l'oggetto più vicino nella lista passata e lo mangia.
  // :param: lista -> cibi o veleno
  // :param: valoreNutrizionale -> indica l'aumento o diminuzione della vita
  // :param: percezione -> indica la distanza massima a cui il veicolo
  // percepisce l'elemento della lista :return: vettore che indica la forza di
  // attrazione verso l'elemento più vicino nella lista :return: vettore nullo
  // se ha mangiato :return: vettore nullo se la lista è vuota

  // Controllo che la lista non sia vuota
  if (lista.size() > 0) {
    // Cerco il più vicino nella visuale del veicolo
    float distanzaMinima = 1e4;
    auto closest = lista.begin();

    // Itero sulla lista
    for (auto it = lista.begin(); it != lista.end(); ++it) {
      float distanza = dist(triangolo.getPosition(), (*it)->getPosition());

      if (distanza < velocitalimite) {
        // Se mi trovo sull'oggetto, lo mangio e basta
        lista.erase(it--);
        health += valoreNutrizionale;
      } else if (distanza < distanzaMinima) {
        // Altrimenti aggiorno la distanza minima
        closest = it;
        distanzaMinima = distanza;
      }
    }

    // Se sono dentro la visuale creo l'attrazione
    if (distanzaMinima < percezione) {
      sf::Vector2f posizioneVicino = (*closest)->getPosition();
      // Restituisco la forza di attrazione
      return seek(posizioneVicino);
    }
  }

  // Se la lista in input è vuota, oppure il più vicino è fuori dalla visuale
  // restituisco il vettore nullo
  return sf::Vector2f(0, 0);
}

void Veichle::vivi(std::vector<std::unique_ptr<sf::CircleShape>> &cibo, std::vector<std::unique_ptr<sf::CircleShape>> &veleno) {
  // Applica la forza di attrazione generata dal metodo mangia, pesandola in
  // base al dna del veicolo. :param: cibo -> lista di cibo :param: veleno ->
  // lista di veleno

  sf::Vector2f forzaBuona = cercaVicino(cibo, 0.5, dna[2]);
  sf::Vector2f forzaMale = cercaVicino(veleno, -0.75, dna[3]);
  multVector(forzaBuona, dna[0]);
  multVector(forzaMale, dna[1]);
  applyForce(forzaBuona);
  applyForce(forzaMale);
}

void Veichle::edges(sf::RenderWindow &finestra) {
  // Se il veicolo va sui bordi dello schermo, setto la velocità desiderata
  // verso il centro :param: finestra -> finestra su cui disegnare il veicolo
  sf::Vector2f pos = triangolo.getPosition();
  sf::Vector2f sizeFinestra = static_cast<sf::Vector2f>(finestra.getSize());
  float margine = 20.;
  if (pos.x < margine || pos.x > sizeFinestra.x - margine || pos.y < margine || pos.y > sizeFinestra.y - margine) {
    applyForce(seek(sf::Vector2f(sizeFinestra.x / 2, sizeFinestra.y / 2)));
  }
}

std::unique_ptr<Veichle> Veichle::clona() {
  // :return: puntatore unico ad un nuovo veicolo con possibili mutazioni
  std::vector<float> nuovoDna = dna;
  for (auto &gene : nuovoDna) {
    // Vario al massimo di un 10% ogni gene
    gene += randomFloat(-gene / 10, gene / 10);
  }
  std::unique_ptr<Veichle> nuovoVeicolo{new Veichle{
      triangolo.getPosition().x, triangolo.getPosition().y, nuovoDna}};
  return nuovoVeicolo;
}

// Metodi di debug
sf::Vector2f Veichle::getorigin() {
  // :return: origine delle trasformazioni
  return triangolo.getOrigin();
}

sf::Vector2f Veichle::getposition() {
  // :return: posizione del triangolo
  return triangolo.getPosition();
}

sf::Vector2f Veichle::getvelocity() {
  // :return: velocità del veicolo
  return vel;
}

float Veichle::getrotation() {
  // :return: angolo di rotazione attuale
  return triangolo.getRotation();
}
