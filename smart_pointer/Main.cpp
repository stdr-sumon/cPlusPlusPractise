#include "Integer.h"
using namespace std;

void CreateInteger();
void CreateIntegerRAII();

class IntPtr {
	Integer* m_p;

public:
	IntPtr(Integer* p) : m_p(p) {
		/*
		cout << m_p << endl;
		cout << m_p->GetValue() << endl;
		cout << "P: " << endl;
		cout << m_p << endl;
		cout << m_p->GetValue() << endl;
		*/

	}
	~IntPtr() {
		delete m_p;
	}
	// '->' operator overloading
	Integer* operator->() {
		return m_p;
	}

	// '*' operator overloading
	Integer& operator*() {
		return *m_p;
	}
};

int main() {
	//CreateInteger();
	CreateIntegerRAII();

	return 0;
}

void CreateIntegerRAII() {
	IntPtr p = new Integer; // Here p is a smart pointer since it is releasing occupied memory but this pointer only works with integer object
	cout << "Val: " << p->GetValue() << endl;    //Works for '-> operator overloading' 
	cout << "Val: " << (*p).GetValue() << endl; //Works for '* operator overloading'
}

void CreateInteger() {
	Integer* p = new Integer;
	p->SetValue(3);
	cout << p->GetValue() << endl;
	delete p;
}