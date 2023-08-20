#pragma once
class Integers {
private:
	int *m_ptr;
public:
	Integers();
	Integers(int value);
	Integers(const Integers& obj);
	void SetValue(int value);
	int GetValue()const;
	~Integers();

};