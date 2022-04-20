#include "Integer.h"

//If first operand is primitive type then it will be invoked
Integer operator +(int a, const Integer& b) {
	Integer tmp;
	tmp.SetValue(a + b.GetValue());
	return tmp; //temporary (with sum value of => a + b.GetValue) object creation
}

//Overloading for object as output
std::ostream & operator <<(std::ostream& out, const Integer& obj) {
	out << obj.GetValue();
	return out;
}

std::istream& operator >>(std::istream& input, Integer& obj) {
	int x;
	input >> x;
	//obj.SetValue(x);
	*obj.m_ptr = x; //Possible since this function is a 'friend' of Integer class 

	return input;
}

int main() {
	Integer a(1), b(3);
	Integer c{ 3 };
	/*
	Integer sum = a + b; // a.operator+(b)
	++sum;
	std::cout << "Sum is: " << (sum++).GetValue() << std::endl;
	std::cout << "Sum is: " << sum.GetValue() << std::endl;
	Integer sum2 = a + 5; // a.operator+(5) and 5 becomes a object of Integer  class through 'type conversion'
	std::cout << "Sum is: " << sum2.GetValue() << std::endl;
	Integer sum3 = 7 + a; // if first operand is primitive type then the operator should be overloaded as global function
	std::cout << "Sum3 is: " << sum3.GetValue() << std::endl;

	// Lets overload an 'ostream' operator '<<' for printing object
	std::cout << "Sum3 is: " << sum3 << std::endl; // it works as--> operator << (std::cout, sum3).operator<<(std::endl);

	if (c == b) {
		std::cout << "Equal" << std::endl;
	}
	else {
		std::cout << "Not Equal" << std::endl;
	}

	std::cout << "C is: " << c.GetValue() << std::endl;
	c = a;
	std::cout << "C is: " << c.GetValue() << std::endl;
	*/

	// Overloading for input and output through object
	Integer d;
	std::cin >> d;
	std::cout << "D is: " << d << std::endl;
	d();

	Printer p;
	p.PrintData(c);


	return 0;
}