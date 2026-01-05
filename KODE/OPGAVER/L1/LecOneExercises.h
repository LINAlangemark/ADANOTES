#ifndef LECONEEXERCISES_H
#define LECONEEXERCISES_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <algorithm>

class LecOneExercises{
    private:
        
    public:
      LecOneExercises();
      int LogTwo(int N); //the algorithm returns the base two logarithm of N, it is a precondition that N is a positive integer and a power of 2 
      int charCount(char c, std::string string); //returns number of times char occurs in string    
      int sum(int n); //returns the sum of the first n natural numbers
      int oddSum(int n); //returns the sum of the first n odd natural numbers
      int evenSquares(int n); //returns the sum of he first n even numbers' squares
      int fib(int n); //returns the nth Fibonacci number
      bool linear(std::string s, char c, int l); //returns true if string s with the length 1 contains char c, otherwise false
      bool binarySearch(std::vector<int>, int value); //returns true if value is in arr, otherwise false, the elements in arr are sorted
      
};

#endif
