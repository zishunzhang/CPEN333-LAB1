#include "rt.h"

//
//	It's important to realise that all processes accessing the same datapool must
//	describe exactly the same datapool or structure template otherwise corruption
//	of data will occur. Ideally, the structure template would be put into a single header file
//	which would be '#include'd' into each program that used that datapool. However, for
//	simplicity, we have recreated the same template in each process
//

struct 	mydatapooldata {	// start of structure template
	int age;		
	char name;		
	int years[5];	
};							// end of structure template


int   main()
{
	int i;

	// 	Attempt to make the datapool 'Car1'. This process will not know
	//	whether the datapool exists or not yet (we know that it does because we only
	//	set the process running after the parent program had created it and stored data
	//	in it) but that shouldn't matter, since the program can just attempt to make it. If it already exists
	//	then it will simply use it. If it doesn't exist, then it will be created below


	cout << "Child 1 attempting to create/use the datapool.....\n";
	CDataPool 		dp("Car1", sizeof(struct mydatapooldata));

	// In order to access the data pool, we need a pointer to its location in memory. This is what
	// the LinkDataPool() primitive does as we saw in the parent program

	//	struct mydatapooldata 	 *MyDataPool = (struct mydatapooldata *)(0x1000) ;    // just to show an error

	struct mydatapooldata* MyDataPool = (struct mydatapooldata*)(dp.LinkDataPool());

	cout << "Child 1 linked to datapool at address : " << MyDataPool << ".....\n";

	// print out the data in the datapool that was stored there by the parent

	cout << "Child 1 Read value for age = " << MyDataPool->age << endl;
	cout << "Child 1 Read value for name = " << MyDataPool->name << endl;

	cout << "Child 1 Read values for years array = " << "\n";
	for (i = 0; i < 6; i++)
		cout << MyDataPool->years[i] << "\n";

	// The CDatapool object 'dp' created at the start of the program will now be destroyed
	// and provided there are no other processes using the same named datapool, then that datapool
	// will also be destroyed

	getchar();	// pause
	return 0;
}