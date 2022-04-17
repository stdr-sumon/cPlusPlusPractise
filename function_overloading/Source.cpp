#include <iostream>
#include "function_overloading.h"
//#define Sqr(x) x*x //happens text replacement x+1*x+1 ==== 11
using namespace std;

inline int Sqr(int x) {
    return x*x;
}

void Print(int length, char ch) {
    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    cout << endl;
}

void EndMsg() {
    cout << "Bye" << endl;
}
namespace FloatArith {
    float calculateAvg(float a, float b) {
        float c = (a + b) / 2;
        return c;
    }
    float Add(float a, float b) {
        return a + b;
    }
    namespace FloatCompare {
        float compare(float a, float b) {
           return (a > b) ? a : b;
        }
    }
}
namespace DecimalArith {
    int calculateAvg(int a, int b) {
        return (int) (a + b) / 2;
    }
    int Add(int a, int b) {
        return a + b;
    }
    namespace DecCompare {
        int compare(int a, int b) {
            return (a > b) ? a : b;
        }
    }
}

int main()
{
    atexit(EndMsg); //invoke before termination
    int a = 15, b = 10;
    double x = 5, y = 12.5;
    const int ac = 10;

    cout << Add(a, b) << endl;
    cout << Add(x, y) << endl;
    Print(&a);
    Print(&ac);

    cout << Sqr(x+1) << endl; //inline and macro

    // function pointer
    int (*ps)(int) = Sqr; 
    cout << (*ps)(5) << endl;

    void (*ptf) (int, char) = &Print;
    (*ptf)(5, '$');
    Print(5, '@');

    
    int (*ptrDecAvg) (int, int) = DecimalArith::calculateAvg;
    cout << "Dec Avg: " << (*ptrDecAvg)(a, b) << endl;

    //using namespace DecimalArith;
    //int decAvg = calculateAvg(a, b);
    int decAvg = DecimalArith::calculateAvg(a, b);
    cout << "Dec Avg is: " << decAvg << endl;
    
    float (*ptrFloatAvg) (float, float) = FloatArith::calculateAvg;
    cout << "Float Avg of a, b: " << (*ptrFloatAvg)(a, b) << endl;
    cout << "Float Avg of x, y: " << (*ptrFloatAvg)(x, y) << endl;
    
    //using FloatArith::calculateAvg;
    //cout << "Var Float Avg of a, b: " << calculateAvg(a, b) << endl;
    float floatAvgAB = FloatArith::calculateAvg(a, b);
    float floatAvgXY = FloatArith::calculateAvg(x, y);
    cout << "Var Float Avg of a, b: " << floatAvgAB << endl;
    cout << "Var Float Avg of x, y: " << floatAvgXY << endl;

    int decLarge = DecimalArith::DecCompare::compare(a, b);
    float floatLarge = FloatArith::FloatCompare::compare(x, y);
    cout << "Large among a, b: " << decLarge << endl;
    cout << "Large among x, y: " << floatLarge << endl;

    return 0;   
}