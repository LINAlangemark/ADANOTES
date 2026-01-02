#include "BallsNBinsExperiment.h"

int BallsNBinsExperiment::maxLoadOneChoice(int N, int M) {
    std::vector<int> load(M, 0);
    RandomHash h(M);

    int mx = 0;
    for (int ball = 0; ball < N; ++ball) {
        size_t b = h(ball);
        mx = std::max(mx, ++load[b]);
    }
    return mx;
}

int BallsNBinsExperiment::maxLoadTwoChoices(int N, int M) {
    std::vector<int> load(M, 0);
    RandomHash hA(M);
    RandomHash hB(M);

    int mx = 0;
    for (int ball = 0; ball < N; ++ball) {
        size_t b1 = hA(ball);
        size_t b2 = hB(ball);
        size_t chosen = (load[b1] <= load[b2]) ? b1 : b2;
        mx = std::max(mx, ++load[chosen]);
    }
    return mx;
}

void BallsNBinsExperiment::runExperiment(int N, int M, int trials) {
    long long sum1 = 0, sum2 = 0;
    int worst1 = 0, worst2 = 0;

    for (int t = 0; t < trials; ++t) {
        int a = maxLoadOneChoice(N, M);
        int b = maxLoadTwoChoices(N, M);
        sum1 += a;
        sum2 += b;
        worst1 = std::max(worst1, a);
        worst2 = std::max(worst2, b);
    }

    std::cout << "N=" << N << " M=" << M << " trials=" << trials << "\n";
    std::cout << "Uniform (1 choice): avg max load = "
              << double(sum1) / trials
              << ", worst = " << worst1 << "\n";
    std::cout << "Two choices: avg max load = "
              << double(sum2) / trials
              << ", worst = " << worst2 << "\n\n";
}
