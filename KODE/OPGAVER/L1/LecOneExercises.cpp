#include "LecOneExercises.h"


LecOneExercises::LecOneExercises(){
  std::cout<<"LecOne works"<<std::endl;
}

int LecOneExercises::LogTwo(int N){
  int y = 0;
  int b;
  if(N <= 0) { //N is not positive
    std::cout<<"N is less than 0"<<std::endl;
    return -1; //error
  }
  if (N != 1 && N%2 == 0){
    N = N/2;
    b = LogTwo(N);
    y = 1+b;
    //std::cout<<"y: " <<y << std::endl;
    //std::cout<<"N: " <<N<< std::endl;
    return y; 
    
  } 
  return y; 
}

int LecOneExercises::charCount(char c, std::string string){
  int strLgth = string.size(); //+1??
  int chCnt = 0;
  
  //std::cout<<"c: " << c <<std::endl;
  //std::cout<<"string: " << string <<std::endl;
  
  if(strLgth != 0){ //as long as there is a string
    char strChar = string.back();
    //std::cout<<"strChar: " << strChar <<std::endl;
  if (strChar == c){ //if last character is a correct character
      chCnt++; //increment count
    }  
    string.pop_back(); //pop last element
    //std::cout<<"chCnt: " << chCnt <<std::endl;
    return chCnt + charCount(c, string); //local counter chcnt added to make progress
  }
  return chCnt; //0 when string is empty
  
}

int LecOneExercises::sum(int n){
  int tmpSum;
  if(n != 0){
    tmpSum = n;
    n--;
    return tmpSum + sum(n);
  }
  
  return n;
}

int LecOneExercises::oddSum(int n){
  if(n <= 0){
    return 0; //base case, or non-positive sum
  }
  if(n%2 == 1){ //hvis odd
    return n + oddSum(n-1); //progress
  }else{
      return oddSum(n-1);   //no progress 
  }
}

int LecOneExercises::evenSquares(int n){
   int sqrSum = 0;
   if(n <= 0){
    return sqrSum; //base case, or non-positive sum
  }
  if(n%2 != 1){ //hvis even
    sqrSum = n*n; 
    return sqrSum + evenSquares(n-1); //progress
  }else{
      return evenSquares(n-1);   //no progress 
  }
} 

int LecOneExercises::fib(int n){
  if(n <= 1){ //base case 
    return n; 
  }else{
    return fib(n-1)+fib(n-2); //returnerer summen ned til n = 0
  } 
}

bool LecOneExercises::linear(std::string s, char c, int l){
  //std::cout<<"c: " << c <<std::endl;
  //std::cout<<"string: " << s <<std::endl;
  //std::cout<<"length: " << l <<std::endl;
  if(l <= 0){ 
    return false; //no char in string
  }  
  if (s[l] == c){ //if last character is a correct character (l-1 is passed not l)
  //std::cout<<"current char: " << s[l] <<std::endl;
    return true; 
  }  
  return linear(s, c, l-1); //recursive call
} 

bool LecOneExercises::binarySearch(std::vector<int> arr, int value){
  int size = arr.size();
  int high = size-1;
  int low = 0;
  int mid;
  
  mid = static_cast<int>(size)/2;
  std::cout<<"mid: "<<mid<<std::endl;
  
  if(arr[mid] <= low || arr[mid] >= high){
    return false;
  }
  
  if(arr[mid] < value){ //middle element is smaller than value
      std::vector<int> right(arr.begin() + mid + 1, arr.end()); //remove right side
      return binarySearch(right, value);
  } else if (arr[mid] > value){ //middle element is larger than value
      std::vector<int> left(arr.begin(), arr.begin() + mid); //remove left side
      return binarySearch(left, value);
  } else{ //middle element is equal to value
      return true; //element found
  }
} 
