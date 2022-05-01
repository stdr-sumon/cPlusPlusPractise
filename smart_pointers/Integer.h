#pragma once
class Integer {
private:
	int* m_ptr;
public:
	//Default Constructor
	Integer();
	//Parameterized Constructor
	Integer(int value);
	Integer(int value, char a, float c);

	//Copy constructor
	Integer(const Integer& obj);
	//Move constructor
	Integer(Integer&& obj) noexcept(false);

	//Copy and Move assignment overloading
	Integer& operator =(const Integer& obj); //copy
	Integer& operator =(Integer&& obj) noexcept(false); //move

	//Other functions
	void SetValue(int value);
	int GetValue()const;


	~Integer();
};