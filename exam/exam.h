#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <vector>

class Exam {
private:
   
public:
    Exam(); 
    int LogTwo(int N);
     
    int longestChain();
    int pythagoreanTriplet();
    int myMethod( int N );
    int getNumberEqual(int x[], int n, int val); 
    int changePriority(int fromP, int toP);
    int myMethod1(int arr[], int arrSize);
    std::string mostFrequentWord(std::string s);
    int mostFrequentNum(int nums[], int noOfNums);
    int O_N_mostFrequentNum(int nums[], int n);
    int recursiveSum(int N);
    int binom(int n, int k);
    int evenSquares(int N);
    int oddSum(int N);
    bool isAnagram(const std::string& s1, const std::string& s2);
};

#endif