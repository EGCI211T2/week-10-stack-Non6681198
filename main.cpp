#include <iostream>
#include <cstdlib>  // for atoi
using namespace std;

#include "stack.h"

int main(int argc, char **argv) {
    Stack s;

    // Example pushes and pops
    s.push(5);
    s.push(1);
    s.push(7);
    cout << "Pop: " << s.pop() << endl;  // pops 7
    s.push(6);
    cout << "Pop: " << s.pop() << endl;  // pops 6

    // -----------------------------
    // Exercise 1: push command line args
    // -----------------------------
    for (int i = 1; i < argc; i++) {
        int val = atoi(argv[i]);  // convert argument to integer
        s.push(val);
    }

    // Pop all remaining stack values
    cout << "Remaining values in stack:" << endl;
    while (true) {
        int val = s.pop();
        if (val == -1) break;  // empty stack
        cout << val << endl;
    }

    return 0;
}
