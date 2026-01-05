#include "P1Exercises.h"
#include <math.h>
P1Exercises::P1Exercises(){
  std::cout<<"P1 works"<<std::endl;
}

int P1Exercises::logTwo(int N){
    if (N == 1){ // 2^0 = 1
        return 0;
    }
    if(N <= 0||N%2 != 0){
        return -1;  //error
    }

    int b = logTwo(N/2); //divide and conquer recursive call
    int y = b+1; 
    
    return y;  
}

bool P1Exercises::additive(std::string s){
    if(s.size() < 3){ //as long as there is a string of at least 3
        return false;
    }

    int first = s[0]- '0'; //48 is ascii value of zero
    int second = s[1]- '0';
    int third = s[2]- '0';

    if(third == second + first){ //condition met
        return true;
    }
    return additive(s.substr(1)); //progress 
}


std::vector<int> P1Exercises::findClosestPot(std::vector<int> arr){
    int arrSize = arr.size(); 
    if(arrSize == 0){ //as long as there is a string
        return {-1}; //error?
    }
    
    /*største potens*/
    int maxElement = *std::max_element(arr.begin(), arr.end()); //value of
    int potMax = maxElement*3; //hvis der er 3 af den samme maks værdi

    /*pot-2 array*/
    std::vector<int> potTwo;
    int inc = 0;
    int power = 0;
    while( power <= potMax){
        power = pow(2, inc);
        potTwo.push_back(power);
        //std::cout<<"power: "<<power<<std::endl;
        inc++;
    }

    /* init return array*/
    int bestPower = potTwo[0];
    int closestSum = arr[1]+arr[2]+arr[3];
    int bestDiff = closestSum - bestPower;
    std::vector<int> clstSumArr = {arr[1], arr[2], arr[3], closestSum}; 

    /*find closest sum*/ 
    for(int i = 0; i <= arrSize-1; i++){
        for(int j = 0; j <= arrSize-1; j++){
            for(int k = 0; k <= arrSize-1; k++){

                    if(arr[i] != arr[j] && arr[i] != arr[k] && arr[j] != arr[k]){ //dont use same number twice
                        
                        int sum = arr[i] + arr[j] + arr[k];
                        
                        for(int power : potTwo){ //check against each power
                            
                            int diff = abs(sum - power); //get positive difference
                            
                            if(diff < bestDiff){
                                bestDiff = diff; //update best difference
                                clstSumArr = {arr[i], arr[j], arr[k], power}; 
                            }
                            
                        }
                    }

                  
            }

        }   
    }   
    

    return clstSumArr;

}

int P1Exercises::sumDivisibleBy3(int N) {
    if (N < 3){
        return 0; // base case
    }            

    if (N % 3 == 0){
        return N + sumDivisibleBy3(N - 3); //now we can just remove 3 each time
    }

    return sumDivisibleBy3(N - 1); //progress
}

std::vector<int> P1Exercises::isExponent(int Z){
    if(Z > 100000 || Z <= 0){
        return {-1, -1}; //error
    }
    /*initialisere værdier*/
    int minX = 3; //for X > 2
    int minY = 3; //fordi Y > 2
    
    int maxX = 46; //for X³ < Z = 100 000
    int maxY = 10; //for (X = 3); 3^10 < Z = 100 000
    
    for(int y = minY; y <= maxY; y++){ 
        for(int x = maxX; x>=minX; x--){ // decrement for at finde største x (start i maxx)
            if(Z == pow(x, y)){
                return {x, y}; 
            } else if(pow(x, y) > Z){ //prøv mindre x værdi 
                continue;
            }
        }
    }
    return {-1, -1}; //ingen løsning
}

int P1Exercises::oddSquares(int N){
   int sqrSum = 0;
   if(N <= 0){
    return 0; //base case, or non-positive sum
  }
  if((N & 1) == 0){ //if LSB is 0 then n is even
    N--;
  }
  return N*N + oddSquares(N-2); //only recursive on odd squares
} 

int P1Exercises::majorityVotes(std::vector<int> votes){
    if(votes.empty()){ 
        return -1; //no votes or candidates
    }
    int nVotes = votes.size(); //length of array

    /*initilize each candidate to 0 votes*/
    int nCandidates = *std::max_element(votes.begin(), votes.end());
    std::vector<int> voteCounts(nCandidates + 1, 0);
    
    /*add up votes*/
    for (int vote : votes){
        if(vote >= 0 && vote <= nCandidates){ //can only vote for "valid" candidates
            voteCounts[vote]++;
        }
    }

    /*find best candidate*/
    auto it = std::max_element(voteCounts.begin(), voteCounts.end());
    int bestCandidate = (int)std::distance(voteCounts.begin(), it);
    int maxVotes  = *it;
    
    std::cout<<"bestCandidate: "<<bestCandidate<<std::endl;
    std::cout<<"maxVotes: "<<maxVotes<<std::endl;

    /*more than 50% of votes?*/
    return (maxVotes > nVotes / 2) ? bestCandidate : -1;
}

int P1Exercises::majorityVotesBoyerMoore(std::vector<int> votes){
  if(votes.empty()){ 
        return -1; //no votes or candidates
    }
    /*finder bedste kandidat, count */
    int candidate = -1; //ingen kandidat
    int balance = 0;
  
    //int candidates = votes.size();

    for(int vote : votes){
        if(balance == 0){ 
            candidate = vote; //gem værdi
            balance = 1; //start
        }else if(vote == candidate){ 
            balance++; //tæl op
        }else {
            balance--; //tæl ned, kandidater udligner hinanden
        }
    }

    /*verificer om kandidat er majority*/
    int voteCount = 0; 
    for(int vote : votes){
        if(vote == candidate){
            voteCount++; //tæller hvor mange votes bedste kandidat har
        }
    }

    return (voteCount > (int)votes.size()/2) ? candidate : -1;
}

/*------Test methods for time-complexity exercises-----*/

int P1Exercises::myMethod(int N){
    int x = 0; int y = 0;
    int j;
    int k;
    int i;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            for (k = 0; k < N*sqrt(N); k++){
                x++;
            }
            //std::cout<<"k: "<< k <<std::endl;
            j*=2;
        }
        //std::cout<<"j: " << j<< std::endl;
        i += i;
    }
    std::cout<<"x: " << x<< std::endl;
    //std::cout<<"i: "<< i<<std::endl;
    for(int i = 0; i < N*N; i++){
        y++;
    }
    std::cout<< "y: " << y << std::endl;
    return x+y;

}

int P1Exercises::myMethod2(int N){
    int x = 0;
    int i;
    int j;
    int k;
    for(i = 1; i <= sqrt(N); i++){
        for(j = 1; j <= N; j++){
            for(k = 1; k < N;){
                x++;
                k = k*2;
            }
            //std::cout<<"k: "<< k<<std::endl;
        }
        //std::cout<<"j: "<< j<<std::endl;
    }
    //std::cout<<"i: "<< i<<std::endl;
    return x; 
}

long P1Exercises::myMethod3(int n){
    if(n <= 1){
        return 1;
    }else{
        std::cout<<"n: " << n << "n-1: "<< myMethod3(n-1) <<"n-2: " <<myMethod3(n-2)<<std::endl;
        return myMethod3(n-1) + myMethod3(n-2);
    }

}