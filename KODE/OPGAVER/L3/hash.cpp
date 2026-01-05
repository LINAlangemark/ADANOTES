#include "hash.h"
#include "node.h"
#include <random>
Hash::Hash(int tableSize, int keyList[]):_tableSize(tableSize), _buckets(tableSize){
    //hashMap(keyList);
    //powerOfTwoChoices(keyList);
    //int max = findLargestChain();
    //int avg = findAverageNumberOfCollisions();
    //std::cout<<"maximum size chain/ number of collisions: " << max << std::endl; 
    //std::cout<<"average number of collisions: "<< avg << std::endl; 
    //hashMap_random_one_choice(std::size_t tableSize); 
}

void Hash::hashMap(int keyList[]){
    int bucketIdx;
    int key;
    
    
    for(int i = 0; i<_tableSize;i++){
        key = keyList[i];
        std::cout<<"current key: "<<key<<std::endl;
        
        bucketIdx = hashFunc(key);
        std::cout<<"bucketIdx: "<<bucketIdx<<std::endl;
        
        if (_buckets[bucketIdx].empty()){ //if node is not empty?
            std::cout<<"bucket not empty"<<std::endl;   
            std::cout<<"bucket size: " << _buckets[bucketIdx].size() << std::endl; 
        } else {
            std::cout<<"bucket empty"<<std::endl;    
        }
        
        _buckets[bucketIdx].push_back(key); //add key to index

    }

}

int Hash::hashFunc(int key){
    //int x = key % _tableSize;
    //return x;
  const std::size_t m = _tableSize;
     long long r = static_cast<long long>(key) % static_cast<long long>(m);
    if (r < 0) r += m;
    return static_cast<std::size_t>(r);
}

int Hash::secondHashFunc(int key){
  
    static constexpr double A = 0.6180339887498948482; // Knuth's suggestion: A = (sqrt(5)-1)/2 ≈ 0.6180339887

    double ka   = static_cast<double>(key) * A;
    double frac = ka - std::floor(ka);        
    return static_cast<std::size_t>(std::floor(frac * _tableSize));
}


void Hash::powerOfTwoChoices(int keyList[]){
    int bucketIdx;
    int key;
    
    
    for(int i = 0; i<_tableSize;i++){
        key = keyList[i];
        int bucketIdx;
        int bucketOne = hashFunc(key);
        int bucketTwo = secondHashFunc(key);

        if (_buckets[bucketOne].size()<=_buckets[bucketTwo].size()){
            bucketIdx = bucketOne;
        } else {
            bucketIdx = bucketTwo;
        }
        
        _buckets[bucketIdx].push_back(key); //add key to index

    }

}


int Hash::findLargestChain(){
    for (int i = 0; i < _tableSize-1; i++){
        _chainSizes.push_back(_buckets[i].size());
        //std::cout<<_chainSizes[i]<<std::endl;
    }

    auto minmax = std::minmax_element(_chainSizes.begin(), _chainSizes.end());
    
    
    auto max_collisions = *minmax.second;
    //std::cout<<"maximum size chain number of collisions: " << max_collisions << std::endl; 
    return max_collisions;
}

float Hash::findAverageNumberOfCollisions(){
    int sum = std::accumulate(_chainSizes.begin(), _chainSizes.end(), 0);

    // Finding average of all elements
    float avg = sum / _chainSizes.size();
    std::cout<<"sum: " << sum << std::endl;
    std::cout<<"table: " << _tableSize << std::endl;
    std::cout<<"avg: " << avg << std::endl;
    return avg; 
}

void Hash::rehash(){
    //create array of double size
    //copy elements from old array into new array
    //point to new array
    //delte old array
}


