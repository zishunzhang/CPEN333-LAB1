#include "rt.h"
#include "LAB3.h"

void CoffeeMaker::Start() {
	statusCM = 1; 
	cout << "#CM" << CoffeeNumber << " START" << "\n";
}  //Control and return the status of the machine

void CoffeeMaker::Stop() {
	statusCM = 0;
	cout << "#CM" << CoffeeNumber << " STOP" << "\n";
}

int CoffeeMaker::main()
{
	cout << "#CM" << CoffeeNumber << ": Ready!\n";
	Sleep(2000);
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
	cout << "#CM" << CoffeeNumber << " Done!\n";
	return 0;

}
	
void WashingMachine::Start() {
	statusWM = 1;
	cout << "#WM" << WashNumber << " START" << "\n";
}  //Control and return the status of the machine

void WashingMachine::Stop() {
	statusWM = 0;
	cout << "#WM" << WashNumber << " STOP" << "\n";
}

int WashingMachine::main()
{
	cout << "#WM" << WashNumber << ": Ready!\n";
	Sleep(2000);
	for (int i = 0; i < 3; i++) {
		cout << "Filling in process... \n";
		Sleep(800);
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
	cout << "#WM" << WashNumber << " Done!\n";
	return 0;
}

