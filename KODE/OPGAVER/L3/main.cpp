#include "hash.h"
#include "doublyLinkedList.h"
#include <random>
#include <limits>

int main() {
    /*---------------------------------- Exercise 1: Balls'n Bins -- Seperate Chaning ------------------------------------*/ 
  /*  const int table_size = 10007;
    int key_list[table_size];                 
    for (int i = 0; i < table_size; ++i)
        key_list[i] = i;

    Hash hash(table_size, key_list);          
    */
    const int table_size = 11;

    int key_list[table_size];
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, 1'000'000'000);

    for (int i = 0; i < table_size; ++i)
        key_list[i] = dist(rng);

    Hash hash(table_size, key_list);

   // hash.hashMap(key_list);
   // int max = hash.findLargestChain();
   // std::cout<<"max: " << max << std::endl;

    /*---------------------------------- Exercise 2 --- Power of Two Choices*-----------------------------------------------*/
   // hash.powerOfTwoChoices(key_list);
   // int max = hash.findLargestChain();
   // std::cout<<"max: " << max << std::endl;
    
    /*---------------------------------- Exercise 5 ---perfect hashing-----------------------------------------------*/
    Hash hash2((table_size*table_size), key_list);
    hash2.powerOfTwoChoices(key_list);
    int max2 = hash2.findLargestChain();
    std::cout<<"max: " << max2 << std::endl;
    /*---------------------------------- Exercise 1: Balls'n Bins -- Quadratic probing ------------------------------------*/
    /*const int table_size = 93;
    int key_list[table_size];                 
    for (int i = 0; i < table_size; ++i)
        key_list[i] = i;

    Hash hash(table_size, key_list);        */  
    
  /*  const int table_size = 11;
    int key_list[table_size] = {2,1,1,1,1,12,1,41,5,1,1};                 
    Hash hash(table_size, key_list);          
    */
    return 0;
}