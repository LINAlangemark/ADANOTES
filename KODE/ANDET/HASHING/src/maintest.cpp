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


int main(int argc, char** argv) {

        std::cout << "---- Exercise 6----\n";
    /*
        size_t N = 10;
        int items[] = {1, 2, 3, 4, 5, 8}; //A W C O E S
        double loadFactor = 0.5;

        ---------- WITH rehashing ----------
        
        HashMap<int, int> hmWithRehash(N, intHash, ProbingMode::LinearProbing, true, loadFactor);

        for (int item : items) {
            hmWithRehash.insert(item, 1);
        }

        std::cout << "Linear Probing Table with Rehashing:\n";
        hmWithRehash.debugPrint();
         */
        
        /* ---------- WITHOUT rehashing ----------
      
        HashMap<int, int> hmWithoutRehash(N, intHash, ProbingMode::LinearProbing, false);

        for (int item : items) {
            hmWithoutRehash.insert(item, 1);
        }

        std::cout << "Linear Probing Table without Rehashing:\n";
        hmWithoutRehash.debugPrint();
  
    */
    /*
    std::cout << "---- Exercise 14----\n";
        size_t tbSize = 11;
        int keys[] = {0, 1, 2, 5, 7, 8};
        HashMap<int, int> hmQuadratic(tbSize, intHash, ProbingMode::QuadraticProbing, false);

        for(int key : keys){
            hmQuadratic.insert(key, 1);
        }
        std::cout << "Quadratic Probing Table:\n";
        hmQuadratic.debugPrint();
        std::cout << "Inserting 1:\n";
        hmQuadratic.insert(12, 1);
        std::cout << "Quadratic Probing Table:\n";
        hmQuadratic.debugPrint();

    
        int a[] = {5,28,7,25,7,9,28,11,67,5,33,28};
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

      

    size_t tbSize = 13;
    int keys[tbSize] = {0};
    for(int i = 0; i <= tbSize-1; i++){
        keys[i] = i*tbSize+3;
        std::cout<<"keys[i]: "<<keys[i]<<std::endl;
    }
 
       HashMap<int, int> hmQuadratic(
        tbSize,
        intHash,
        ProbingMode::QuadraticProbing,
        true,          // enableRehash
        0.4     // evt. eksplicit max load factor
    );
        for(int key : keys){
            hmQuadratic.insert(key, 1);
        }
        std::cout << "Quadratic Probing Table:\n";
        hmQuadratic.debugPrint();
        std::cout << "Inserting 1:\n";
        hmQuadratic.insert(12, 1);
        std::cout << "Quadratic Probing Table:\n";
        hmQuadratic.debugPrint();
    */  


    size_t tbSize = 17;
    int keys[tbSize] = {0};
    for(int i = 0; i <= 8-1; i++){
        keys[i] = i*tbSize+5;
        std::cout<<"keys[i]: "<<keys[i]<<std::endl;
    }
 
       HashMap<int, int> hmQuadratic(
        tbSize,
        intHash,
        ProbingMode::QuadraticProbing,
        false          // enableRehash
           // evt. eksplicit max load factor
    );
        for(int key : keys){
            hmQuadratic.insert(key, 1);
        }
        std::cout << "Quadratic Probing Table:\n";
        hmQuadratic.debugPrint();
    return 0;
}
