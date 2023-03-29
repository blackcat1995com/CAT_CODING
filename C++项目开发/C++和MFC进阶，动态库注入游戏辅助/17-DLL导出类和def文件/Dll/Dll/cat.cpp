#include "pch.h"
#include "cat.h"

int Max(int a, int b) {
	return a > b ? a : b;
}

int Min(int a, int b) {
	return a < b ? a : b;
}


void MyCat::output() {
	cout << "I am a cat." << endl;
}

Cat* BlackCat() {
	return new MyCat();
}
