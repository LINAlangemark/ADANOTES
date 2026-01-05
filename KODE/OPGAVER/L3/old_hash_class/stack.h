#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <algorithm>

class Stack{
    protected:
        int* _stack;
        int _stack_size;
        int _top;
        
    public:
        explicit Stack(int stack_size);
        ~Stack();
        void push(int element); //modifier?
        int pop(); //accessor/modifier?
        void showStack();
        int peek();
        void insert(int element, int index);

        bool balPar(std::string text); //metoden tjekker om parenteser () i parameteren er "balanceret" en udvidet verson vil kunne omfatte {} og []
};

#endif
