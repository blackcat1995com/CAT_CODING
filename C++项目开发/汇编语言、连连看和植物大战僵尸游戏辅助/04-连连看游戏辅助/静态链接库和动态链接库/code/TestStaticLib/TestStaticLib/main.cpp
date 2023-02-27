#include <iostream>
#include <cstdio>
using namespace std;

//#pragma comment(lib, "MyStaticLib.lib")

extern int add(int a, int b);

int main() {

	cout << add(5, 8) << endl;

	return 0;
}
