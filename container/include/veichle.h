#ifndef VEICHLE_H
#define VEICHLE_H

#include "randomTools.h"

// Classe veichle
class Veichle {

    private:
      // Angolo (direzione del veicolo)
      float angle{0.};
      sf::ConvexShape triangolo;
      sf::Vector2f vel{randomTools::randomFloat(-5, 5), randomTools::randomFloat(-5, 5)};
      float velocitalimite{5};
      sf::Vector2f acc{0, 0};
      // Dimensione
      float raggio{7.};
      // DNA
      // dna[1] rappresenta l'affinità al cibo
      // dna[2] rappresenta l'affinità al veleno
      // dna[3] rappresenta la percezione al cibo
      // dna[4] rappresenta la percezione al veleno
      std::vector<float> dna{0, 0, 0, 0};
      // Il veicolo può reagire solo ad oggetti all'interno di un cerchio di raggio
      // "" Vita
      float health{1};

      // Ciclo di vita
      void applyForce(sf::Vector2f force);
      sf::Vector2f seek(sf::Vector2f oggetto);
      sf::Vector2f cercaVicino(std::vector<std::unique_ptr<sf::CircleShape>> &lista, float valoreNutrizionale, float percezione);

    public: // Costruttore
      Veichle(float x, float y, std::vector<float> newDna = std::vector<float>{});
      // Disegno
      void show(sf::RenderWindow &finestra);
      void update();
      // Gestione uscita schermo
      void edges(sf::RenderWindow &finestra);
      // Ciclo di vita
      void vivi(std::vector<std::unique_ptr<sf::CircleShape>> &cibo, std::vector<std::unique_ptr<sf::CircleShape>> &veleno);
      bool dead();
      // Riproduzione
      std::unique_ptr<Veichle> clona();
      // Getters
      sf::Vector2f getorigin();
      sf::Vector2f getposition();
      sf::Vector2f getvelocity();
      float getrotation();
      // Variabile di debug
      static bool debug;

};

#endif
