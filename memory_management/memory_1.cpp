#include <iostream>
#include <stdlib.h>
#include <cstdint>
using namespace std;

void getMemVal(void) {
    void *p;
	cout << "Enter the address: ";
	cin >> p;
    cout << "address = " << p << endl;
    unsigned char *ptr;
    ptr = (unsigned char*) p;
    printf("The value at address = `%c`, decimal %d, hex 0x%02x\n", *ptr, *ptr, *ptr);
}
void Malloc() {
	//int* p = (int*)calloc(5, sizeof(int));
	int* p = (int*)malloc(5 * sizeof(int));
	if (p == NULL) {
		cout << "Failed to allocate Memory";
		return;
	}
	*p = 5;
	cout << *p;
	free(p);
	p = NULL;
	getMemVal();
	getMemVal();
	getMemVal();
}

void New() {
	int* q = new int;
	*q = 612;
	cout << "Q value: " << *q << endl;

	int* p = new int(5);
	cout << "P value: " << *p << endl;
	delete p, q;
	//cout << *p << " " << *q << endl;

	p = nullptr, q = nullptr; // No need actually since it is a function, and function excutes in stack memory; automatically the space will be released 
	//cout << p << " " << q;
}

void NewArrays() {
	//int* p = new int[5]{ 1, 2, 3, 4, 5 };

	int* p = new int[5];
	for (int i = 0; i < 5; i++) {
		p[i] = i;
	}
	delete[] p;
}

void Strings() {
	char* p = new char[8];
	strcpy_s(p, 8, "The C++"); //since C11  
	cout << p << endl;
	delete[] p;
}

void TwoD() {
	int* p1 = new int[3];
	int* p2 = new int[3];
	for (int i = 0; i < 3; i++) {
		p1[i] = i + 1;
		p2[i] = p1[i] * 2;
	}

	int** pData = new int *[2]; //memory for array of two integers;
	//pData is a 1D array of integers pointer; each element of this 1D array will hold a pointer of another 1D aaray
	pData[0] = p1;
	pData[1] = p2;

	for (int i = 0; i < 3; i++) {
		cout << "P1[" << i << "]: " << p1[i] << " AND " << "P2[" << i << "]: " << p2[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "pData[" << i << "]" << "[" << j << "]: " << pData[i][j] << endl;
		}
	}
	delete[] p1; //delete []pData[0]
	delete[] p2; //delete []pData[1]

	delete[] pData;
}

int main() {
	//Malloc();
	/*Strings();
	New();	
	NewArrays();*/
	int data[2][3] = {
		1,2,3,
		4,5,6
	}; //1,2,3,4,5,6
	TwoD();

	return 0;
}