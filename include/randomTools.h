#ifndef RANDOMTOOLS_H
#define RANDOMTOOLS_H

namespace randomTools {

    // Serie di Tools per la generazione rapida di numeri random
    template<typename T> T randomGenerator(const T& start = 0, const T& stop = 1);
    float randomFloat(float start = 0, float stop = 1);
    int randomInt(int start = 0, int stop = 0);

} // namespace randomTools


#endif
