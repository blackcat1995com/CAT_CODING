#pragma once
#include <iostream>
using namespace std;

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif // DLL_EXPORTS

class Cat {
public:
	virtual void output() = 0;
};

class MyCat :public Cat {
	void output();
};

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int a = 123;
	int Max(int a, int b);
	int Min(int a, int b);

	Cat* BlackCat();

#ifdef __cplusplus
}
#endif // __cplusplus

class DLL_API Student {
public:
	void output() {
		cout << "I am a student." << endl;
	}
};