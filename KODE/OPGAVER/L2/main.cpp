#include "stack.h"
#include <iostream>
#include <string>

int main(int argc, char** argv){

    //-----------Exercise 1: Stack ---------------
    Stack stack = Stack(10);
    stack.push(3);
    stack.push(5);
    stack.push(1);
    stack.push(2);
    stack.push(8);
    stack.showStack();
    stack.peak();
    int element = stack.pop();
    std::cout<<"popped: "<<element<<std::endl;
    stack.peak();
    stack.showStack();
    stack.push(7);
    stack.peak();
    stack.showStack();
    
    //-----------Exercise 1: Balanced Parenthesis ------------

    std::cout<<"--------Parenthesis Balancing --------"<<std::endl;
    
    Stack stack2 = Stack(50);
    
    std::string text1 = "((()))";
    std::cout<<"string is balanced? "<< stack2.balPar(text1) <<std::endl; //should return true

    std::string text2 = "(()))";
    std::cout<<"string is balanced? "<< stack2.balPar(text2) <<std::endl; //should return false

    std::string text3 = "{[()]}";
    std::cout<<"string is balanced? "<< stack2.balPar(text3) <<std::endl; //should return true

    std::string text4 = "({})])";
    std::cout<<"string is balanced? "<< stack2.balPar(text4) <<std::endl; //should return false


    return 0;
}
