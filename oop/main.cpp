#include "Car.h"

int main() {
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
	car.Dashboard();

	return 0;
}