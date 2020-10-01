#include "rt.h"

struct myStruct
{
	int a;
	string b;
	char c;
};
struct myStruct NameData[3] = { 
	{1, "Derek", 'D'},
	{2, "Zishun", 'Z'},
	{3, "Zhang", 'Z'},
}; // an array of thread numbers, strings and chars, one passed to each thread to identify it



UINT __stdcall ChildThread(void* args)	// A thread function 
{
	auto Name = (struct myStruct*)args;
	for (int i = 0; i < 10; i++) {
		cout << "The " << Name->a << " part of my name is: "<< Name->b << ", and initial is: "<< Name->c << "\n" << endl;
		Sleep(100);
	}
	return 0;
}


int main()
{
	CThread* Threads[3];

	for (int i = 0; i < 3; i++)
		Threads[i] = new CThread(ChildThread, ACTIVE, &NameData[i]);
	

	// wait for threads and then delete thread objects we created above
	for (int j = 0; j < 3; j++) {
		Threads[j]->WaitForThread();
		delete Threads[j];
	}

	return 0;
}