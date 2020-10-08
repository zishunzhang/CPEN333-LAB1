#include "rt.h"

struct example1 {
	int age;
	int year;
};
// structure template for some data that we intend to write to the pipeline
struct example2 {
	char initial_1;
	char initial_2; // My name is Derek Zhang
};

struct example1 mystruct1 = { 24, 2020 };
struct example2 mystruct2 = { 'D', 'Z'};

int main()
{
	cout << "Parent Process Creating Int Type Pipeline 1.....\n";
	CTypedPipe<int>	pipe1("MyPipe1", 1024);							// Create a int type Mypipe1
	cout << "Parent Process Creating Char Type Pipeline 2.....\n";
	CTypedPipe<char> pipe2("MyPipe2", 1024);						// Create a char type Mypipe2

	cout << "Parent Process Creating Child Process to Read from Pipelines.....\n";

	CProcess p1("C:\\CPEN333-LAB4-B\\Debug\\Child1.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	CProcess p2("C:\\CPEN333-LAB4-B\\Debug\\Child2.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	cout << "Hit RETURN to Write the structure [" << mystruct1.age << ", " << mystruct1.year << "] to the pipeline 1.....\n";
	getchar();
	pipe1.Write(&mystruct1.age);			// write the int structure to the pipeline 1
	pipe1.Write(&mystruct1.year);

	cout << "Hit RETURN to Write the structure [" << mystruct2.initial_1 << ", " << mystruct2.initial_2 << "] to the pipeline 2.....\n";
	getchar();
	pipe2.Write(&mystruct2.initial_1);			// write the char structure to the pipeline 2
	pipe2.Write(&mystruct2.initial_2);

	while (1) {
		pipe1.Read(&mystruct1.age);	// Read the structure from the pipeline
		pipe1.Read(&mystruct1.year);
		cout << "Received data [" << mystruct1.age << "," << mystruct1.year << "] from Pipeline 1.....\n";
		Sleep(1500); //Vary delay time
		pipe2.Read(&mystruct2.initial_1);	// Read the structure from the pipeline
		pipe2.Read(&mystruct2.initial_2);
		cout << "Received data [" << mystruct2.initial_1 << ", " << mystruct2.initial_2 << "] from the pipeline 2.....\n";
		Sleep(2000); //Vary delay time
	}

	p1.WaitForProcess();
	p2.WaitForProcess();

	return 0;
}