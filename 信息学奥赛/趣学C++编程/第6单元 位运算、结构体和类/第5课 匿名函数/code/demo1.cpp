#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    // auto f = [](int a, int b)->int{ return a + b; };
    // auto f = [](int a, int b){ return a + b; };

    int x = -1, y = -1;

    auto f = [&](int a, int b){
        x = 2, y = 3;
        cout << x << " " << y << endl;
        return a + b;
    };

    cout << f(3, 5) << endl;
	
	return 0;
}

