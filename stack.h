#ifndef STACK_H
#define STACK_H
#include "node.h"
#include <iostream>
using namespace std;

class Stack {
    NodePtr top;
    int size;
public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
};

Stack::Stack() {
    top = nullptr;
    size = 0;
}

Stack::~Stack() {
    while (top) {
        pop(); // delete all remaining nodes
    }
}

void Stack::push(int x) {
    NodePtr new_node = new NODE(x);
    if (new_node) {
        new_node->set_next(top); // connect new node to previous top
        top = new_node;          // update top
        size++;                  // increment size
    }
}

int Stack::pop() {
    if (!top) {
        cout << "Stack empty!" << endl;
        return -1; // return -1 if stack is empty
    }
    NodePtr t = top;
    int value = t->get_value();
    top = t->get_next(); // move top to next node
    delete t;            // free memory
    size--;              // decrement size
    return value;
}

#endif
