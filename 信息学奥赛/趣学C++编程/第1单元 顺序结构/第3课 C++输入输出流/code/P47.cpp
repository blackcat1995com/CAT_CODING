#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int a;
    cin >> a;
    
    // 获取个位数字 % 10       + - * / 
    cout << a % 10 << a / 10 << endl;
    
	return 0;
}

