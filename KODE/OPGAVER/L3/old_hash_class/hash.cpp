#include "hash.h"


Hash::Hash(int table_size, int key_list[]): Stack(table_size),_table_size{table_size}{
    hashMap(key_list);
    //showStack();
}

void Hash::hashMap(int key_list[]){
    int hashedVal;
    int key;
    
    for(int i = 0; i<_table_size;i++){
        key = key_list[i];
        std::cout<<"current key: "<<key<<std::endl;
        hashedVal = hashFunc(key);
        std::cout<<"current hashedVal: "<<hashedVal<<std::endl;
        quadProbe(key, hashedVal);
    }

    showStack(); //prints hashed table
}

int Hash::hashFunc(int key){
    int x = key % _table_size;
    return x;
}

void Hash::quadProbe(int key, int index){
    int initial_index = index;
    int inc = 1;
    while(_stack[index] != -1){
        index = (initial_index  + (inc*inc)) % _table_size;
        inc++;
        std::cout<<"index in quadProbe: "<<index <<std::endl;
    }
    _stack[index] = key; //valid index found
}