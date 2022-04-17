#include <iostream>
using namespace std;

int sum(int i, int j) {
	return i + j;
}

int main_c() {
	auto i = 10;
	auto j = 5;
	auto k = i + j;

	cout << "K: " << k << "\n";

	auto res = sum(i, j) + 4.5f;
	cout << "Res: " << res << "\n";

	const int x = 10;
	auto y = x;
	const auto z = x; // need const keyword to make the variable as constant -> EXPLICIT
	auto& var = x; // NO need const keyword to make the reference as constant -> IMPLICIT
	auto ptr = &x;

	auto list = { 1, 2, 4 };
	cout << list.begin()[2];

	auto varr{ 2 };
	cout << "varr: " << varr << "\n";

	return 0;
}