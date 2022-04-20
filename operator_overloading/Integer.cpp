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

Integer Integer::operator+(const Integer& obj) const {
	Integer temp;
	std::cout << "This is: " << *this->m_ptr << " obj is: " << *obj.m_ptr << std::endl;
	*temp.m_ptr = *this->m_ptr + *obj.m_ptr;
	std::cout << "Sum is: " << *temp.m_ptr << std::endl;
	return temp;
}

Integer& Integer::operator++() {
	++(*this->m_ptr);
	return *this;
}

Integer Integer::operator++(int) {
	Integer temp(*this);
	++(*this->m_ptr);
	return temp;
}

//Copy contructor 
Integer::Integer(const Integer& obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	m_ptr = new int(*obj.m_ptr);
}
//Copy assignment operator overloading
Integer& Integer::operator=(const Integer& obj) {
	if (this != &obj) {
		delete this->m_ptr;
		this->m_ptr = new int(*obj.m_ptr);
	}
	return *this;
}

//Move assignment constructor
Integer::Integer(Integer&& obj) noexcept(false) {
	std::cout << "Integer(Integer&&)" << std::endl;
	m_ptr = obj.m_ptr;
	obj.m_ptr = nullptr;
}

//Move assignment operator overloading
Integer& Integer::operator=(Integer&& obj) {
	if (this != &obj) {
		delete this->m_ptr;
		this->m_ptr = obj.m_ptr;
		obj.m_ptr = nullptr;
	}
	return *this;
}

//Comparision operator overloading for object comparision
bool Integer::operator==(const Integer& obj) const {
	return *this->m_ptr == *obj.m_ptr;
}

//Function call operator overloading
//This operator overloading allow us to perform any operation to the calling object
void Integer::operator()() {
	std::cout << "Value before: " << *this->m_ptr << std::endl;
	*this->m_ptr = 777;
	std::cout << "Value After: " << *this->m_ptr << std::endl;
}

//Printer class function
void Printer::PrintData(const Integer& obj) const{
	std::cout << "PrintData calling Integer class member: " << *obj.m_ptr << std::endl;
}

//Destructor
Integer::~Integer() {
	std::cout << "~Integer()" << std::endl;
	delete m_ptr;
}
