#include "pch.h"
#include "cat.h"

extern "C" _declspec(dllexport) int sum(int a, int b) {
	return a + b;
}