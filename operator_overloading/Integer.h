#pragma once
#include <iostream>
class Integer {
private:
	int* m_ptr;
public:
	//Default Constructor
	Integer();
	//Parameterized Constructor
	Integer(int value);
	//Copy constructor
	Integer(const Integer& obj);
	//Move constructor
	Integer(Integer&& obj) noexcept(false);

	//Other functions
	void SetValue(int value);
	int GetValue()const;
	
	//Operator overloaded functions
	//Integer operator +(const Integer& obj)const;
	Integer operator+(const Integer& obj) const;
	Integer& operator ++();
	Integer operator ++(int); 
	bool operator ==(const Integer& obj) const;

	//Copy and Move assignment overloading
	Integer& operator =(const Integer& obj); //copy
	Integer& operator =(Integer&& obj); //move

	// Function call operator overloading
	void operator ()();

	//Friend function
	friend std::istream& operator >> (std::istream& input, Integer& obj);
	//Friend class
	friend class Printer;

	~Integer();
};

class Printer {
public:
	void PrintData(const Integer &obj) const;
};