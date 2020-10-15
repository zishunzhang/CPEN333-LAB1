/*
**	Win32 code program to solve the graphical problem illustrated previously. The double Producer
**	Single Consumer arrangement. Let's assume this is both the Producer and the Parent program
*/

#include 	<stdio.h>
#include	"C:\RTExamples\rt.h"		

struct		mydatapooldata {		// template for the data in a datapool
	int 	x ;						
	char	c;
} ;

struct		mydatapooldata* TheDataPointer1;		// pointer to the actual data pool
struct		mydatapooldata* TheDataPointer2;

int 	main()
{
	CSemaphore		ps1("PS1", 0, 1) ;    // semaphore with initial value 0 and max value 1
	CSemaphore		ps2("PS2", 0, 1);    // semaphore with initial value 0 and max value 1
	CSemaphore		cs1("CS1", 1, 1) ;    // semaphore with initial value 1 and max value 1
	CSemaphore		cs2("CS2", 1, 1);    // semaphore with initial value 1 and max value 1

	char CharData[5] = { 'A','B','C','D','E' }; // To be written into datapool 2

//	Create two datapools and then get a pointer to it
	CDataPool dp1("MyDataPoolName1", sizeof(struct mydatapooldata)) ;
	TheDataPointer1 = (struct mydatapooldata*)dp1.LinkDataPool() ;	// get pointer to data pool
	CDataPool dp2("MyDataPoolName2", sizeof(struct mydatapooldata));
	TheDataPointer2 = (struct mydatapooldata*)dp2.LinkDataPool();

//
//	Now that we have created the semaphores, let's create the child process
//
	CProcess p1("C:\\RTExamples\\Q9 - ProducerConsumerProblem\\Q9Child\\debug\\Q9Child.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,					// process has its own window
		ACTIVE							// process is active immediately
	) ;


	printf("Producer 1 Process Running.....\n") ;

	for(int i = 0; i < 5; i ++)	 {	// Produce 5 lots of data
		cs1.Wait() ;			// wait for consumer process to signal consumer semaphore
		cout << "Hit RETURN to Produce Data.....\n";
		getchar() ;
		TheDataPointer1->x = i ;	// generate data and store in datapool
		ps1.Signal() ;			// signal the producer semaphore to wake up the consumer
		cout << "Produced " << i << ".....\n";
	}

	printf("\nProducer 2 Process Running.....\n");

	for (int i = 0; i < 5; i++) {	// Produce 5 lots of data
		cs2.Wait();			// wait for consumer process to signal consumer semaphore
		cout << "Hit RETURN to Produce Data.....\n";
		getchar();
		TheDataPointer2->c = CharData[i];	// generate data and store in datapool
		ps2.Signal();			// signal the producer semaphore to wake up the consumer
		cout << "Produced " << CharData[i] << ".....\n";
	}

	p1.WaitForProcess() ;		// wait for the child process to terminate 

	return 0 ;				// sempahores destroyed here
}