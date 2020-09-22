#include"CSwitch.h"
#include<iostream>

CSwitch::CSwitch(): state(0){
	std::cout << "CSwitch constructor being called" << std::endl;
}

CSwitch::~CSwitch() {
	std::cout << "CSwitch cdestructor being called" << std::endl;
}

void CSwitch::turnon() {
	state = 1;
}

void CSwitch::turnoff() {
	state = 0;
}

int CSwitch::getState() {
	return state;
}

void CSwitch::print() {
	switch (getState()) {
	case 0:
		std::cout << "off" << std::endl;
		break;
	case 1:
		std::cout << "on" << std::endl;
		break;
	default:
		std::cout << "Unknown state" << std::endl;
	}
}