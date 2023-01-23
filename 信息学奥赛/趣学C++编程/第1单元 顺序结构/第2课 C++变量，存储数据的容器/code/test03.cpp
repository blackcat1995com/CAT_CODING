#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int a = 3, b = 4;
    
    int t = a;
    a = b;
    b = t;
    
    cout << a << " " << b << endl;

	return 0;
}

