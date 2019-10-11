//
// Created by Filip Peterek on 11/10/2019.
//

#ifndef SSPU_UKAZKA_2_RANDOM_HPP
#define SSPU_UKAZKA_2_RANDOM_HPP

#include <random>

class Random {

    static std::mt19937_64 rand;

public:

    static uint64_t randUInt(const uint64_t min, const uint64_t max);
    static int64_t randInt(const int64_t min, const int64_t max);
    static bool randBool();

};

#endif //SSPU_UKAZKA_2_RANDOM_HPP
