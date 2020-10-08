#ifndef __LAB3__
#define __LAB3__
#include "rt.h"

class CoffeeMaker : public ActiveClass {
private:
	int CoffeeNumber;
	int main();
public:
	CoffeeMaker(int _CoffeeNumber) { CoffeeNumber = _CoffeeNumber; } //Constructor for a given integer argument
	int statusCM;
	void Start();
	void Stop();
};


class WashingMachine : public ActiveClass {
private:
	int WashNumber;
	int main();
	
public:
	WashingMachine(int _WashNumber) { WashNumber = _WashNumber; } //Constructor for a given integer argument
	int statusWM;
	void Start();
	void Stop();
};

#endif