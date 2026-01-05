#include "P1Exercises.h"
#include <iostream>
#include <string>

int main(int argc, char** argv){
  P1Exercises P1;
  /*-------------------------ASSIGNMENT PRINTS----------------------------*/
    int N;
    
    std::cout<<"------ OPGAVE 1 ------"<<std::endl;
    
    N = 8;    
    std::cout<<"N: "<< N << std::endl;
    int sum = P1.oddSquares(N); 
    std::cout<<"odd squares sum of N = " << sum <<std::endl;

    std::cout<<"------ OPGAVE 2 ------"<<std::endl;
    std::cout<<"see document for solution"<<std::endl;
    /* N = 10;
    std::cout<<"N: "<< N << std::endl;
    int x_y = P1.myMethod(N);
    std::cout << "x + y = " << x_y <<std::endl; 
    N = 20;
    std::cout<<"N: "<< N << std::endl;
    x_y = P1.myMethod(N);
    std::cout << "x + y = " << x_y <<std::endl; 
    N = 40;
    std::cout<<"N: "<< N << std::endl;
    x_y = P1.myMethod(N);
    std::cout << "x + y = " << x_y <<std::endl; */

    std::cout<<"------ OPGAVE 3 ------"<<std::endl;
  
    std::string string = "82842605"; 
    std::cout<<"String of numbers: "<< string << std::endl;
    bool bb = P1.additive(string);
    std::cout<<"Method returned: "<< bb << std::endl;
  
    std::cout<<"------ OPGAVE 4 ------"<<std::endl;
    std::vector<int> arr = {23,56,22,11,65,89,3,44,87,910,45,35,98}; 
    std::cout<<"original array: "<<std::endl;
    for(int i = 0; i <= arr.size(); i++){
        std::cout<<arr[i] << ", ";
    }
    std::cout<<std::endl;

    std::vector<int> arr2 = P1.findClosestPot(arr);
    std::cout<<"returned array: "<<std::endl;
    for(int i = 0; i <= arr2.size()-1; i++){
        std::cout<<arr2[i] << ", ";
    }
    std::cout<<std::endl;

    std::cout<<"------ OPGAVE 5 ------"<<std::endl;
    std::cout<<"see document for solution"<<std::endl;
    /*int x;
    std::cout<<"N: "<< 20 << std::endl;
    x = P1.myMethod2(20);
    std::cout << "x  " << x <<std::endl; 
    std::cout<<"N: "<< 40 << std::endl;
    x = P1.myMethod2(40);  
    std::cout << "x  " << x <<std::endl; 

    std::cout<<"N: "<< 80 << std::endl;
    x = P1.myMethod2(80);  
    std::cout << "x  " << x <<std::endl;*/

    std::cout<<"------ OPGAVE 6 ------"<<std::endl;
    N = 12;
    std::cout<<"N: "<< N << std::endl;
    int sum3 = P1.sumDivisibleBy3(N); 
    std::cout<<"sum3(N) = " << sum3 <<std::endl;
    N = 14;
    std::cout<<"N: "<< N << std::endl;
    sum3 = P1.sumDivisibleBy3(N); 
    std::cout<<"sum3(N) = " << sum3 <<std::endl;

    std::cout<<"------ OPGAVE 7 ------"<<std::endl;
    int Z = 6561;
    std::cout<<"Z: "<< Z << std::endl;
    std::vector<int> ZZ = P1.isExponent(Z); 
    std::cout<<"Z = " << ZZ[0] << "^" << ZZ[1] <<std::endl;

    /*
    Z = 
    std::cout<<"Z: "<< Z << std::endl;
    std::vector<int> ZZ = P1.isExponent(Z); 
    std::cout<<"Z = " << ZZ[0] << "^" << ZZ[1] <<std::endl;
    */
    std::cout<<"------ OPGAVE 8 ------"<<std::endl;
    std::cout<<"see document for solution"<<std::endl;

    std::cout<<"------ OPGAVE 9 ------"<<std::endl;
    std::cout<<"see document for solution"<<std::endl;
    /*N = 5;
    std::cout<<"N: "<< N << std::endl;
    long ret = P1.myMethod3(N);
    std::cout << "returned: " << ret <<std::endl; */


    std::cout<<"------ OPGAVE 10 ------"<<std::endl;
    N = 32;
    std::cout<<"N: "<< N << std::endl;      
    int log2 = P1.logTwo(N); 
    std::cout<<"Log2(N) = " << log2 <<std::endl;
    N = 4096;
    std::cout<<"N: "<< N << std::endl;      
    log2 = P1.logTwo(N); 
    std::cout<<"Log2(N) = " << log2 <<std::endl;


    std::cout<<"------ OPGAVE 11 ------"<<std::endl;
    std::vector<int> votes = {7,4,3,5,3,1,6,4,5,1,7,5};
    std::cout<<"original votes: "<<std::endl;
      for(int i = 0; i <= votes.size(); i++){
          std::cout<<votes[i] << ", ";
      }
    std::cout<<std::endl;
    int bestCandidate = P1.majorityVotes(votes);
    std::cout<<"returned = " << bestCandidate <<std::endl;

    std::cout<<"-----------------------"<<std::endl;
    votes = {7,7,7,7,7,7,6,4,5,1,7,5};
    std::cout<<"original votes: "<<std::endl;
    for(int i = 0; i <= votes.size(); i++){
        std::cout<<votes[i] << ", ";
    }
      std::cout<<std::endl;
    bestCandidate = P1.majorityVotes(votes);
    std::cout<<"returned = " << bestCandidate <<std::endl;

    std::cout<<"------ OPGAVE 11: Boyer Moore ------"<<std::endl;
    votes = {7,4,3,5,3,1,6,4,5,1,7,5};
    std::cout<<"original votes: "<<std::endl;
      for(int i = 0; i <= votes.size(); i++){
          std::cout<<votes[i] << ", ";
      }
    std::cout<<std::endl;
    bestCandidate = P1.majorityVotesBoyerMoore(votes);
    std::cout<<"returned = " << bestCandidate <<std::endl;

    std::cout<<"-----------------------"<<std::endl;
    votes = {7,7,7,7,7,7,6,4,5,1,7,5};
    std::cout<<"original votes: "<<std::endl;
    for(int i = 0; i <= votes.size(); i++){
        std::cout<<votes[i] << ", ";
    }
      std::cout<<std::endl;
    bestCandidate = P1.majorityVotesBoyerMoore(votes);
    std::cout<<"returned = " << bestCandidate <<std::endl;


  /*----------------------------TEST PRINTS-------------------------------*/
  
  std::cout<<"Which exercise do you want to run?"<<std::endl;
  int ex;
  std::cin >> ex;
  switch(ex) {    
    case 10: { //base 2 logarithm
        int N;
        std::cout<<"To get Log2(N), Type N: "<<std::endl;
        std::cin>> N;
        int log2 = P1.logTwo(N); 
        std::cout<<"Log2(N) = " << log2 <<std::endl;
      break;
      }
    case 3: { //char counter
        char c; 
        std::string string; 
        std::cout<<"Type a string of numbers: "<<std::endl;
        std::cin>> string;
        bool bb = P1.additive(string);
        std::cout<<"returned: "<< bb << std::endl;
      break;
      }
    case 4: { 
        std::vector<int> arr = {23,56,22,11,65,89,3,44,87,910,45,35,98}; 
        std::cout<<"original array: "<<std::endl;
        for(int i = 0; i <= arr.size(); i++){
            std::cout<<arr[i] << ", ";
        }
        std::cout<<std::endl;
        std::vector<int> arr2 = P1.findClosestPot(arr);
        std::cout<<"returned array: "<<std::endl;
        for(int i = 0; i <= arr2.size()-1; i++){
            std::cout<<arr2[i] << ", ";
        }
        std::cout<<std::endl;
        std::cout<<"change array from main.cpp"<<std::endl;
        break;
      }
    case 6: { 
        int N;
        std::cout<<"Type N: "<<std::endl;
        std::cin>> N;
        int log2 = P1.sumDivisibleBy3(N); 
        std::cout<<"sum(N) = " << log2 <<std::endl;
      break;
      }
    case 7: {
        int Z;
        std::cout<<"Type Z: "<<std::endl;
        std::cin>> Z;
        std::vector<int> ZZ = P1.isExponent(Z); 
        std::cout<<"Z = " << ZZ[0] << "^" << ZZ[1] <<std::endl;
      break;
      }
    case 1: { 
        int Z;
        std::cout<<"Type num: "<<std::endl;
        std::cin>> Z;
        int sum = P1.oddSquares(Z); 
        std::cout<<"sum = " << sum <<std::endl;
      break;
      }
    case 11: { 
        std::vector<int> votes = {7,4,3,5,3,1,6,4,5,1,7,5};
        //votes = {7,7,7,7,7,7,6,4,5,1,7,5};
        int bestCandidate = P1.majorityVotes(votes);
        std::cout<<"bestCandidate = " << bestCandidate <<std::endl;
        std::cout<<"change votes from main.cpp"<<std::endl;
      break;
      }
    case 2: { 
       std::cout<<"see document for solution"<<std::endl;
      break;
    }
    case 5: { 
      std::cout<<"see document for solution"<<std::endl;
      break;
    }
   case 8: { 
       std::cout<<"see document for solution"<<std::endl;
      break;
    }
   case 9: { 
       std::cout<<"see document for solution"<<std::endl;
      break;
    }
     
    default: {
        std::cout << "not an exercise.\n";
      break;
      }
  }
      return 0;
}
