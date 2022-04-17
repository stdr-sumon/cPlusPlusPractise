#include <iostream>
using namespace std;

int main() {
	int arr[] = {1, 5, 7, 6};

	for (int i = 0; i < 4; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (auto x : arr) {
		x = 47;
		cout << x << " ";
	}
	cout << endl;
	for (const auto x : arr) {
		//x = 47;
		cout << x << " ";
	}

	//c++ 11 supports
	/*int* begin = std::begin(arr);
	int* end = std::end(arr);
	cout << endl;
	while (begin != end) {
		cout << *begin << ' ';
		begin++;
	}*/

	/*auto begin = std::begin(arr);
	auto end = std::end(arr);
	cout << endl;
	for (;begin != end; ++begin) {
		auto v = *begin;
		cout << v << ' ';
	}*/

	auto&& range = arr; // && range is forwarding reference
	auto begin = std::begin(range);
	auto end = std::end(range);
	cout << endl;
	for (;begin != end; ++begin) {
		cout << *begin << ' ';
	}

	return 0;
}