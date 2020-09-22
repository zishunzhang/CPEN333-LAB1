#ifndef _CLAMP3BULB_H_
#define _CLAMP3BULB_H_

#include "CSwitch.h"
#include "CBulb.h"

class CLamp3Bulb {

public:
	CLamp3Bulb(int w1, int w2, int w3);
	~CLamp3Bulb();
	void Lampon();
	void Lampoff();
	void print();
	int getState() const;
	int getPower();
	CBulb* exchange(CBulb* newBulb, int bulbNumber);
	CLamp3Bulb(const CLamp3Bulb &LampToCopy);

private:
	CSwitch* mySwitch;
	CBulb* myBulbs[3];

};


#endif
