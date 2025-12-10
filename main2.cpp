// charstack.h
#ifndef CHARSTACK_H
#define CHARSTACK_H

#include <iostream>
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
        cout << "Popped: " << c << endl; // print during pop
        return c;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

#endif
