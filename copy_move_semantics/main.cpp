#include <iostream>
#include "Integer.h"

class Number {
private:
	Integer m_Value{};
public:
	Number() = default;

	Number(int value) :m_Value{value} {
	}

	//Copy contructor of Number class
	/*
	Number(const Number& n) :m_Value{ n.m_Value } {
	}
	*/
	Number(const Number& n) = default;

	//Copy assignment of Number class
	/*
	Number& operator=(const Number& obj) {
		return *this;
	}
	*/
	Number& operator=(const Number&) = default;

	//Move contructor of Number class
	/*
	Number(Number&& n) :m_Value{ std::move(n.m_Value) } {
	}
	*/
	Number(Number&& n) = default;

	//Move assignment of Number class
	/*
	Number& operator=(Number&& obj) {
		return *this;
	}
	*/
	Number& operator=(Number&&) = default;

	Integer GetVal() {
		return m_Value;
	}
	~Number() {

	}
};

Number CreateNumber(int num) {
	Number n{ num };
	return n;
}

Integer Add(const Integer& a, const Integer& b) {
	Integer tmp;
	tmp.SetValue(a.GetValue() + b.GetValue());
	return tmp; //temporary(with sum value of => a.GetValue + b.GetValue) object creation
}

void CheckCopySemantics() {
	//std::cout << new int(0);
	Integer a(1), b(4);
	//std::cout << "val: " << Add(a, b).GetValue() << std::endl;
	a.SetValue(Add(a, b).GetValue());

	Number n;
	Number n1{ 16 };
	//std::cout << n1.GetVal().GetValue() << std::endl;
	auto n2{ n1 };
	n2 = n1;
}

void CheckMoveSemantics() {
	Number n;
	auto n3{ CreateNumber(3) };
	n3 = CreateNumber(13);
}

void Print(Integer obj) {
	std::cout << obj.GetValue() << std::endl;
}

int main() {
	//CheckCopySemantics();
	//CheckMoveSemantics();
	Integer a(5);
	auto b{ a }; // it calls CopyConstructor --> Integer(const Integer&) fuction since 'a' is l-value reference
	//auto c{ static_cast<Integer&&>(a) }; // it calls MoveConstructor --> Integer(Integer&& obj) fuction since 'a' passed as r-value refernce as it is casted
	//auto d{ std::move(a) }; // More readable and it invokes MoveConstructor

	/*Print(a);
	std::cout << a.GetValue() << std::endl;*/

	Print(std::move(a));
	a.SetValue(6);
	std::cout << a.GetValue() << std::endl;

	return 0;
}