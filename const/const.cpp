#include <iostream>
using namespace std;

void printPointer(const int *ptr) {
	cout << "ptr: " << *ptr << " ptr ref: " << ptr << " ptr add: " << &ptr << endl;
	//*ptr = 700;
}

void printRef(const int &ref) {
	int y = 5;
	//ref = y;
	cout << "Ref is:" << ref << endl;
	//ref = 20;
}

int main_a() {
	/*
	float const PI = 3.14f;
	float rad = 3.0f;
	float area = PI * rad * rad;
	float circumference = PI * 2 * rad;
	
	const float *const p = &PI;
	*p = 12;
	p = &rad;

	float * r = &rad;
	*r = 12;
	*/

	//cout << "Area is: " << area << " & Circumference is: " << circumference << endl;

	int x = 10;
	//printPointer(&x);

	//cout << "X-> " << x;

	printRef(x);
	cout << "X-> " << x;

	return 0;
}