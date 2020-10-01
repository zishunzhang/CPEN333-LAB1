#include "rt.h"

int main()
{
	cout << "Creating Child Processes.....\n";

	CProcess p1("C:\\Lab 2\\Part-C\\Debug\\PartC-Child1.exe 1 2 3",// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);


	CProcess p2("C:\\Lab 2\\Part-C\\Debug\\PartC-Child2.exe  3 4 5",// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	CProcess p3("C:\\Lab 2\\Part-C\\Debug\\PartC-Child3.exe  5 6 7",// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	p1.WaitForProcess(); // pause parent until child terminates
	cout << "Child1 process done \n";
	p2.WaitForProcess(); // pause parent until child terminates
	cout << "Child2 process done \n";
	p3.WaitForProcess(); // pause parent until child terminates
	cout << "Child3 process done \n";

	return 0;
}