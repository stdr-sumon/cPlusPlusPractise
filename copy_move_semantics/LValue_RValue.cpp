#include <iostream>

//Returns r-value
int Add(int x, int y) {
	return x + y;
}

//Return l-value
int& Transform(int& x) {
	x *= x;
	return x;
}

void Print(int& x) {
	std::cout << "Print(int& )" << std::endl;
}

void Print(const int& x) {
	std::cout << "Print(const int& )" << std::endl;

}

void Print(int&& x) {
	std::cout << "Print(int&& )" << std::endl;
}

int main_a() {
	/*
	//x, y & z are l-value AND 3, 4, 5 are r-value
	int x = 3;
	int y = 4;
	int z = 5;

	// Expression returning r-value
	int res = (x + y) * z;

	// Expression returning l-value
	++x = 6;
	*/

	int x = 10;
	Print(x);
	Print(10); //As preference temporary(10) will hit r-value refernce not constant l-value reference

	return 0;
}