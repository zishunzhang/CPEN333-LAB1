//////////////////////////////////////////////////////////////////////////////////
//	The Consumer 1 Process
//////////////////////////////////////////////////////////////////////////////////

#include 	<stdio.h>
#include	"C:\RTExamples\rt.h"			

struct		mydatapooldata {			// template for data in a datapool
	int x ;						// just a single int
} ;

struct		mydatapooldata 		*TheDataPointer ;		// pointer to the data pool

int main()
{
	CSemaphore		ps1("PS1", 0, 1) ;    // semaphore with initial value 0 and max value 1
	CSemaphore		cs1("CS1", 1, 1) ;    // semaphore with initial value 1 and max value 1

//	Create a datapool and then get a pointer to it

	CDataPool dp1("MyDataPoolName", sizeof(struct mydatapooldata)) ;
	TheDataPointer = (struct mydatapooldata *)(dp1.LinkDataPool()) ; // get pointer to data pool

	cout << "Consumer 1 Process Running.....\n";
	for(int i = 0; i < 10; i++) {	// consume 10 lots of data
		cout << "Hit RETURN to Consume Data.....\n";
		getchar() ;
		ps1.Wait() ;		// wait for producer process to signal producer semaphore
		cout << "Consumed: " << TheDataPointer->x << '\n' ;
		cs1.Signal() ;		// signal the consumer semaphore to wake up the producer
	}

	getchar() ;
	return 0 ;
}
