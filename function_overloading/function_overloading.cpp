#include <iostream>
#include "function_overloading.h"
using namespace std;
int Add(int a, int b) {
    return a + b;
}

double Add(double a, double b) {
    return a + b;
}

/*
extern "C" {
    void Print(int* x) {
        cout << *x << endl;
    }

    void Print(const int* x) {
        cout << "Const: " << *x << endl;
    }
}
*/
void Print(int* x) {
    cout << *x << endl;
}

void Print(const int* x) {
    cout << "Const: " << *x << endl;
}