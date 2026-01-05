#ifndef P2E_H
#define P2E_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <algorithm>


#include <iostream>
#include <queue>
#include <limits.h>
class P2E{
    private:
        
    public:
        P2E();
        std::string findMostFrequentWord(std::string text);
        void primMST(const std::vector<std::vector<int>> graph); 
        void djikstra(const std::vector<std::vector<int>> adj); 
        void printState(int step, const std::vector<int>& dist, const std::vector<bool>& known, const std::vector<int>& prev);
};

#endif 
