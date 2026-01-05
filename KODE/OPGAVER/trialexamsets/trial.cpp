#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "trial.h"

Trial::Trial(){
    std::cout<<"trial"<<std::endl;
}


int Trial::charCounter(std::string s, char c){
    if(s.empty()){
        return 0; //base case
    }
    
    char cs = s.back(); //save last char in s
    s.pop_back(); //pop last char in s
    
    if(cs == c){ 
        return 1 + charCounter(s, c);
    }

    return charCounter(s, c);
}

int Trial::bigOh(double N){
    long x = 0; long y = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < pow(log(N),2); j++){
            for (int k = 0; k <= sqrt(N); k++){
                x++;
            }
        }
            i += i;
        }
    
    for (long k = 0; k < N*sqrt(N); k++) //for-loop nummer 2
        y++;
        std::cout<< x << " " << y<<std::endl;
    return x+y;
} 

int Trial::sumOfDigits(int integer){
    if(!integer){
        return 0;
    }
    int digit = integer % 10;
    integer/=10;
    return digit + sumOfDigits(integer);
}

void Trial::rotate(int arr[], int k, int arrSize){
    int tmp; 
    for(int i = 0; i < k; i++){   
        tmp = arr[i];
        arr[i] = arr[k+i+1];
        arr[k+i+1] = tmp;
        
        for(int i = 0; i < arrSize; i++){
            std::cout<<arr[i];
        }
        std::cout<<std::endl;
    }

}