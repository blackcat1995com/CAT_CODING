#include <iostream>
#include <Windows.h>
#include "../../CATDLL/CATDLL/cat.h"
using namespace std;

#pragma comment(lib, "CATDLL.lib")

//typedef int (*PSUM)(int, int);
DLL_API int sum(int a, int b);

int main() {


	cout << sum(3, 5) << endl;
	/*HMODULE hModule = LoadLibrary(TEXT("CATDLL.dll"));

	PSUM psum = (PSUM)GetProcAddress(hModule, "sum");

	cout << psum(4, 5) << endl;

	FreeLibrary(hModule);*/

	return 0;
}
