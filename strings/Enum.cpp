#include <iostream>

/*
	Unscoped enum 
	-> Can not hold same name
*/
enum Color {RED, GREEN, BLUE};
enum TrafficLight { REDD, GREENN, BLUEE };

void FillColorUnscoped(Color color) {
	if (color == RED) {
		std::cout << "Color is RED" << std::endl;
	}
	else if (color == GREEN) {
		std::cout << "Color is GREEN" << std::endl;
	}
	else if (color == BLUE) {
		std::cout << "Color is BLUE" << std::endl;
	}
}

void CheckFillColorUnscoped() {
	Color c = RED;
	FillColorUnscoped(c);
	FillColorUnscoped(GREEN);
	FillColorUnscoped(static_cast<Color>(2));
	std::cout << c << std::endl;
}

/*
	Scoped enum
	-> Can hold same name
*/
enum class Farbe : int { RED = 4, GREEN, BLUE };
enum class Ampel : char { RED = 'r', GREEN, BLUE };

void FillColorScoped(Farbe color, Ampel trafficLight) {
	if (color == Farbe::RED) {
		std::cout << "Color is RED" << std::endl;
	}
	else if (color == Farbe::GREEN || trafficLight == Ampel::GREEN) {
		std::cout << "Color is GREEN" << std::endl;
	}
	else if (color == Farbe::BLUE) {
		std::cout << "Color is BLUE" << std::endl;
	}
}
void CheckFillColorScoped() {
	Farbe c = Farbe::RED;
	//std::cout << c << std::endl; // Won't work, because there's no implicit conversion to int
	int x = static_cast<int>(c);
	std::cout << x << std::endl;

	FillColorScoped(c, Ampel::RED);
	FillColorScoped(Farbe::BLUE, Ampel::GREEN);
	FillColorScoped(static_cast<Farbe>(4), Ampel::RED);
}

/*
int main() {
	//CheckFillColorUnscoped();
	//CheckFillColorScoped();
}
*/