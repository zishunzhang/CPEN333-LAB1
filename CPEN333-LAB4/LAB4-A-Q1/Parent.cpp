#include "rt.h"

// Let's suppose the data we want to put in the datapool is complex, i.e not just a simple
// int or char. The easiest way to store complex data is to introduce a structure template
// describing the names and types of the data we wich to group together as shown below
//  which includes three variables, two simple integers and an array of 10 integers

struct mydatapooldata {		
	int age;				
	char name;		
	int years[6];			
};					// end of structure 

int 	main()
{

	cout << "Parent attempting to create/use the datapool.....\n";
	CDataPool 		dp("Car1", sizeof(struct mydatapooldata));

	struct mydatapooldata* MyDataPool = (struct mydatapooldata*)(dp.LinkDataPool());

	printf("Parent linked to datapool at address %p.....\n", MyDataPool);

	// Now that we have the pointer to the datapool, we can put data into it

	cout << "Parent Writing value '24' to age variable.....\n";
	MyDataPool->age = 24;		

	cout << "Parent Writing char 'Z' to name variable.....\n";
	MyDataPool->name = 'Z';	

	cout << "Parent Writing value '2015-2020' to years array.....\n";
	for (int i = 0; i < 6; i++)
		MyDataPool->years[i] = i + 2015;

	//	Now that we have created the data pool and have stored data in it, it is safe to create
	//	a child process that can access the data

	getchar();

	CProcess p1("C:\\CPEN333-LAB4-A\\Debug\\Child.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window
		ACTIVE							// process is active immediately
	);

	CProcess p2("C:\\CPEN333-LAB4-A\\Debug\\Child2.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window
		ACTIVE							// process is active immediately
	);

	p1.WaitForProcess();		// wait for the child process to Terminate
	p2.WaitForProcess();

	return 0;				// CDataPool object 'dp' destroyed here
}