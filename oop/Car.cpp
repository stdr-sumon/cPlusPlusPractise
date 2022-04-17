#include "Car.h"
#include <iostream>

Car::Car() {
	fuel = 0;
	speed = 0;
	passengers = 0;
}

Car::Car(float amount) {
	std::cout << "Car()" << std::endl;
	fuel = amount;
	speed = 0;
	passengers = 0;
}

Car::~Car() {
	std::cout << "~Car()" << std::endl;
}

void Car::FillFuel(float amount) {
	fuel = amount;
}
void Car::Accelarate() {
	++speed;
	fuel -= 0.5f;
}
void Car::Brake() {
	speed = 0;
}
void Car::AddPassengers(int count) {
	passengers = count;
}
void Car::Dashboard() {
	std::cout << "Fuel: " << fuel << std::endl;
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Passengers: " << passengers << std::endl;
	std::cout << std::endl;
}