#include "rt.h"

struct example1 {
	int age;
	int year;
}; // structure template for some data that we intend to read from pipeline

struct example1 mystruct1;

int main()
{
	printf("Child Process 1 Opening Pipeline 1.....\n");
	CTypedPipe<int>	p1("MyPipe1", 1024); // Create a int type Mypipe1

	p1.Read(&mystruct1.age);	// Read the structure from the pipeline
	p1.Read(&mystruct1.year);
	cout << "Child Process 1 read [" << mystruct1.age << "," << mystruct1.year << "] from Pipeline 1.....\n";

	while (1) {
		p1.Write(&mystruct1.age);	// Write to pipeline
		p1.Write(&mystruct1.year);
		cout << "Writing [" << mystruct1.age << "," << mystruct1.year << "] to Pipeline 1.....\n";
		Sleep(1500); //Vary delay time
	}

	return 0;
}