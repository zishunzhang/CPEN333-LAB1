#include "rt.h"
#include "LAB3.h"

int WorkStatus[2] = { 1,0 };

void CoffeeMaker::Start() {
	statusCM = 1;
	cout << "#CM" << CoffeeNumber << " START" << "\n";
}  //Control and return the status of the machine

void CoffeeMaker::Stop() {
	statusCM = 0;
	cout << "#CM" << CoffeeNumber << " STOP" << "\n";
}

UINT __stdcall InletThread(void* args)
{
	int InletStatus = *(int*)(args);
	if (InletStatus == 1)
		cout << "Inlet Opened" << "\n";
	else
		cout << "Inlet Closed" << "\n";
	return 0;
}

UINT __stdcall HeaterThread(void* args)
{
	int HeaterStatus = *(int*)(args);
	if (HeaterStatus == 1)
		cout << "Heater Turned On" << "\n";
	else
		cout << "Heater Turned Down" << "\n";
	return 0;
}

int CoffeeMaker::main()
{
	cout << "#CM" << CoffeeNumber << ": Ready!\n";
	Sleep(2000);

	Inlet_Thread = new CThread(InletThread, ACTIVE, &WorkStatus[0]); // Open inlet to add water
	Inlet_Thread->WaitForThread(); 	// wait for thread and then delete thread objects we created above
	delete Inlet_Thread;
	Sleep(2000); // Allow time to check all inlets before any processing
	for (int i = 0; i < 3; i++) {
		cout << "Water filling in process... \n";
		Sleep(800);
	}

	Heater_Thread = new CThread(HeaterThread, ACTIVE, &WorkStatus[0]); // Turn on heater to boil water
	Heater_Thread->WaitForThread(); 	// wait for thread and then delete thread objects we created above
	delete Heater_Thread;
	Sleep(2000);
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

////////////// Separating two machines

void WashingMachine::Start() {
	statusWM = 1;
	cout << "#WM" << WashNumber << " START" << "\n";
}  //Control and return the status of the machine

void WashingMachine::Stop() {
	statusWM = 0;
	cout << "#WM" << WashNumber << " STOP" << "\n";
}

UINT __stdcall ValveThread(void* args)
{
	int ValveStatus = *(int*)(args);
	if (ValveStatus == 1)
		cout << "Valve Opened" << "\n";
	else
		cout << "Valve Closed" << "\n";
	return 0;
}

UINT __stdcall MotorThread(void* args)
{
	int MotorStatus = *(int*)(args);
	if (MotorStatus == 1)
		cout << "Motor Running" << "\n";
	else
		cout << "Motor Not Working" << "\n";
	return 0;
}

int WashingMachine::main()
{
	cout << "#WM" << WashNumber << ": Ready!\n";
	Sleep(2000);

	Valve_Thread = new CThread(ValveThread, ACTIVE, &WorkStatus[0]); // Open valve
	Valve_Thread->WaitForThread(); 	// wait for thread and then delete thread objects we created above
	delete Valve_Thread;
	Sleep(2000);
	for (int i = 0; i < 3; i++) {
		cout << "Filling in process... \n";
		Sleep(800);
	}

	Motor_Thread = new CThread(MotorThread, ACTIVE, &WorkStatus[0]); // Start motor
	Motor_Thread->WaitForThread(); 	// wait for thread and then delete thread objects we created above
	delete Motor_Thread;
	Sleep(2000);
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

