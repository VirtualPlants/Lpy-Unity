#include "Header.h"
#include <iostream>

DLL void DoWork(ProgressCallback progressCallback)
{
	int counter = 0;

	for (; counter <= 100; counter++)
	{
		// do the work...

		if (progressCallback)
		{
			// send progress update
			progressCallback(counter);
		}
	}
}

DLL int ProcessFile(GetFilePathCallback getPath, char *path)
{
	if (getPath)
	{
		// get file path...
		getPath(path);

		return 1;
	}
	return 2;
}