#include "rt.h"
#include <thread>

// Solve the problem using Monitor
class Monitor {
private:
	CMutex* theMutex;	       // a pointer to a hidden mutex protecting the ‘ThreadData’ variable 

public:
	Monitor(string name) { theMutex = new CMutex(name); } // constructor creates a hidden mutex and destructor destroys it
	~Monitor() { delete theMutex; }

	void WriteToScreen(int x, int y, string id)
	{
		theMutex->Wait();
		MOVE_CURSOR(x, y);             	// move cursor to cords [x,y] 
		cout << "Thread " << id << " running" << endl;  // Another way to assign ID number for child thread
		fflush(stdout);		      				// force output to be written to screen now
		theMutex->Signal();
	}
};



class LAB5Class : public ActiveClass
{
private:
	ClassThread<LAB5Class>* ChildThread1;
	ClassThread<LAB5Class>* ChildThread2;
	ClassThread<LAB5Class>* ChildThread3;
	Monitor monitor1{ "MonitorName" }; // a monitor object with built in synchronization

	struct data {
		int x;
		int y;
		string name;
	};

	int ChildThreads(void* args) // Child thread print function
	{
		data arguments = *(data*)(args);
		for (int i = 0; i < 50000; i++) {
			monitor1.WriteToScreen(arguments.x, arguments.y, arguments.name);
		}
		return 0;
	}

	int main(void)
	{
		data ThreadData[4] = { {5,5, "Parent"}, {10,20,"Child 1"}, {10,30,"Child 2"}, {10,40,"Child 3"} };
		for (int i = 0; i < 50000; i++) {
			monitor1.WriteToScreen(ThreadData[0].x, ThreadData[0].y, ThreadData[0].name ); // Parent thread printing
		}

		ChildThread1 = new ClassThread<LAB5Class>(this, &LAB5Class::ChildThreads, ACTIVE, &ThreadData[1]); // create the 3 other child threads
		ChildThread2 = new ClassThread<LAB5Class>(this, &LAB5Class::ChildThreads, ACTIVE, &ThreadData[2]);
		ChildThread3 = new ClassThread<LAB5Class>(this, &LAB5Class::ChildThreads, ACTIVE, &ThreadData[3]);

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

	cout << "Monitor solution started!" << endl;

	LAB5Class MonitorThread;
	MonitorThread.Resume();
	MonitorThread.WaitForThread();

	return 0;
}