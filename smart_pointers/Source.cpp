#include <iostream>
#include "Integer.h"
#include "SharedPointer.cpp"
#include "WeakPointer.cpp"

void Display(const Integer* p) {
	std::cout << p->GetValue() << std::endl;
}

void Store(const std::unique_ptr<Integer> p) {
	std::cout << "Store called!" << std::endl;
}

Integer* GetPointer(int value) {
	Integer* p = new Integer{ value };
	return p;
}

void OperateAsRaw(int value) {
	Integer* p = GetPointer(value);
	if (p == nullptr) {
		p = new Integer{ value };
	}
	p->SetValue(20);
	Display(p);
	delete p;
	p = nullptr;

	p = new Integer{};
	*p = __LINE__;
	Display(p);
	delete p;
}

void OperateAsSmart(int value) {
	std::unique_ptr<Integer> p{ GetPointer(value) };
	if (p == nullptr) {
		p.reset(new Integer{ value });
	}
	p->SetValue(20);
	
	// Here 'p' is an object and p.get() is pointer to that object
	Display(p.get());
	p = nullptr;

	p.reset(new Integer{});
	*p = __LINE__;
	Display(p.get());
	Store(std::move(p));
	//*p = 200;
	//Display(p.get());
}
void ShowEmpInfo(const std::shared_ptr<Employee> &emp) {
	std::cout << "Employee project details: " << std::endl;
	emp->GetEmpProject()->GetProjectName();
}

void CheckSharedPointer() {
	std::shared_ptr<Project> prj{ new Project{} };
	prj->SetProjectName("Project One");
	std::shared_ptr<Employee> e1{ new Employee{} };
	e1->SetEmpProject(prj);
	std::shared_ptr<Employee> e2{ new Employee{} };
	e2->SetEmpProject(prj);
	{
		std::shared_ptr<Employee> e3{ new Employee{} };
		e3->SetEmpProject(prj);
	}
	//e2.reset();
	//e1.reset();
	//ShowEmpInfo(e2);
	//ShowEmpInfo(e1);

	prj->GetProjectName();
	std::cout << "Reference Count: " << prj.use_count() << std::endl;
}

void CheckWeakPointer() {
	Printer prn;
	int num{};
	std::cin >> num;
	std::shared_ptr<int> p{ new int{num} };
	//Passing shared pointer to initialize the weak pointer 
	prn.SetValue(p);
	if (*p > 10) {
		p = nullptr;
	}
	prn.Display();
}

struct Free {
	void operator()(int* p) {
		free(p);
		std::cout << "Pointer Freed!";
	}
};

//Function as a custom deleter
void MallocFree(int* p) {
	free(p);
	std::cout << "Pointer Freed!";
}

void CustomDelterForUniquePtr() {
	//std::unique_ptr <int> p{ (int*)malloc(4) };
	/*
		Calling the custom deleter, here Free{} creates a temporary object that calls the function call operator
		'operator()(int* p)'
		and releases the ocupied memory, which is known as Function object.
	*/
	//Two way to invoke custom deleter for unique_ptr
	std::unique_ptr<int, Free> p{ (int *)malloc(4), Free{} }; //Recomended
	//std::unique_ptr<int, void (*)(int *)> p{ (int*)malloc(4), MallocFree };
	*p = 100;
	std::cout << *p << std::endl;
}

void CustomDelterForSharedPtr() {
	//Two way to invoke custom deleter for shared_ptr
	std::shared_ptr<int> p{ (int*)malloc(4), Free{} }; //Recomended
	//std::shared_ptr<int> p{ (int*)malloc(4), MallocFree };
	*p = 100;
	std::cout << *p << std::endl;
}

void DynamicArrayWithUniquePtr(std::unique_ptr<int[]> &p) {
	//std::cout << p << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "P[" << i << "] => " << p[i] << std::endl;
	}
}

void TestMakeFunction() {
	std::unique_ptr<int[]> p{ new int[5] {1, 2, 3, 5, 6} };
	DynamicArrayWithUniquePtr(p);
	std::cout << p << std::endl;

	/*
		make_unique behaves as a factory function that creates a object on the heap memory
		that is specified in the <''> brackets
		And return a unique_ptr;
	*/
	//make_unique accepts arbitary no. of arguments
	{
		auto test0 = std::make_unique<Integer>(5);
		auto test1 = std::make_unique<Integer>(5, 'a', 1.2f);

		//For array, it is only possible to declare
		auto q = std::make_unique<int[]>(5);
		for (int i = 0; i < 5; i++)
		{
			std::cout << "Q[" << i << "] => " << q[i] << std::endl;
		}
	}

	{
		auto test0 = std::make_shared<int>(5);
		auto test1 = std::make_shared<Integer>(5, 'a', 1.2f);

		//For array, it is only possible to declare
		//auto q = std::make_shared<int[]>(5); //Added in c++20, previous version won't compile
		/*for (int i = 0; i < 5; i++)
		{
			std::cout << "Q[" << i << "] => " << q[i] << std::endl;
		}*/
	}

}

int main() {
	//OperateAsRaw(2);
	//OperateAsSmart(2);

	//CheckSharedPointer();
	/*Make(make_unique, make_shared) function are recomended over hardcode allocation */
	//CheckWeakPointer();
	//CustomDelterForUniquePtr();
	
}