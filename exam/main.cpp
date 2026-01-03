#include <iostream>
#include "exam.h"

int main() {
    Exam e;
    //int chain = e.longestChain();
    //std::cout<<"longest chain: "<< chain << std::endl;

    //int triplet = e.pythagoreanTriplet();
    //std::cout<<"triplet: "<<triplet<<std::endl;
    

    //int N = 16;
    //int x = e.myMethod(N);
    //std::cout<<"N: "<<N<<", x: "<<x <<std::endl;
    
    //int x[] = {7, 4, 1, 3, 5, 6, 4, 8};
    //int n = 8;
    //int val = 4;
    //int occ = e.getNumberEqual(x, n, val);
    //std::cout<<"n: "<<n<<", val: "<<val << ", occ" << occ <<  std::endl;
    
    //int a[] = {7, 4, 1};
    //int arrSize = sizeof(a)/sizeof(a[0]);
    //int x = e.myMethod1(a, arrSize);
    //std::cout<<"x: "<<x <<std::endl;
    //int nums[] = {5,28,7,25,7,9,28,11,67,5,33,28} ;
    //int noOfNums = sizeof(nums)/sizeof(nums[0]);

    //int mostfreqnum = e.O_N_mostFrequentNum(nums,noOfNums);
    //std::cout<<"mostfreqnum: "<<mostfreqnum<<std::endl;
    
    //int N = 5; 
    //int sum = e.recursiveSum(N);
    //std::cout<<"sum: "<<sum<<std::endl;
    
    //exercise 20 -- kombinatorik, vælg 6 cifre fra 1-9 [i stigende rækkefølge]
    //int n = 9; //choose from 1 to n
    //int k = 6; //k times
    //int possiblePasswords = e.binom(n, k);
    //std::cout<<"possiblePasswords: "<<possiblePasswords<<std::endl;
    
    //int N = 9;
    //int evensquares = e.evenSquares(N);
    //std::cout<<"N = "<<N<< ", evensquares: "<<evensquares<<std::endl;

    //int N = 9;
    //int oddsum = e.oddSum(N);
    //std::cout<<"N = "<<N<< ", oddSum: "<<oddsum<<std::endl;

    std::string s1 = "taste";
    std::string s2 = "state";
    bool anneagream = e.isAnagram(s1, s2);
    std::cout<<"s1: "<<s1<<", s2: "<<s2<<"isAnagram = "<<anneagream<<std::endl;
    return 0;
}