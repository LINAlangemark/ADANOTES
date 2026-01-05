#include "hashMap.h"    

HashMap::HashMap(int tableSize): _tableSize(tableSize) {
    _buckets.resize(_tableSize);
}

void HashMap::insert(std::string word) {
    int idx = hashFunc(word);
    for (auto &p : _buckets[idx]) {
        if (p.first == word) { //word is in the first spot
            p.second++; //increment counter for words
            return;
        }
    }

    _buckets[idx].push_back({word, 1}); //first word appearance
   
}

int HashMap::hashFunc(const std::string& word) {
    int h = 0;
    
    for (char c : word) {
        h = 31 * h + c;
    }
    
    int hashVal = abs(h) % _tableSize;
     
    //std::cout<<"hashVal: "<< hashVal<<std::endl;
    return hashVal;
}

std::string HashMap::findMostFrequent(){
    std::string word = "null";
    int maxCount = 0;
    // Loop through all buckets
    for (const auto& bucket : _buckets) {
        // Loop through all pairs inside bucket
        for (const auto& p : bucket) {
            if (p.second > maxCount) {
                word = p.first;
                maxCount = p.second;
            }
        }
    }
    return word;
}

int HashMap::getCount(std::string word){
    int wordCount = 0;
    // Loop through all buckets
    for (const auto& bucket : _buckets) {
        // Loop through all pairs inside bucket
        for (const auto& p : bucket) {
            if (p.first == word) {
                wordCount = p.second;
            }
        }
    }
    return wordCount;

}


