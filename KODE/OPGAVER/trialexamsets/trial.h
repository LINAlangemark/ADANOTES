#ifndef TRIAL_H
#define TRIAL_H

#include <iostream>
#include <vector>

class Trial {
private:
   
public:
    Trial(); 
    int charCounter(std::string s, char c);
    int bigOh(double N);
    int sumOfDigits(int integer);
    void rotate(int arr[], int k, int arrSize);
};

#endif