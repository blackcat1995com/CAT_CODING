#include <iostream>
#include <Windows.h>
#include "../../Dll/Dll/cat.h"
using namespace std;
#pragma comment(lib, "Dll.lib")

DWORD WINAPI ThreadProc(LPVOID lpParameter) {
	cout << Max(3, 5) << endl;
	cout << Min(3, 5) << endl;

	return 0;
}

int main() {

	//cout << Max(3, 6) << endl;
	CreateThread(0, 0, ThreadProc, 0, 0, 0);
	getchar();

	return 0;
}