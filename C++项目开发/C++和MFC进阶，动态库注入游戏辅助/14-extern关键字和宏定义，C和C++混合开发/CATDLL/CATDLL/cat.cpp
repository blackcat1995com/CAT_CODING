#include "pch.h"
#include "cat.h"
#define DLL_EXPORT

__declspec(dllexport) int sum(int a, int b) {
	return a + b;
}