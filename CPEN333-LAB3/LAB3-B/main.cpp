#include "LAB3.h"
#include "rt.h"

int main(void)
{
	// create instance of the above active object on the stack
	// then allow it to run and then wait for it to terminate

	CoffeeMaker Coffee1(1), Coffee2(2), Coffee3(3), Coffee4(4), Coffee5(5);
	WashingMachine Wash1(1), Wash2(2), Wash3(3), Wash4(4), Wash5(5);

	Coffee1.Resume();
	Sleep(100);

	Coffee2.Resume();
	Sleep(100);
	Coffee2.Stop(); //Coffee2 will not show DONE message if stopped
	if (Coffee2.statusCM == 0)
		Coffee2.Suspend();

	Coffee3.Resume();
	Sleep(100);
	Coffee4.Resume();
	Sleep(100);
	Coffee5.Resume();

	Coffee1.WaitForThread();
	// Coffee2.WaitForThread();
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
	Sleep(100);
	Wash5.Stop();
	Sleep(200); //Allow time to react
	Wash5.Start(); // Wash 5 will stop and start
	if (Wash5.statusWM == 1) {};


	Wash1.WaitForThread();
	Wash2.WaitForThread();
	Wash3.WaitForThread();
	Wash4.WaitForThread();
	Wash5.WaitForThread();

	cout << "Finished! \n";

	return 0;

}