#include <iostream>

class Printer {
	std::weak_ptr<int> m_Val{};
public:
	//Weak pointer initialized by a shared pointer
	void SetValue(std::weak_ptr<int> p) {
		m_Val = p;
	}
	void Display() {
		if (m_Val.expired()) {
			std::cout << "Reference already freed!" << std::endl;
			return;
		}
		auto sp = m_Val.lock();
		std::cout << "Value is: " << *sp << std::endl;
		std::cout << "Reference Count: " << sp.use_count() << std::endl;
	}
};