#include <iostream>
#include <cstdio>
using namespace std;

int main() {

	cout << sizeof(long long) << endl;
    cout << sizeof(123) << endl;
    cout << sizeof(123LL) << endl;
    
    int a = 0771;
    cout << a << endl;
    
    int b = 0xA1e;
    cout << b << endl;
    
    cout << sizeof(.3) << endl;
    cout << sizeof(3.) << endl;
    
	return 0;
}

