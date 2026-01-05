#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <algorithm>

class Stack{
    private:
        int* _stack;
        int _stack_size;
        int _top;
        
    public:
        Stack(int stack_size);
        ~Stack();
        void push(int element); //modifier?
        int pop(); //accessor/modifier?
        void showStack();
        void peak();

        bool balPar(std::string text); //metoden tjekker om parenteser () i parameteren er "balanceret" en udvidet verson vil kunne omfatte {} og []
};

#endif
