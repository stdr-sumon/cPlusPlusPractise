#include <iostream>
#include <cstring>

const char* Combine(const char* pFname, const char* pLname) {
	char* fullName = new char[strlen(pFname) + strlen(pLname) + 1];
	strcpy(fullName, pFname);
	strcat(fullName, pLname);

	return fullName;
}

/*
int main() {
	char fName[10];
	char lName[10];
	std::cin.getline(fName, 10);
	std::cin.getline(lName, 10);

	const char* pFullName = Combine(fName, lName);
	//const int* a = new int[2]{14, 2};
	//std::cout << *a << std::endl;
	std::cout << pFullName << std::endl;

	// Combine(fName, lName) allocated a memory on heap, so delete manually
	delete[] pFullName;
}
*/