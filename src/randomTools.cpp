#include <random>
#include "../include/randomTools.h"


float randomTools::randomFloat(float start, float stop) {
  // Generatore random di float tra start e stop
  // :param: start -> Valore di inizio (default 0)
  // :param: stop -> Valore di fine (default 1)
  // :return: float random tra start e stop
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<float> distr(start, stop);
  return distr(eng);
}

int randomTools::randomInt(int start, int stop) {
  // Generatore random di interi tra start e stop.
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_int_distribution<int> distr(start, stop);
  return distr(eng);
}
