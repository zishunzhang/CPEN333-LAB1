#include "rt.h"

int main()
{
	int i;
	for (i = 0; i < 50; i++) {
		cout << "Hello from child process 1....\n";
		Sleep(50);
	}

	return 0;		// exit child program by returning status value 0
				// Note we could also call exit(0) to achieve the same thing
}