#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <algorithm>
#include "stack.h"

class Hash: public Stack{
    private:
        int _table_size;
        
    public:
        explicit Hash(int table_size, int key_list[]); 
        void hashMap(int key_list[]);
        int hashFunc(int key);
        //void place(int key, int index);
        void quadProbe(int key, int index);
};

#endif
