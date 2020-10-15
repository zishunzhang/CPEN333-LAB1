#include "rt.h"
#include <thread>
#include <atomic>

atomic_flag flag;
// Solve the problem using Atomic_flag
class LAB5Class : public ActiveClass
{

private:
	ClassThread<LAB5Class>* ChildThread1;
	ClassThread<LAB5Class>* ChildThread2;
	ClassThread<LAB5Class>* ChildThread3;

	int coordinates[3] = { 20, 30, 40 }; //coords for cursor

	int ChildThreads(void* args)
	{
		int coords = *(int*)(args);
		for (int i = 0; i < 50000; i++) {
			while (flag.test_and_set() == true);	// spinlock
			MOVE_CURSOR(10, coords);             	// move cursor to cords [x,y] = 10, coords[i]
			cout << "Child Thread " <<coords/10 -1<< " running" << endl;  // Another way to assign ID number for child thread
			fflush(stdout);		      	// force output to be written to screen now
			flag.clear();
		}
		return 0;
	}

	int main(void) 
	{
		for (int i = 0; i < 50000; i++) {
			while (flag.test_and_set() == true);	// spinlock
			MOVE_CURSOR(5, 5);             	// move cursor to cords [x,y] = 5,5
			printf("Parent Thread 1 running\n");
			fflush(stdout);		      	// force output to be written to screen now
			flag.clear();
		}

		ChildThread1 = new ClassThread<LAB5Class>(this, &LAB5Class::ChildThreads, ACTIVE, &coordinates[0]); // create the 3 other child threads
		ChildThread2 = new ClassThread<LAB5Class>(this, &LAB5Class::ChildThreads, ACTIVE, &coordinates[1]);
		ChildThread3 = new ClassThread<LAB5Class>(this, &LAB5Class::ChildThreads, ACTIVE, &coordinates[2]);

		ChildThread1->WaitForThread(); // wait for the 3 other child threads to end
		ChildThread2->WaitForThread();
		ChildThread3->WaitForThread();
		delete ChildThread1;
		delete ChildThread2;
		delete ChildThread3;
					
		return 0;

	}
};

int main() {

	cout << "Atomic Flag solution started!" << endl;

	LAB5Class FlagThread;
	FlagThread.Resume();
	FlagThread.WaitForThread();

	return 0;
}