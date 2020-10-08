#include "rt.h"


class CoffeeMaker : public ActiveClass 
{

private:
	int CoffeeNumber;

public:
	CoffeeMaker(int _CoffeeNumber) { CoffeeNumber = _CoffeeNumber; } //Constructor for a given integer argument

private:
	int main(void) 
	{
		cout << "#CM" << CoffeeNumber << ": Ready!\n" ;
		Sleep(2000); //Make sure all machines are ready 
		for (int i = 0; i < 3; i++) {
			cout << "Water filling in process... \n";
			Sleep(800);
		}
		for (int i = 0; i < 3; i++) {
			cout << "Water boiling in process... \n";
			Sleep(800);
		}
		for (int i = 0; i < 3; i++) {
			cout << "Coffee brewing in process... \n";
			Sleep(800);
		}
		for (int i = 0; i < 3; i++) {
			cout << "Coffee filtering in process... \n";
			Sleep(800);
		}
		cout << "Done! \n";
		return 0;
	}
}; 



class WashingMachine : public ActiveClass {

private:
	int WashNumber;

public:
	WashingMachine(int _WashNumber) { WashNumber = _WashNumber; } //Constructor for a given integer argument

private:
	int main(void)
	{
		cout << "#WM" << WashNumber << ": Ready!\n";
		Sleep(2000);
		for (int i = 0; i < 3; i++) {
			cout << "Filling in process... \n";
			Sleep(800); //As a timer
		}
		for (int i = 0; i < 3; i++) {
			cout << "Washing in process... \n";
			Sleep(800);
		}
		for (int i = 0; i < 3; i++) {
			cout << "Draining in process... \n";
			Sleep(800);
		}
		for (int i = 0; i < 3; i++) {
			cout << "Spinning in process... \n";
			Sleep(800);
		}
		cout << "Done! \n";
		return 0;
	}
};


int main (void)
{
	// create instance of the above active object on the stack
	// then allow it to run and then wait for it to terminate

	CoffeeMaker Coffee1(1), Coffee2(2), Coffee3(3), Coffee4(4), Coffee5(5);
	WashingMachine Wash1(1), Wash2(2), Wash3(3), Wash4(4), Wash5(5); 

	Coffee1.Resume();
	Sleep(100); // Make sure machines are ready in the correct order
	Coffee2.Resume();
	Sleep(100);
	Coffee3.Resume();
	Sleep(100);
	Coffee4.Resume();
	Sleep(100);
	Coffee5.Resume();

	Coffee1.WaitForThread(); // Wait for the process to finish
	Coffee2.WaitForThread();
	Coffee3.WaitForThread();
	Coffee4.WaitForThread();
	Coffee5.WaitForThread();

	Wash1.Resume();
	Sleep(100);
	Wash2.Resume();
	Sleep(100);
	Wash3.Resume();
	Sleep(100);
	Wash4.Resume();
	Sleep(100);
	Wash5.Resume();

	Wash1.WaitForThread();
	Wash2.WaitForThread();
	Wash3.WaitForThread();
	Wash4.WaitForThread();
	Wash5.WaitForThread();

	cout << "Finished! \n";

	return 0;

}