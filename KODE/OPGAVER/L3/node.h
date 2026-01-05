// C++ program to Implement doubly linked list
// https://www.geeksforgeeks.org/cpp/doubly-linked-list-in-cpp/ 


#include <iostream>
#include <cstddef>

#ifndef NODE_H
#define NODE_H

struct Node {
    int data;
    Node* next;
    Node* prev;
    explicit Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

#endif // NODE_H