#include <iostream>
#include <cstdio>
#include "E:\��èϵ�пγ�\Windows API MFC��� ��Ϸ���������򹤳�\��4�� ��̬���ӿ�\1.��̬���ӿ�Ͷ�̬���ӿ�\code\MyDll\MyDll\cat.h"

using namespace std;

extern "C" __declspec(dllimport) int add(int a, int b);

//#pragma comment(lib, "MyDll.lib")

int main() {

	cout << add(6, 9) << endl;

	return 0;
}
