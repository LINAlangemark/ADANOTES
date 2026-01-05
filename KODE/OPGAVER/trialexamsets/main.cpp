#include <iostream>
#include "trial.h"

int main() {
    Trial t;
    
    /* -------------- Exercise 1 ----------------
    std::string s = "banana";
    char c = 'a';
    int charCount = t.charCounter(s, c);
    std::cout<<"String: "<<s<<", char: "<< c<<", charCount = "<<charCount<<std::endl;
    */

    /*-------Exercise 2-------
    double N = 16; 
    int O = t.bigOh(N);
    std::cout<<"O: "<<O<<std::endl;
    */
    
    /*-------Exercise 3-------
    int integer = 1024;
    int sum = t.sumOfDigits(integer);
    std::cout<<"sum: "<<sum<<std::endl;
    */
    
    /*-------Exercise 4-------*/
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    std::cout<<"array before"<<std::endl;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
        for(int i = 0; i < arrSize; i++){
        std::cout<<arr[i];
    }
    std::cout<<std::endl;

    int k = 3;
    t.rotate(arr, k, arrSize);

    return 0;
};