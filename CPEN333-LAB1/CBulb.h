#ifndef _CBulb_H_
#define _CBulb_H_

class CBulb {
private:
	int state;
	int watts;

public:
	void print();
	void setstate(int new_state);
	CBulb();
	CBulb(int initial_watts);
	~CBulb();
	void on();
	void off();
	int getState();
	void setWatts(int new_watts);
	int getPower();
	
};

#endif 