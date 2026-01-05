
#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <algorithm>
#include "node.h"
#include "doublyLinkedList.h"

class Hash: public DoublyLinkedList{
    private:
        int _tableSize;
        std::vector<DoublyLinkedList> _buckets;
        std::vector<int> _chainSizes;

    public:
        Hash(int tableSize, int keyList[]); 
        void hashMap(int keyList[]);
        int hashFunc(int key);
        int secondHashFunc(int key);
        void rehash();
        void hashMap_random_one_choice(std::size_t balls); 
        int findLargestChain();
        float findAverageNumberOfCollisions();
        void powerOfTwoChoices(int keyList[]);
        //void place(int key, int index);
        //void quadProbe(int key, int index);
};

#endif