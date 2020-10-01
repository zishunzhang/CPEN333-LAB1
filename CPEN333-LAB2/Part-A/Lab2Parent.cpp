#include "rt.h"
#include <iostream>

int main() 
{
	cout << "Creating Child Processes.....\n";

	CProcess p1("C:\\Lab 2\\Part-A\\CPEN-Lab2\\Debug\\Lab2Child1.exe",// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	
	CProcess p2("C:\\Lab 2\\Part-A\\CPEN-Lab2\\Debug\\Lab2Child2.exe",// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	CProcess p3("C:\\Lab 2\\Part-A\\CPEN-Lab2\\Debug\\Lab2Child3.exe",// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	cout << "Child Processes Activated.....\n";

	cout << "Waiting For Child1 to Terminate.....\n";
	p1.WaitForProcess();

	cout << "Waiting For Child2 to Terminate.....\n";
	p2.WaitForProcess();					// wait for the child process to end

	cout << "Waiting For Child3 to Terminate.....\n";
	p3.WaitForProcess();					// wait for the child process to end

	return 0;
}