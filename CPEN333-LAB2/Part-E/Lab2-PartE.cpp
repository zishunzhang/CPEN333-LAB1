#include "Lab2.h"


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
	for (int i = 0; i < 20; i++) {
		cout << "The " << Name->a << " part of my name is: " << Name->b << ", and initial is: " << Name->c << "\n" << endl;
		Sleep(100);
	}
	return 0;
}


int main()
{
	HANDLE Threads[3];
	UINT ThreadID = pInfo.dwThreadId;

	//Suspended thread
	for (int i = 0; i < 3; i++) {
		Threads[i] = (HANDLE)(_beginthreadex(NULL, 0, ChildThread, (void*)&NameData[i], CREATE_SUSPENDED, &ThreadID));
		if (Threads[i] == 0) {
			cout << "Failed to create thread with id: " << i << endl;
			return -1;
		}
	}


	// Resume threads.
	for (int j = 0; j < 3; j++) {
		UINT result = ResumeThread(Threads[j]);
		if (result == 0xffffffff) {
			std::cout << "Cannot resume thread with id: " << ThreadID << std::endl;
			return -1;
		}
	}

	// Waiting for threads completion.
	for (int k = 0; k < 3; k++) {
		UINT result = WaitForSingleObject(Threads[k], INFINITE); // return WAIT_FAILED on error
		if (result == WAIT_FAILED) {
			cout << "Cannot wait for thread with id: " << ThreadID << endl;
			return -1;
		}
	}


	cout << "All threads done! \n";
	return 0;
}