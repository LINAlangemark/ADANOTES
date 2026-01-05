#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <utility> 


class HashMap {
    private:
    std::vector<std::list<std::pair<std::string, int>>> _buckets;// key-value
    int _tableSize;
    std::vector<int> _chainSizes;

    public:
        HashMap(int _tableSize);
        void insert(std::string word);

        int hashFunc(const std::string &word);
        std::string findMostFrequent();
        int getCount(std::string word);
        
};

#endif