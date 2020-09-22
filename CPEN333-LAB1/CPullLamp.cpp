#include "CPullLamp.h"
#include <iostream>

CPullLamp::CPullLamp(int w1, int w2, int w3)
	: CLamp3Bulb(w1, w2, w3)		// call base class constructor with watts
{
	std::cout << "CPullLamp constructor being called" << std::endl;
}

void CPullLamp::toggle() {
	if (getState() == 0) 
		CLamp3Bulb::Lampon();
	else 
		CLamp3Bulb::Lampoff();
}
