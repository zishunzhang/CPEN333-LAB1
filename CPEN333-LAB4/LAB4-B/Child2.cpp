#include "rt.h"

struct example2 {
	char initial_1;
	char initial_2; // My name is Derek Zhang
}; // structure template for some data that we intend to read from pipeline

struct example2 mystruct2;

int main()
{
	printf("Child Process 2 Opening Pipeline 2.....\n");
	CTypedPipe<char>	p2("MyPipe2", 1024); // Create a char type Mypipe1

	p2.Read(&mystruct2.initial_1);	// Read the structure from the pipeline
	p2.Read(&mystruct2.initial_2);	// Read the structure from the pipeline
	cout << "Child Process 2 read [" << mystruct2.initial_1 << "," << mystruct2.initial_2 << "] from Pipeline 2.....\n";

	while (1) {
		p2.Write(&mystruct2.initial_1);	// Write to pipeline
		p2.Write(&mystruct2.initial_2);
		cout << "Writing [" << mystruct2.initial_1 << "," << mystruct2.initial_2 << "] to Pipeline 2.....\n";
		Sleep(2000); //Vary delay time
	}

	return 0;
}