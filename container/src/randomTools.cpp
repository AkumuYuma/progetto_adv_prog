#include <random>
#include "../include/randomTools.h"


template <typename T>
T randomTools::randomGenerator(const T& start, const T& stop) {
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<> distr(start, stop);
  return static_cast<T>( distr(eng) );
}

float randomTools::randomFloat(float start, float stop) {
  // Generatore random di float tra start e stop
  // :param: start -> Valore di inizio (default 0)
  // :param: stop -> Valore di fine (default 1)
  // :return: float random tra start e stop
  /* std::random_device rd; */
  /* std::default_random_engine eng(rd()); */
  /* std::uniform_real_distribution<float> distr(start, stop); */
  /* return distr(eng); */
  return randomGenerator(start, stop);
}

int randomTools::randomInt(int start, int stop) {
  // Generatore random di interi tra start e stop.
  /* std::random_device rd; */
  /* std::default_random_engine eng(rd()); */
  /* std::uniform_int_distribution<int> distr(start, stop); */
  /* return distr(eng); */
  return randomGenerator(start, stop);
}
