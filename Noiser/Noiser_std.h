// Created by yanni on 14.09.2023.
//

#ifndef CYBERTOPIC_ENGINE_1_NOISER_STD_H
#define CYBERTOPIC_ENGINE_1_NOISER_STD_H

#include "../cymath/cymath_main.h"
#include <random>
#include <ctime>

namespace ns
{
    namespace _std
    {
        namespace random
        {
            int rnd1(int seed)
            {
                std::time_t now = std::time(nullptr);
                std::tm data_t;
                localtime_s(&data_t, &now);
                std::mt19937 rng(42 * (data_t.tm_yday + 1) * (data_t.tm_year + 1900) * data_t.tm_sec);
                std::uniform_int_distribution<int> dist(1, 6);
                return dist(rng); // Return the generated random number
            }

            int* rnd1l(int seed, int ilit)
            {
                int* out;
                for (int i = 0;i < ilit;i++)
                {
                    rnd1(seed * i * (i/2));
                }
                return out;
            }

            // Uses The Seed, Time, and the mt19937 random to generate a pseudo-random number.
        } // End of namespace random

        struct noisemap2
        {
            enum types
            {
                perlin_noise,
                white_noise,
                brown_noise,
                pink_noise
            };

            static constexpr int res = 2;
            cy::vector2<float> values[res];
            int type;
        };
    } // End of namespace std
} // End of namespace ns

#endif //CYBERTOPIC_ENGINE_1_NOISER_STD_H
