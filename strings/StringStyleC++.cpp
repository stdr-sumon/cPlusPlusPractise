#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using std::string;

void CheckStdString() {
	//initialize & assign
	string s = "Hello";
	string sn{ "World" };
	s = "Hi";
	//Access
	s[1] = 'h';
	sn[0] = 'w';
	std::cout << sn << std::endl;

	std::getline(std::cin, s);
	std::cout << s << std::endl;
	//Size 
	std::cout << "s Length: " << s.length() << std::endl;
	std::cout << "sn Length: " << sn.length() << std::endl;
	//Insert & concatenate
	string s1{ "Hello" }, s2{ "World" };
	s = s1 + s2;
	s += s1;
	std::cout << s << std::endl;
	s.insert(6, "Hi");
	//Comparision
	if (s1 != s2) {
		std::cout << "'s1 != s2'\t--> Hello World " << std::endl;
	}
	//Removal
	s.erase();
	s1.erase(0, 3);
	s2.clear();
	//Search
	auto pos = sn.find("World", 0);
	//string::npos is -1 and find() returns -1 if it is not found
	if (pos != string::npos) {
		//Found
	}

	//Replace
	s1.replace(1, 1, "a");
}
const string Combine(const string fName, const string lName) {
	return fName + lName;
}
std::string ToUpper(const std::string& str) {
	string tmpStr = str;
	for (int i = 0; i < tmpStr.length(); i++) {
		/*if (int(tmpStr[i]) > 96 && int(tmpStr[i]) < 123) {
			tmpStr[i] = char(int(tmpStr[i]) - 32);
		}*/
		tmpStr[i] = toupper(tmpStr[i]);
	}
	return tmpStr;
}
std::string ToLower(const std::string& str) {
	string tmpStr = str;
	for (int i = 0; i < tmpStr.length(); i++) {
		if (int(tmpStr[i]) > 64 && int(tmpStr[i]) < 91) {
			tmpStr[i] = char(int(tmpStr[i]) + 32);
		}
		//tmpStr[i] = tolower(tmpStr[i]);
	}
	return tmpStr;
}

void CheckStringStream() {
	//For read and write
	std::stringstream ss;
	//For write
	std::istringstream is;
	//For read
	std::ostringstream os;

	int a{ 5 }, b{ 6 };
	int sum = a + b;
	//string output = "Sum of: " + a + " & " + b + " is: " + sum; // it won't work

	//std::cout << "Sum of: " << a << " & " << b << " is: " << sum << std::endl;
	ss << "Sum of: " << a << " & " << b << " is: " << sum << std::endl;
	os << "Sum of: " << a << " & " << b << " is: " << sum << std::endl;

	//Extract string as STD STRING
	//The object of 'stringstream' has two overload obj.str() and obj.str("")
	string s1 = ss.str();
	//string s1 = os.str();
	std::cout << s1 << std::endl;
	ss.str("");
	ss << sum;
	auto ssum = ss.str();
	//to_string(primitive_type), this function overloaded for all primitive_type
	auto ssum1 = std::to_string(sum);
	std::cout << ssum << std::endl;
	std::cout << ssum1 << std::endl;

	string data = "12 89 21 56 abc";
	int as;
	std::istringstream iss;
	iss.str(data);
	//while (!iss.fail()) {
	//	iss >> as;
	//	std::cout << as << std::endl;
	//}

	/*while (iss >> as) {
		std::cout << as << std::endl;
	}*/
	std::cout << std::stoi("54") << std::endl;
	int x = std::stoi("64");
	std::cout << x << std::endl;
}

int main() {
	string first;
	string last;
	first = "hello!! c++";
	last = "WORLD c++";
	std::cout << "ToUpper: " << ToUpper(first) << std::endl;
	std::cout << "ToLower: " << ToLower(last) << std::endl;
	//std::getline(std::cin, first);
	//std::getline(std::cin, last);
	//string fullName = Combine(first, last);
	//std::cout << "Fullname: " << fullName << "\n" << std::endl;
	//printf("%s \n", fullName.c_str());
	CheckStringStream();
	
}