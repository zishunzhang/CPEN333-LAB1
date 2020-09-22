#include <iostream>
#include "CBulb.h"


void CBulb::print() {
	switch (state) {
	case 0:
		std::cout << "off" << std::endl;
		break;
	case 1:
		std::cout << "on" << std::endl;
		break;
	default:
		std::cout << "Error, unknown state: " << state << std::endl;
	}
	
}

int CBulb::getState() {
	return state;
}

void CBulb::setstate(int new_state) {
	state = new_state;
}

CBulb::CBulb(): state(0), watts(0) {
	std::cout << "CBulb Default Constructor being called.." << std::endl;
}

CBulb::CBulb(int initial_watts) : state(0), watts(initial_watts) {}

CBulb::~CBulb() {
	std::cout << "CBulb Destructor being called.." << std::endl;
}


void CBulb::on() {
	state = 1;
}

void CBulb::off() {
	state = 0;
}

void CBulb::setWatts(int new_watts){
	watts = new_watts;
}

int CBulb::getPower() {
	if (state == 0)
		return 0;
	else {
		return watts;
	}
}