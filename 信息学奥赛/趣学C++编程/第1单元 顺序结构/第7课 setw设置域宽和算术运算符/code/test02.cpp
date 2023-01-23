#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const double PI = 3.14;

int main() {

    cout << PI << endl;
    cout << setprecision(6) << PI << endl;
    cout << setprecision(6) << 3.14159265358 << endl;
    
    cout << fixed << setprecision(6) << PI << endl;

	return 0;
}

