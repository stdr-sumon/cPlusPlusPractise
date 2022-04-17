#pragma once
int Add(int a, int b);
double Add(double a, double b);
extern "C" {
	void Print(int* x);
}
void Print(const int* x);