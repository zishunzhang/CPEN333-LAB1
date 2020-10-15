//////////////////////////////////////////////////////////////////////////////////
//	The Consumer 1 Process
//////////////////////////////////////////////////////////////////////////////////

#include 	<stdio.h>
#include	"C:\RTExamples\rt.h"			

struct		mydatapooldata {			// template for data in a datapool
	int x ;						
	char c;
} ;

struct		mydatapooldata* TheDataPointer1;		// pointer to the actual data pool
struct		mydatapooldata* TheDataPointer2;

int main()
{
	CSemaphore		ps1("PS1", 0, 1);    // semaphore with initial value 0 and max value 1
	CSemaphore		ps2("PS2", 0, 1);    // semaphore with initial value 0 and max value 1
	CSemaphore		cs1("CS1", 1, 1);    // semaphore with initial value 1 and max value 1
	CSemaphore		cs2("CS2", 1, 1);    // semaphore with initial value 1 and max value 1

//	Create a datapool and then get a pointer to it

	CDataPool dp1("MyDataPoolName1", sizeof(struct mydatapooldata)) ;
	TheDataPointer1 = (struct mydatapooldata*)(dp1.LinkDataPool()) ; // get pointer to data pool
	CDataPool dp2("MyDataPoolName2", sizeof(struct mydatapooldata));
	TheDataPointer2 = (struct mydatapooldata*)(dp2.LinkDataPool());

	cout << "Consumer Process Running.....\n";

	while (1) {
		if(ps1.Read() > 0){
			for (int i = 0; i < 5; i++) {	// consume 5 lots of data
				ps1.Wait();		// wait for producer process to signal producer semaphore
				cout << "Hit RETURN to Consume Data.....\n";
				getchar();
				cout << "Consumed: " << TheDataPointer1->x << '\n';
				cs1.Signal();		// signal the consumer semaphore to wake up the producer
			}
		}

		if (ps2.Read() > 0) {
			for (int i = 0; i < 5; i++) {	// consume 5 lots of data
				ps2.Wait();		// wait for producer process to signal producer semaphore
				cout << "Hit RETURN to Consume Data.....\n";
				getchar();
				cout << "Consumed: " << TheDataPointer2->c << '\n';
				cs2.Signal();		// signal the consumer semaphore to wake up the producer
			}
		}
	}

	getchar() ;
	return 0 ;
}
