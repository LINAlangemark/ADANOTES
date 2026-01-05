#ifndef P1EXERCISES_H
#define P1EXERCISES_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <algorithm>

class P1Exercises{
    private:
        
    public:
      P1Exercises();
      /*the algorithm returns the base two logarithm of N, it is a precondition that N is a positive integer and a power of 2 */ 
      int logTwo(int N); 
      /*Returns true if the parameter contains a substring of three consecutive numbers, were the third number is a sum of the two preceding numbers*/ 
      bool additive(std::string s); 
      /* returns 3 values from array, which make a sum closest to a power of two value*/
      std::vector<int> findClosestPot(std::vector<int> arr);
      /*Algoritmen returnerer summen af heltal større end 0 og mindre end eller lig med N, som er dividérbare med 3*/
      int sumDivisibleBy3(int N);
      std::vector<int> isExponent(int Z);
      int oddSquares(int n);
      int majorityVotes(std::vector<int> votes);
      int majorityVotesBoyerMoore(std::vector<int> votes);
      /*Test metode til opgave 2*/
      int myMethod(int N); 
      /*Test metode til opgave 5*/
      int myMethod2(int N);
      /*Test metode til opgave 9*/
      long myMethod3(int n);
      
      
};

#endif
