#include "LecOneExercises.h"
#include <iostream>
#include <string>

int main(int argc, char** argv){
  LecOneExercises L1;
  std::cout<<"Which exercise do you want to run?"<<std::endl;
  int ex;
  std::cin >> ex;
  switch(ex) {    
    case 1: { //base 2 logarithm
        int N;
        std::cout<<"To get Log2(N), Type N: "<<std::endl;
        std::cin>> N;
        int log2 = L1.LogTwo(N); 
        std::cout<<"Log2(N) = " << log2 <<std::endl;
      break;
      }
    case 2: { //char counter
        char c; 
        std::string string; 
        std::cout<<"Type a string: "<<std::endl;
        std::cin>> string;
        std::cout<<"Type which character to count: "<<std::endl;
        std::cin >> c;
        int chCnt = L1.charCount(c, string); 
        std::cout<<"Number of characters in string is: " << chCnt <<std::endl; 
      break;
      }
    case 3: { //regular sum
        int n;
        std::cout<<"Type n and get sum: "<<std::endl;
        std::cin>> n;
        int sum = L1.sum(n); 
        std::cout<<"sum: " << sum <<std::endl;
      break;
      }
    case 4: { //odd sum
        int n;
        std::cout<<"Type n and get odd sum: "<<std::endl;
        std::cin>> n;
        int sum = L1.oddSum(n); 
        std::cout<<"sum: " << sum <<std::endl;
      break;
      }
    case 5: { // sum of even squares
        int n;
        std::cout<<"Type n and get the sum of the first n even numbers squares: "<<std::endl;
        std::cin>> n;
        int squareSum = L1.evenSquares(n); 
        std::cout<<"squares sum: " << squareSum <<std::endl;
      break;
      }
    case 6: { // nth fibonacci number
        int n;
        std::cout<<"Type fibonacci numbr you want to find: "<<std::endl;
        std::cin>> n;
        int fibNum = L1.fib(n); 
        std::cout<<"nth fibonacci number: " << fibNum <<std::endl;
      break;
      }
      case 7: { // char c exists in string s of length l ??
        char c;
        std::string s;
        std::cout<<"Type your string: "<<std::endl;
        std::cin>> s;
        std::cout<<"Type the char you want to find: "<<std::endl;
        std::cin>> c;
        int l = s.size(); 
          if(L1.linear(s, c, l)){
            std::cout<<"There IS a char " << c << " in your string"<<std::endl;
          } else {
            std::cout<<"There is NO char " << c << " in your string"<<std::endl;
          }
          
      break;
      }
      case 8: { // binary search
        std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for(int i = 0; i<= arr.size()-1; i++){
          std::cout<<arr[i]<<", ";
        }
        std::cout<<std::endl;
        int value;
        
        std::cout<<"Type value you want to search for: "<<std::endl;
        std::cin>> value;
        if(L1.binarySearch(arr, value)){
            std::cout<<"value FOUND"<<std::endl;
          } else {
            std::cout<<"value NOT found"<<std::endl;
          }
      break;
      }
    default: {
        std::cout << "Unknown exercise.\n";
      break;
      }
  }
  return 0;
}
