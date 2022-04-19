#include "Integer.h"
#include <iostream>

Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_ptr = new int(0);
}

Integer::Integer(int value) {
	//std::cout << "Here" << std::endl;
	std::cout << "Integer(int)" << std::endl;
	m_ptr = new int(value);
}

Integer::Integer(const Integer& obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	m_ptr = new int(*obj.m_ptr);
}

Integer::Integer(Integer&& obj) noexcept(false) {
	std::cout << "Integer(Integer&&)" << std::endl;
	m_ptr = obj.m_ptr;
	obj.m_ptr = nullptr;
}

Integer& Integer::operator=(const Integer& obj) {
	std::cout << "operator=(const Integer&)" << std::endl;
	if (this == &obj) {
		return *this;
	}
	delete m_ptr;
	m_ptr = new int(*obj.m_ptr);

	return *this;
}

Integer& Integer::operator=(Integer&& obj) noexcept(false) {
	std::cout << "operator=(Integer&&)" << std::endl;
	if (this == &obj) {
		return *this;
	}
	delete m_ptr;
	m_ptr = obj.m_ptr;
	obj.m_ptr = nullptr;

	return *this;
}

void Integer::SetValue(int value) {
	*m_ptr = value;
}

int Integer::GetValue() const {
	return *m_ptr;
}

Integer::~Integer() {
	std::cout << "~Integer()" << std::endl;
	delete m_ptr;
}
