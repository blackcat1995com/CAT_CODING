//#include <iostream>
//#include <Windows.h>
//using namespace std;
//
//typedef int (*PMAX)(int, int);
//
//int main() {
//
//	HMODULE hModule = LoadLibrary(TEXT("Dll.dll"));
//	PMAX pMax = (PMAX)GetProcAddress(hModule, "Max");
//	cout << pMax(8, 6) << endl;
//	FreeLibrary(hModule);
//
//	return 0;
//}