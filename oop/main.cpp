#include "Car.h"
#include "Integers.h"
#include <iostream>

void CurExe() {
	Car::ShowCount();
	//Car car;
	Car car(6.0f);
	car.Dashboard();
	//car.FillFuel(5.5);
	car.Accelarate();
	car.Accelarate();
	car.Dashboard();
	car.AddPassengers(4);
	car.Accelarate();
	car.Dashboard();
	car.Brake();
	car.Accelarate();

	Car c1, c2;
	car.Dashboard();
	Car::ShowCount();

	const Car c3(8);
	c3.DashboardMini();
}
void CurExeDelegateCheck() {
	Car c0(6.0f);
	c0.Dashboard();

	Car c1(6.0f, 4);
	c1.Dashboard();

	Car c3;
	c3.Dashboard();
}

void IntegersExe() {
	Integers i(3);
	Integers i2(i);

	std::cout << i.GetValue() << std::endl;
	std::cout << i2.GetValue() << std::endl;
}

int main() {
	//CurExe();
	CurExeDelegateCheck();

	int* p1 = new int(5);
	//Shallow Copy
	int* p2 = p1;
	//Deep copy
	int* p3 = new int(*p1);
	//IntegersExe();

	return 0;
}