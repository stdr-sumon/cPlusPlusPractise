#include <iostream>
using namespace std;
void FillData(int*& p_ref1) {
	p_ref1 = new int{ 5 };
	cout << &p_ref1 << endl;
}

int main_b() {
	//Try to modify x1 & x2 and see the compilation output
	int x = 5;
	int y = 10;
	int z = 15;
	const int MAX = 12;

	int* pt = &x;
	int& ref_x1 = x;
	ref_x1 = y;
	cout << x << "  " << ref_x1 << endl;
	//ref_x1 = MAX;
	const int& ref_x2 = MAX;
	cout << ref_x2 << "  " << ref_x1 << endl;

	//Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
	const int* ptr1 = &x; //here value is not modifibale
	ptr1 = &z;
	cout << *ptr1 << endl;
	int* const ptr2 = &x; //here reference is not modifibale
	*ptr2 = y;
	cout << *ptr2 << endl;
	const int* const ptr3 = &x; //here value and reference are not modifibale

	cout << ptr1 << "  " << ptr2 << "  " << ptr3 << "  " << endl;

	//Find which declarations are valid. If invalid, correct the declaration
	//const int* ptr3 = &MAX;
	const int* ptr4 = &MAX;

	const int& r1 = ref_x1;
	const int& r2 = ref_x2;

	const int*& p_ref1 = ptr1; //p_ref1 is a reference (&) to a pointer (*) of type integer (int
	cout << "p_ref1: " << p_ref1 << " *p_ref1: " << *p_ref1 << " &p_ref1: " << &p_ref1 << endl;
	p_ref1 = pt;
	cout << "p_ref1: " << p_ref1 << " *p_ref1: " << *p_ref1 << " &p_ref1: " << &p_ref1 << endl;
	//const int*& p_ref2 = ptr2;
	int* p = nullptr;//Don't print(read) or write null ponter, it is an access violation
	cout << "ff: " << &p << endl;
	FillData(p);
	std::cout << *p << std::endl;


	return 0;
}