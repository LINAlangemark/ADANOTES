#include <iostream>
#include <stack>
#include <string>

using namespace std;


// Implement your own stack and write the method given. 
// You have to use the stack
// Counters cannot be used.

// Function declaration
bool balPar(string text);


// The method checks if parenthesis () are in the parameters and balanced
// An extended version can include {} and []

// Function definition
bool balPar(string text) {                      
    stack<char> s;                                  // Create a stack of characters                                
    for (int i = 0; i < text.length(); i++) {       // Loop through the string
        if (text[i] == '(') {                       // If the character is an opening parenthesis
            s.push(text[i]);                        // Push it onto the stack
        } else if (text[i] == ')') {                // If the character is a closing parenthesis
            if (s.empty() || s.top() != '(') {      // If the stack is empty or the top of the stack is not an opening parenthesis
                return false;                       // Return false
            }
            s.pop();                                // Pop the opening parenthesis from the stack
        }
    }
    return s.empty();                               // Return true if the stack is empty
}

int main() {
    string text = "((()))";                         // Test string
    cout << balPar(text) << endl;                   // Should print 1 (true)
    cout << balPar("((())") << endl;                // Should print 0 (false)
    return 0;
}

