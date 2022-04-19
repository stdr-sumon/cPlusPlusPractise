#include <iostream>
#include "Integer.h"

Integer Add(const Integer& a, const Integer& b) {
	Integer tmp;
	tmp.SetValue(a.GetValue() + b.GetValue());
	return tmp; //temporary(with sum value of => a.GetValue + b.GetValue) object creation
}

void checkCopySemantics() {
	//std::cout << new int(0);
	Integer a(1), b(4);
	//std::cout << "val: " << Add(a, b).GetValue() << std::endl;
	a.SetValue(Add(a, b).GetValue());
}

class Number {
private:
	Integer m_Value{};
public:
	Number(int value) :m_Value{value} {
	}

	Integer GetVal() {
		return m_Value;
	}
};

Number CreateNumber(int num) {
	Number n{ num };
	return n;
}

int main() {
	//checkCopySemantics();

	//Number n1{ 16 };
	////std::cout << n1.GetVal().GetValue() << std::endl;
	//auto n2{ n1 };
	//n2 = n1;

	auto n3{ CreateNumber(3) };
	n3 = CreateNumber(13);

	return 0;
}