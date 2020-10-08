#ifndef __LAB3__
#define __LAB3__
#include "rt.h"

class CoffeeMaker : public ActiveClass {
private:
	int CoffeeNumber;
	int main();
	CThread* Inlet_Thread;
	CThread* Heater_Thread;

public:
	CoffeeMaker(int _CoffeeNumber) { CoffeeNumber = _CoffeeNumber; } //Constructor for a given integer argument
	int statusCM = 1;
	void Start();
	void Stop();
};


class WashingMachine : public ActiveClass {
private:
	int WashNumber;
	int main();
	CThread* Valve_Thread;
	CThread* Motor_Thread;

public:
	WashingMachine(int _WashNumber) { WashNumber = _WashNumber; } //Constructor for a given integer argument
	int statusWM = 1;
	void Start();
	void Stop();
};

#endif
