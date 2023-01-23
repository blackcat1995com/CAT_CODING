#include <iostream>
#include <cstdio>
using namespace std;

namespace cat1{
    int a = 1, b = 2;
}

namespace cat2{
    int a = 3, b = 4;
}

namespace cat3{
    int a = 4, b = 5;
}

namespace cat4{
    int a = 6, b = 7;
}

int main() {

	cout << cat1::a << " " << cat1::b << endl;
    cout << cat2::a << " " << cat2::b << endl;
    
    using namespace cat3;
    cout << a << " " << b << endl;
    
    using cat4::a;
    cout << a << endl;
    
	return 0;
}

