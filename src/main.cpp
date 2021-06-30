// Librerie di sfml
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

// Librerie standard
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Classe personale
#include "../include/veichle.h"
#include "../include/utilities.h"

using namespace utilities;

std::string percorso_font{"../font/arial.ttf"};

int main() {

  // Variabili di ambiente
  int veicoliIniziali{200}, ciboIniziale{300}, velenoIniziale{300};
  float probNuovoCibo{0.1}, probNuovoVeleno{0.01}, probClonare{0.005};
  // ---------------------------------- Operazioni preparatorie al main loop ------------------------------------- //

  sf::RenderWindow finestra(sf::VideoMode(900, 900), "Evolution", sf::Style::Close | sf::Style::Titlebar);

  // Creo array di veicoli
  std::vector<std::unique_ptr<Veichle>> veicoli;
  for (int i = 0; i < veicoliIniziali; ++i) {
    veicoli.push_back(std::unique_ptr<Veichle>{new Veichle(300, 300)});
  }

  // Creo array di cibo e veleno
  std::vector<std::unique_ptr<sf::CircleShape>> cibi;
  for (int i = 0; i < ciboIniziale; ++i) {
    cibi.push_back(creaCibo(finestra, true));
  }
  std::vector<std::unique_ptr<sf::CircleShape>> veleno;
  for (int i = 0; i < velenoIniziale; ++i) {
    veleno.push_back(creaCibo(finestra, false));
  }

  // Nota: I puntatori sono necessari perché è necessario eliminare i gli
  // oggetti dalle varie liste ed eliminarli dalla memoria. Se non usassi i
  // puntatori non potrei usare le operazioni di insert ed erase sulla lista.

  // Inizio a misurare il tempo
  std::chrono::steady_clock::time_point timeStart = std::chrono::steady_clock::now();
  // Variabile bool per fine simulazione
  bool finito{false};
  std::string tempoFinale = "";
  // Conto i loop
  int loopCounter{0};

  // ------------------------------------------------- Main loop
  // ------------------------------------------------
  while (finestra.isOpen()) {

    // Misuro il tempo a ogni loop
    std::chrono::steady_clock::time_point timeEnd = std::chrono::steady_clock::now();
    std::string tempo = std::to_string(std::chrono::duration_cast<std::chrono::seconds>(timeEnd - timeStart).count());

    finestra.setFramerateLimit(60);
    // Gestione eventi
    sf::Event ev;
    while (finestra.pollEvent(ev)) {
      switch (ev.type) {
      case sf::Event::Closed:
        finestra.close();
        break;

      case sf::Event::KeyPressed:
        // Se premo d sulla tastiera attivo o disattivo la debug mode dei
        // veicoli
        if (ev.key.code == sf::Keyboard::D) {
          Veichle::debug = !Veichle::debug;
        }
        break;
      }
    }

    // Bassa probabilità di generare cibo o veleno in posizione random sullo
    // schermo
    if (randomTools::randomFloat() < probNuovoCibo) {
      cibi.push_back(creaCibo(finestra, true));
    }
    if (randomTools::randomFloat() < probNuovoVeleno) {
      veleno.push_back(creaCibo(finestra, false));
    }

    // --------------------------------------------- Operazioni di disegno ------------------------------------- //

    finestra.clear();

    // --------------------------------------------- Loop sui veicoli ------------------------------------------- //

    for (auto i = veicoli.begin(); i != veicoli.end(); ++i) {
      // l'oggetto *i rappresenta veicoli[i]
      (*i)->edges(finestra);
      (*i)->vivi(cibi, veleno);
      (*i)->update();
      (*i)->show(finestra);

      // Probabilià di clonare
      if (randomTools::randomFloat() < probClonare) {
        i = veicoli.insert(i, (*i)->clona());
        i++;
      }

      if ((*i)->dead()) {
        // Se l'elemento i-simo è morto, lo elimino.
        // Inoltre creo un cibo nella posizione
        // i-- restituisce i a erase e poi decrementa. Così elimino l'elemento
        // ma non salto niente
        cibi.push_back(creaCibo(finestra, true, (*i)->getposition()));
        veicoli.erase(i--);
      }
    }

    // ---------------------------------------------- Disegno info, veleni e cibi --------------------------------//

    // Definisco il font per testo a schermo
    sf::Font font;
    if (!font.loadFromFile(percorso_font)) {
      throw("Errore nel caricare il font");
    }

    // Scrivo le info sullo schermo
    finestra.draw(creaTesto(font, "Alive: " + std::to_string(veicoli.size()), 24));
    finestra.draw(creaTesto(font, "Elapsed time: " + tempo + "s", 15, sf::Vector2f{0, 30}));
    finestra.draw(creaTesto(font, "Loops elapsed: " + std::to_string(loopCounter), 15, sf::Vector2f{0, 50}));
    finestra.draw(creaTesto(font, "Food: " + std::to_string(cibi.size()), 15, sf::Vector2f{0, 70}));
    finestra.draw(creaTesto(font, "Poison: " + std::to_string(veleno.size()), 15, sf::Vector2f{0, 90}));
    finestra.draw(creaTesto(font, "D to show debug info", 15, sf::Vector2f{static_cast<float>(finestra.getSize().x - 200), static_cast<float>(finestra.getSize().y - 30)}));

    // Se la simulazione è finita scrivo a schermo il tempo di sopravvivenza
    // della specie
    if (veicoli.size() == 0 && !finito) {
      tempoFinale = tempo;
      finito = true;
    }
    if (tempoFinale != "") {
      finestra.draw(creaTesto(font, "They lived for: " + tempoFinale + "s", 15,
                              sf::Vector2f{0, 110}));
    }

    // Disegno i cibi
    for (auto &cibo : cibi) {
      finestra.draw(*cibo);
    }

    // Disegno i veleni
    for (auto &vel : veleno) {
      finestra.draw(*vel);
    }

    finestra.display();

    ++loopCounter;
  }
}
