#include <iostream>
#include <string>

static long myMethod(long N){
    long x = 0; long y = 0;
    long i = 0; 
    long j = 0;
    long k = 0;

    for(i = N; i > 0; i=i/4){
        std::cout<<"j: "<<j<<std::endl;
        std::cout<<"x: "<<x<<std::endl;
        std::cout<<"k: "<<k<<std::endl;
        std::cout<<"i: "<<i<<std::endl;
    
        
        for(long j = 0; j < N; j++){
            for(long k = 0; k < N*N*N; k++){
                x++; k*=k;

                //std::cout<<"k: "<<k<<std::endl;
            }
        }
        
    }
    
   
    return x;
}

int main(int argc, char** argv){
    long x = myMethod(16);
    std::cout<<"x: "<<x<<std::endl;
    
    
  return 0;  
};