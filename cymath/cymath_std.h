//
// Created by yanni on 12.09.2023.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
#ifndef CYBERTOPIC_ENGINE_1_CYMATH_STD_H
#define CYBERTOPIC_ENGINE_1_CYMATH_STD_H

#include <cmath>

namespace cy
{
    template <typename t>
    struct vector2
    {
        t x, y;
    };

    template <typename t>
    struct vector3
    {
        t x, y, z;
    };

    template <typename t>
    struct vector4
    {
        t x, y, z, w;
    };

    namespace math
    {
        namespace std
        {
            char mode[4] = "CBF";
            long double MBF_DOUBLE[100];
            long int MBF_INT[100];
            int ACC; // The Accuracy of All the standard cymath functions

            double pi()
            {
                return 3.1419;
            }
        }
    }

    struct sciNot {
        long double Mantissa;
        int exponent;

        // Constructor for initializing Mantissa and exponent
        sciNot(long double m, int e) : Mantissa(m), exponent(e) {}
        sciNot() {}
        // Function to convert a decimal number to sciNot
        static sciNot cnv_sciNot(long double x) {
            if (x == 0.0) {
                return sciNot(0.0, 0); // Special case: zero is represented as (0.0, 0)
            }

            int exp = static_cast<int>(std::floor(std::log10(std::abs(x))));
            long double mantissa = x / std::pow(10.0, static_cast<double>(exp));

            return sciNot(mantissa, exp);
        }

        // Function to convert a sciNot to a decimal number
        long double cnv_dec() const {
            return Mantissa * std::pow(10.0, static_cast<double>(exponent));
        }
    };
}

#endif //CYBERTOPIC_ENGINE_1_CYMATH_STD_H

#pragma clang diagnostic pop