#include "FinalExercises.h"
//#include "hashMap.h"

#include <stdio.h>
#include <string.h>

FinalExercises::FinalExercises(){
    std::cout<<"FinalExercises works"<<std::endl;
  
}

int FinalExercises::logTwo(int N){
    if(N == 0){ //base case
        return -1; //error
    }

    return 1 + logTwo(N/2); //add 1 to keep track of count 
    
}

int FinalExercises::getNumberEqual(int x[], int n, int val){
    if(n < 0){ //base case
        return 0; //no counts
    }

    if(x[n-1] == val){  
        return getNumberEqual(x, n-1, val) + 1; //add 1 to keep track of count 
    }else{
       return getNumberEqual(x, n-1, val);
    }
}

int FinalExercises::sumOfOdds(int N){
    if(N < 0){ //base case
        return 0; //no counts
    }
    if(N%2 != 0){  
        return sumOfOdds(N-2) + N; //add 1 to keep track of count 
    }else{
       return sumOfOdds(N-1);
    }
}