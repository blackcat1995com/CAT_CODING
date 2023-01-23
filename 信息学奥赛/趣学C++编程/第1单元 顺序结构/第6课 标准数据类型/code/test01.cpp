#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    
    cout << sizeof 123 << endl;
    cout << sizeof(char) << endl;
    
    int r;
    cin >> r;
    const double PI = 3.14;
    cout << PI << endl;
    cout << PI * r * r << " " << 2 * PI * r << endl; 
    
    // PI = 3.1415926;
    cout << sizeof PI << endl;

	return 0;
}

