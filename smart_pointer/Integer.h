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
	
	//Destructor
	~Integer();
};