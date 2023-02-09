#include <iostream>
#include <cstdio>
#include "E:\黑猫系列课程\Windows API MFC编程 游戏辅助和逆向工程\第4章 动态链接库\1.静态链接库和动态链接库\code\MyDll\MyDll\cat.h"

using namespace std;

extern "C" __declspec(dllimport) int add(int a, int b);

//#pragma comment(lib, "MyDll.lib")

int main() {

	cout << add(6, 9) << endl;

	return 0;
}
