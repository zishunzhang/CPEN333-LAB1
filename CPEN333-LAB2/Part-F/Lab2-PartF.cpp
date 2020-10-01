#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

struct myStruct
{
	int a;
	std::string b;
	char c;
};
struct myStruct NameData[3] = {
	{1, "Derek", 'D'},
	{2, "Zishun", 'Z'},
	{3, "Zhang", 'Z'},
}; // an array of thread numbers, strings and chars, one passed to each thread to identify it


int ChildThread(struct myStruct Name)	// A thread function 
{
	for (int i = 0; i < 10; i++) {
		cout << "The " << Name.a << " part of my name is: " << Name.b << ", and initial is: " << Name.c << "\n" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}

	return 0;
}

int main() {
	thread* Threads[3];

	for (int i = 0; i < 3; i++)
		Threads[i] = new thread(ChildThread, NameData[i]);


	// wait for threads and then delete thread objects we created above
	for (int j = 0; j < 3; j++) {
		Threads[j]->join();
		delete Threads[j];
	}

	return 0;
}