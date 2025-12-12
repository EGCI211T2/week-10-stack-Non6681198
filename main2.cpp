// charstack.h
#ifndef CHARSTACK_H
#define CHARSTACK_H

#include <iostream>
#include <string> 
using namespace std;

class CharNode {
public:
    char data;
    CharNode* next;
    CharNode(char val) : data(val), next(nullptr) {}
    ~CharNode() {}
};

class CharStack {
private:
    CharNode* top;

    bool isMatchingPair(char char1, char char2) {
        if (char1 == '(' && char2 == ')')
            return true;
        else if (char1 == '{' && char2 == '}')
            return true;
        else if (char1 == '[' && char2 == ']')
            return true;
        else
            return false;
    }

public:
    CharStack() : top(nullptr) {}
    ~CharStack() {
        while (top) pop();
    }

    void push(char c) {
        CharNode* n = new CharNode(c);
        n->next = top;
        top = n;
       
    }

  
    char pop() {
        if (!top) return '\0';
        char c = top->data;
        CharNode* t = top;
        top = top->next;
        delete t;
        cout << "Popped: " << c << endl; 
        return c;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isBalancedParentheses(const string& expression) {
        // 
        for (char c : expression) {
          
            if (c == '(' || c == '{' || c == '[') {
                push(c);
            }
            
            else if (c == ')' || c == '}' || c == ']') {
              
                if (isEmpty()) {
                   
                    while (top) pop(); 
                    return false;
                }
                
                char popped_char = top->data; t
                
                if (isMatchingPair(popped_char, c)) {
                    
                    pop(); 
                } else {
                    
                    while (top) pop(); 
                    return false;
                }
            }
            
        }

        
        bool balanced = isEmpty();
        
        
        while (top) pop(); 

        return balanced;
    }
};

#endif