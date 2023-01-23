#include <iostream>
#include <cstdio>
using namespace std;

// 全局区 默认没有初始化是0
int a;

int main() {
	
    // main内部 局部变量 栈区 默认没有初始化是随机值
    cout << a << endl;
    
    int b;
    cout << b << endl;
    
    int c;
    cout << c << endl;
    
    int d;
    cout << d << endl;
    
    // -2^31 ~ 2^31-1
    
    cout << &a << " " << &b << " " << &c << " " << &d << endl;

	return 0;
}

