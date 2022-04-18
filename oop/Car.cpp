#include "Car.h"
#include <iostream>

int Car::totalCount = 0;

//Delegating Constructor
Car::Car():Car(0) {
	std::cout << "Car(0)" << std::endl;
}

Car::Car(float fuel):Car(fuel, 0) {
	std::cout << "Car(amount, 0)" << std::endl;
}

Car::Car(float fuel, int passengers) {
	std::cout << "Car(amount, passengers)" << std::endl;
	++totalCount;
	this->fuel = fuel;
	this->passengers = passengers;
	speed = 0;
}

Car::~Car() {
	--totalCount;
	std::cout << "~Car()" << std::endl;
}

void Car::FillFuel(float fuel) {
	this->fuel = fuel;
}

void Car::Accelarate() {
	++speed;
	fuel -= 0.5f;
}

void Car::Brake() {
	speed = 0;
}

void Car::AddPassengers(int passengers) {
	this->passengers = passengers;
}

void Car::Dashboard() {
	std::cout << "Fuel: " << fuel << std::endl;
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Passengers: " << passengers << std::endl;
	std::cout << std::endl;
}

void Car::ShowCount() {
	std::cout << "Total Count: " << totalCount << "\n" << std::endl;
}

void Car::DashboardMini() const {
	std::cout << "Constant Member Function" << std::endl;
	std::cout << "Fuel: " << fuel << std::endl;
	std::cout << "Passengers: " << passengers << std::endl;
}

