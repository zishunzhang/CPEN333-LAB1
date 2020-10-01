#include "rt.h"

int main(int argc, char* argv[])
{
	cout << "argc count =" << argc << "\n";

	for (int i = 0; i < argc; i++) {			// set up loop to print out all args
		cout << "Passed information from parent: " << argv[i] << "\n";
		Sleep(3000);
	}

	return 0;		// exit child program by returning status value 0

}