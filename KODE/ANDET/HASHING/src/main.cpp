#include "hashMap.h"
#include "BallsNBinsExperiment.h"
#include "CuckooHashMap.h"
#include "HopscotchHashMap.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <random>

/* ---------- Hash Functions ---------- */
size_t stringHash(const std::string& s) {
    size_t h = 0;
    for (char c : s)
        h = 31 * h + c;
    return h;
}

size_t intHash(const int& k) {
    return static_cast<size_t>(k);
}
size_t intHash1(int k) {
    return static_cast<size_t>(k);
}

size_t intHash2(int k) {
    static constexpr double A = 0.6180339887498948482;
    double frac = k * A - std::floor(k * A);
    return static_cast<size_t>(frac * 1e9);
}

/* ---------- TestBenches ---------- */
enum TestBench {
    RUN_ALL = 0,
    STRING_HASHING = 1,
    PROBING = 2,
    BALLS_N_BINS = 3,
    REHASHING = 4,
    CUCKOO = 5,
    HOPSCOTCH = 6
};

int main(int argc, char** argv) {

    int choice = RUN_ALL;
    if (argc > 1) {
        choice = std::atoi(argv[1]);
    }

    switch (choice) {

    case STRING_HASHING:
    case RUN_ALL: {
        /* ============================================================
           STRING HASHING — FIND MOST FREQUENT WORD — SEPERATE CHAINING
           ============================================================ */
        std::cout << "---- STRING HASHING: Most Frequent Word ----\n";

        std::string text =
            "The cattle were running back and forth, but there was no wolf to be seen heard, or smelled, so the shepherd decided to take a little nap in a bed of grass and early summer flowers. Soon he was awakened by a sound he had never heard before.";

        std::vector<char> buffer(text.begin(), text.end());
        buffer.push_back('\0');

        const int tableSize = 211;
        HashMap<std::string, int> wordMap(tableSize, stringHash, ProbingMode::SeparateChaining, false);

        char del[] = " ,.";
        char* cw = strtok(buffer.data(), del);

        while (cw != nullptr) {
            wordMap.insert(cw, 1);
            cw = strtok(nullptr, del);
        }

        auto [word, count] = wordMap.findMaxValue();

        std::cout << "Most frequent word: \"" << word
                  << "\" with count: " << count << "\n";

        if (choice != RUN_ALL) break;
        [[fallthrough]];
    }

    case PROBING: {
        /* ============================================================
         LINEAR AND QUADRATCI PROBING
        ============================================================ */
        size_t tbSize = 11;
        int keys[] = {22, 5, 16, 27, 1, 2,3 ,4, 7, 8, 10};

        /*---------- Linear Probing ----------*/
        HashMap<int, int> hmLinear(tbSize, intHash, ProbingMode::LinearProbing, false);

        for(int key : keys){
            hmLinear.insert(key, 1);
        }
        std::cout << "Linear Probing Table:\n";
        hmLinear.debugPrint();

        /*---------- Quadratic  Probing ----------*/
        HashMap<int, int> hmQuadratic(tbSize, intHash, ProbingMode::QuadraticProbing, false);

        for(int key : keys){
            hmQuadratic.insert(key, 1);
        }
        std::cout << "Quadratic Probing Table:\n";
        hmQuadratic.debugPrint();

        if (choice != RUN_ALL) break;
        [[fallthrough]];
    }

    case BALLS_N_BINS: {
        /* ============================================================
           BALLS N' BINS — POWER OF TWO CHOICES
           ============================================================ */
        std::cout << "---- BALLS N' BINS ----\n";

        BallsNBinsExperiment::runExperiment(97, 97, 100);
        BallsNBinsExperiment::runExperiment(10007, 10007, 50);
        BallsNBinsExperiment::runExperiment(32749, 32749, 50);

        if (choice != RUN_ALL) break;
        [[fallthrough]];
    }

    case REHASHING: {
        /* ============================================================
         REHASHING WITH LOAD FACTOR
        ============================================================ */
        size_t N = 16;
        int items[] = {22, 5, 16, 27, 1, 2,3 ,4, 7, 8, 10, 11, 33, 28, 12, 9};
        double loadFactor = 0.6;

        /* ---------- WITH rehashing ---------- */
        HashMap<int, int> hmWithRehash(N, intHash, ProbingMode::LinearProbing, true, loadFactor);

        for (int item : items) {
            hmWithRehash.insert(item, 1);
        }

        std::cout << "Linear Probing Table with Rehashing:\n";
        hmWithRehash.debugPrint();

        /* ---------- WITHOUT rehashing ---------- */
        HashMap<int, int> hmWithoutRehash(N, intHash, ProbingMode::LinearProbing, false);

        for (int item : items) {
            hmWithoutRehash.insert(item, 1);
        }

        std::cout << "Linear Probing Table without Rehashing:\n";
        hmWithoutRehash.debugPrint();

        if (choice != RUN_ALL) break;
        [[fallthrough]];
    }
    
    case CUCKOO: {
        /* ============================================================
        CUCKOO HASHING
        ============================================================ */
        std::cout << "Cuckoo Hashing:\n";
        CuckooHashMap<int, int> cuckoo(
            11,
            [](const int& x){ return intHash1(x); },
            [](const int& x){ return intHash2(x); }
        );

        int keys[] = {22, 5, 16, 27, 1, 2, 3, 4, 7, 8, 10};

        for (int k : keys)
            cuckoo.insert(k, 1);

        cuckoo.debugPrint();

        if (choice != RUN_ALL) break;
        [[fallthrough]];
    }
    case HOPSCOTCH: {
        /* ============================================================
        HOPSCOTCH HASHING
        ============================================================ */
        std::cout << "Hopscotch Hashing:\n";

        HopscotchHashMap<int, int> hop(11, intHash);

        int keys[] = {22, 5, 16, 27, 1, 2, 3, 4, 7, 8, 10};

        for (int k : keys)
            hop.insert(k, 1);

        hop.debugPrint();

        if (choice != RUN_ALL) break;
        [[fallthrough]];
    }

    default:
        std::cerr << "Invalid test case.\n";
        break;
    }

    return 0;
}
