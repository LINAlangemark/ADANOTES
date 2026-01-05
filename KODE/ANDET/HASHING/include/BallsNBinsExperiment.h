#ifndef BALLS_N_BINS_EXPERIMENT_H
#define BALLS_N_BINS_EXPERIMENT_H

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

class BallsNBinsExperiment {
private:
    struct RandomHash {
        size_t a, b, P, M;

        RandomHash(size_t M)
            : P(4294967311ULL), M(M)
        {
            static std::mt19937_64 rng(std::random_device{}());
            std::uniform_int_distribution<size_t> dist(1, P - 1);
            a = dist(rng);
            b = dist(rng);
        }

        size_t operator()(size_t x) const {
            return ((a * x + b) % P) % M;
        }
    };

    static int maxLoadOneChoice(int N, int M);
    static int maxLoadTwoChoices(int N, int M);

public:
    static void runExperiment(int N, int M, int trials);
};

#endif
