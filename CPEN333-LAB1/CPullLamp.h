#ifndef _CPULLLAMP_H_
#define _CPULLLAMP_H_

#include "CLamp3Bulb.h"

class CPullLamp : public CLamp3Bulb {

public:
	CPullLamp(int w1, int w2, int w3);
	void toggle();

private:
	void Lampon() {}	// empty private function
	void Lampoff() {}

};

#endif
