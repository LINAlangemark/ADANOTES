#include "BinarySearchTree.h"
#include "hashMap.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cmath>

/*------------------ Method for exercise 1 from P2E------------------*/
/*-------------------- Utilizes the HashMap Class -------------------*/
std::string findMostFrequentWord(std::string text) {
    std::vector<char> buffer(text.begin(), text.end());
    buffer.push_back('\0');  // ensure it's null-terminated
    
    int tbSize = buffer.size();
    tbSize = 211; //fixed prime
    HashMap hm(tbSize);

    //split words by these delimeters
    char del[] = " ,."; 
    char* cw = strtok(buffer.data(), del); //c-string word
    
    //create hashmap of each word
    while (cw != nullptr) {
        hm.insert(cw); 
        cw = strtok(nullptr, del); //null-terminates at delimeters
    }
    
    //find most frequent word by the largest chain in hashmap
    std::string word = hm.findMostFrequent();
    int count = hm.getCount(word);
    std::cout<< "Most frequent word: "<< word << ", with count: "<< count<<std::endl;
    
    return word; //most frequent word
}

int main(int argc, char** argv){
    std::cout<<"----------------------------- Exercise 1 ----------------------------- "<<std::endl;
    std::string text = "The cattle were running back and forth, but there was no wolf to be seen, heard, or smelled, so the shepherd decided to take a little nap in a bed of grass and early summer flowers. Soon he was awakened by a sound he had never heard before.";
    std::cout<<"sentence: "<< text<<std::endl;
    std::cout<<"\n";
    std::string word = findMostFrequentWord(text);

    std::cout<<"----------------------------- Exercise 2 ----------------------------- "<<std::endl;
    BinarySearchTree bst;

    int vals[] = {7, 4, 3, 2, 1, 28, 55, 51, 48, 40, 35, 60, 58, 57, 69};
        std::cout<<"inserting values: "<<std::endl;
    for (int v : vals){
        std::cout<<v<<std::endl;
        bst.insert(v);

    } 
    
    
    int branchCount= bst.branchCount();
    std::cout<<"branchCount: "<<branchCount<<std::endl;

    return 0; 
};