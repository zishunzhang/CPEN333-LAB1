#include"CLamp3Bulb.h"
#include<iostream>

CLamp3Bulb::CLamp3Bulb(int w1, int w2, int w3) {
	myBulbs[0] = new CBulb(w1);
	myBulbs[1] = new CBulb(w2);
	myBulbs[2] = new CBulb(w3);
	mySwitch = new CSwitch();
	std::cout << "CLamp3Bulb constructor being called" << std::endl;
}

CLamp3Bulb::~CLamp3Bulb() {
	delete mySwitch;
	delete myBulbs[0];
	delete myBulbs[1];
	delete myBulbs[2];
	std::cout << "CLamp3Bulb destructor being called" << std::endl;
}

CLamp3Bulb::CLamp3Bulb(const CLamp3Bulb& LampToCopy) {
	CSwitch* copySwitch;
	CBulb* copyBulbs[3];

	copyBulbs[0] = new CBulb(LampToCopy.myBulbs[0]->getPower());
	copyBulbs[0] = new CBulb(LampToCopy.myBulbs[0]->getPower());
	copyBulbs[0] = new CBulb(LampToCopy.myBulbs[0]->getPower());
	copySwitch = new CSwitch();
	if (LampToCopy.getState()) {
		Lampon();
	}
	else {
		Lampoff();
	}
	std::cout << "CLamp3Bulb copy constructor being called" << std::endl;
}

void CLamp3Bulb::Lampon() {
	mySwitch->turnon();
	myBulbs[0]->on();
	myBulbs[1]->on();
	myBulbs[2]->on();
}

void CLamp3Bulb::Lampoff() {
	mySwitch->turnoff();
	myBulbs[0]->off();
	myBulbs[1]->off();
	myBulbs[2]->off();
}

int CLamp3Bulb::getState() const {
	return mySwitch->getState();
}

void CLamp3Bulb::print() {
	switch (mySwitch->getState()) {
	case 0:
		std::cout << "on" << std::endl;
		break;
	case 1:
		std::cout << "off" << std::endl;
		break;
	default:
		std::cout << "Unknown state" << std::endl;
	}
}

int CLamp3Bulb::getPower() {
	return myBulbs[0]->getPower() + myBulbs[1]->getPower() + myBulbs[2]->getPower();
}

CBulb* CLamp3Bulb::exchange(CBulb* newBulb, int bulbNumber) {
	CBulb* oldBulb = myBulbs[bulbNumber];
	myBulbs[bulbNumber] = newBulb;
	return oldBulb;
}




