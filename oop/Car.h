#pragma once //header guard -> prevent redeclaration
class Car {
private:
	float fuel;
	float speed;
	float passengers;

public:
	Car();
	Car(float amount);
	~Car(); 
	void FillFuel(float amount);
	void Accelarate();
	void Brake();
	void AddPassengers(int count);
	void Dashboard();
};