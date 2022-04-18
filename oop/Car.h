#pragma once //header guard -> prevent redeclaration
class Car {
private:
	//float fuel{ 0 }; //Non-static data member initialization
	//float speed{ 0 }; //Non-static data member initialization
	//int passengers{ 0 }; //Non-static data member initialization
	
	float fuel, speed;
	int passengers;
	static int totalCount;

public:
	Car();
	Car(float amount);
	Car(float amount, int passengers);
	~Car(); 
	void FillFuel(float fuel);
	void Accelarate();
	void Brake();
	void AddPassengers(int passengers);
	void Dashboard();
	static void ShowCount();
	void DashboardMini() const;
};