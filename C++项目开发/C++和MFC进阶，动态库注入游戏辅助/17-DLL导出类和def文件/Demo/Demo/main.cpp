#include <iostream>
#include "../../Dll/Dll/cat.h"
using namespace std;

#pragma comment(lib, "Dll.lib")

int main() {

	cout << a << endl;
	cout << Max(3, 5) << endl;
	cout << Min(3, 5) << endl;

	Student stu;
	stu.output();

	Cat* cat = BlackCat();
	cat->output();

	return 0;
}