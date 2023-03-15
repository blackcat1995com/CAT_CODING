#include <iostream>
#include <Windows.h>
//#include "../../CATDLL/CATDLL/cat.h"
using namespace std;

//#pragma comment(lib, "CATDLL.lib")

typedef int (*PSUM)(int, int);

int main() {

	HMODULE hModule = LoadLibrary(TEXT("CATDLL.dll"));

	PSUM psum = (PSUM)GetProcAddress(hModule, "sum");

	cout << psum(4, 5) << endl;

	FreeLibrary(hModule);

	return 0;
}
