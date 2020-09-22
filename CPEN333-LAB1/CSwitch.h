#ifndef _CSwitch_H_
#define _CSwitch_H_

class CSwitch {

public:
	CSwitch();
	~CSwitch();
	void turnon();
	void turnoff();
	int getState();
	void print();

private:
	int state;

};




#endif
