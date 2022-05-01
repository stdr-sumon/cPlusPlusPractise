#include "Integer.h"

Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_ptr = new int(0);
}

Integer::Integer(int value) {
	//std::cout << "Here" << std::endl;
	std::cout << "Integer(int)" << std::endl;
	m_ptr = new int(value);
}
void Integer::SetValue(int value) {
	// if the calling object is in unspecified condition that time we need to allocate memory for its member variables
	if (m_ptr == nullptr) {
		m_ptr = new int{};
	}
	*m_ptr = value;
}

int Integer::GetValue() const {
	return *m_ptr;
}

//Copy contructor 
Integer::Integer(const Integer& obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	m_ptr = new int(*obj.m_ptr);
}

//Move assignment constructor
Integer::Integer(Integer&& obj) noexcept(false) {
	std::cout << "Integer(Integer&&)" << std::endl;
	m_ptr = obj.m_ptr;
	obj.m_ptr = nullptr;
}

//Destructor
Integer::~Integer() {
	std::cout << "~Integer()" << std::endl;
	delete m_ptr;
}