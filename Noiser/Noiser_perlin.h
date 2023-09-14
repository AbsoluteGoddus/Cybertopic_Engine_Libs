//
// Created by yanni on 14.09.2023.
//

#ifndef CYBERTOPIC_ENGINE_1_NOISER_PERLIN_H
#define CYBERTOPIC_ENGINE_1_NOISER_PERLIN_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>

namespace ns {

    class PerlinNoise {
    public:
        PerlinNoise(long int seed);
        double noise(double x, double y);

    private:
        int* p;
        double fade(double t);
        double lerp(double t, double a, double b);
        double grad(int hash, double x, double y);
    };

    PerlinNoise::PerlinNoise(long int seed) {
        p = new int[512];

        std::default_random_engine engine(seed);
        std::uniform_int_distribution<int> distribution(0, 255);

        // Initialize permutation table with random values
        for (int i = 0; i < 256; i++) {
            p[i] = p[i + 256] = distribution(engine);
        }
    }

    double PerlinNoise::noise(double x, double y) {
        // Determine grid cell coordinates
        int X = (int)floor(x) & 255;
        int Y = (int)floor(y) & 255;

        // Relative coordinates within the cell
        x -= floor(x);
        y -= floor(y);

        // Fade curves for smooth interpolation
        double u = fade(x);
        double v = fade(y);

        // Hash coordinates of the 4 grid corners
        int A = p[X] + Y;
        int B = p[X + 1] + Y;

        // Interpolate the gradients
        double gradAA = grad(p[A], x, y);
        double gradBA = grad(p[B], x - 1, y);
        double gradAB = grad(p[A + 1], x, y - 1);
        double gradBB = grad(p[B + 1], x - 1, y - 1);

        // Interpolate along x-axis, then y-axis
        double lerpX1 = lerp(u, gradAA, gradBA);
        double lerpX2 = lerp(u, gradAB, gradBB);
        double result = lerp(v, lerpX1, lerpX2);

        return result;
    }

    double PerlinNoise::fade(double t) {
        return t * t * t * (t * (t * 6 - 15) + 10);
    }

    double PerlinNoise::lerp(double t, double a, double b) {
        return a + t * (b - a);
    }

    double PerlinNoise::grad(int hash, double x, double y) {
        int h = hash & 15;   // Convert low 4 bits of hash code into 12 gradient directions
        double u = h < 8 ? x : y;
        double v = h < 4 ? y : (h == 12 || h == 14 ? x : 0);
        return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
    }
}
#endif //CYBERTOPIC_ENGINE_1_NOISER_PERLIN_H
