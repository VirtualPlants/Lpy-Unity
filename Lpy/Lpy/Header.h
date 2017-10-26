#include "Windows.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define DLL __declspec(dllexport)
	typedef void(__stdcall * ProgressCallback)(int);
	typedef char* (__stdcall * GetFilePathCallback)(char* filter);

	DLL void DoWork(ProgressCallback progressCallback);
	DLL int ProcessFile(GetFilePathCallback getPath, char *path);

#ifdef __cplusplus
}
#endif