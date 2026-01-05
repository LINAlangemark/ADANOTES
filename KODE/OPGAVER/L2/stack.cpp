#include "stack.h"


Stack::Stack(int stack_size): _stack_size{stack_size}, _top(-1){ //top(-1) so we can increment to index 0 on first push
    _stack = new int[stack_size]; //stack is a pointer variable, so at this address create new stack with stack_size
}

void Stack::push(int element){
    try { //internal try catch to handle overflow
        if (_top < _stack_size - 1) {
            _stack[++_top] = element; //incrementing the index before assigning the element to that index
            //std::cout<<"top: "<< _top<<" TOS: "<<_stack[_top]<<std::endl;
        } else {
            throw std::overflow_error("Stack overflow");
        }
    }
    catch (const std::overflow_error&) {
        _top = -1; //resetting stack
    }
}

int Stack::pop(){
    try{ 
        if(_top >= 0){
        int element = _stack[_top];

            --_top;
            //std::cout<<"top: "<< _top<<" TOS: "<<_stack[_top]<<std::endl;
            return element;
        } else {
            throw std::out_of_range("underflow");
        }   
    }
    catch (const std::out_of_range&){
        _top  = +1; //if we happen to decreme to below 0 fix here
    }
    return 0;
}


bool Stack::balPar(std::string text){
    for(char c : text){
        
        if(c == '(' || c == '{' || c == '['){ //if opening brackets: ( { [
            push(c);
        }else{ // if closing brackets ) ] }  --- or something else
            if (_top < 0) return false;               // no opener to match
            char top = static_cast<char>(pop());
            switch (top){
                case '(':
                    if(c != ')'){return false;} break; //keep going if correct
                case '{': 
                    if(c != '}'){return false;} break; //keep going if correct
                case '[':
                    if(c != ']'){return false;} break; //keep going if correct
            }
             
        }  
        
    }
    if(_top == -1){ // finished iterating through string and stack is fully popped
        return true;
    }

    return false;
    
} 

void Stack::showStack(){
    std::cout<<"-----Stack -----"<<std::endl;
    for (int i = 0; i < _top+1; ++i){ //current top
        std::cout<<"element " << i << ": " << _stack[i] << std::endl; 
    }
}

void Stack::peak(){
    std::cout<<"top: "<< _top<<" TOS: "<<_stack[_top]<<std::endl;
}

Stack::~Stack(){
    delete[] _stack; //deallocate heap memory for array, important why?
}