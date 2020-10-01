//#include "rt.h"
#include <iostream>
#include "Lab2.h"

int PartB() {
	std::string Path = "C:\\Lab 2\\Part-B\\CPEN-Lab2\\Debug\\Lab2Child1.exe";

	STARTUPINFO  StartupInfo = {
		sizeof(PROCESS_INFORMATION) ,
		nullptr ,		// reserved
		nullptr ,		// ignored in console applications
		(char*)(Path.c_str()) ,	// displayed in title bar for console applications
		0,0,		// dwx, dwy, offset of top left of new window relative to top left of screen in pixel
				// flags below must specify STARTF_USEPOSITION. Ignored for console apps'
		0,0,		// dwxsize, dwysize: Width and height of the window if new window specified
				// must use flags STARTF_USESIZE. Ignored for console apps'
		0,0,		// size of console in characters, only if STARTF_USECOUNTCHARS flag specified, 
				// Ignored for console apps
		0,		// Colour control, for background and text. Ignored for console apps
		0,		// Flags. Ignored for console applications
		0,		// ignored unless showwindow flag set
		0 ,
		NULL,
		0,0,0		// stdin, stdout and stderr handles (inherited from parent)

	};

	PROCESS_INFORMATION pInfo;
	UINT flags = NORMAL_PRIORITY_CLASS | CREATE_SUSPENDED;

	bool Success = CreateProcess(
		nullptr,			// application name
		(char*)(Path.c_str()), // Exe. pathlist		
		nullptr,			// process attributes
		nullptr,			// thread attributes
		TRUE,			// inherits handles of parent
		flags,			// Priority and Window control flags,
		NULL,			// use environment of parent
		NULL,			// use same drive and directory as parent
		&StartupInfo,			// controls appearance of process (see above)
		&pInfo			// Stored process handle and ID into this object
	);
	if (Success != TRUE) {
		cout << "Unable to Create New Process";
		return -1;
	}// check for error and print message if appropriate

	HANDLE ProcessHandle = pInfo.hProcess;		// handle to the child Process, can be used to identify a process
	HANDLE ThreadHandle = pInfo.hThread;		// handle to the child process's main thread, used to identify thread
	UINT ProcessID = pInfo.dwProcessId;		// Id of the Child Process (not the same as a handle)
	UINT ThreadID = pInfo.dwThreadId;		// Id of the Child Process's main thread (not the same as a handle)


	//Resume the thread
	UINT Result = ResumeThread(ThreadHandle);
	if (Result == 0xffffffff) {
		cout << "Cannot Resume Process";
		return -1;
	} // if ther is error



	//Wait for process to complete
	Result = WaitForSingleObject(ThreadHandle, INFINITE);
	// check for error and print message if appropriate== WAIT_OBJECT_0 ) 
	if (Result == WAIT_FAILED) {
		cout << "Cannot Wait for Child Process to Terminate.\n It might already be dead";
		return -1;
	}

	return 0;
}

int main() 
{
	std::cout << "Creating Child Processes.....\n" << std::endl;

	PartB();

	cout << "child process completed successfully";
	return 0;
}