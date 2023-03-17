#include <iostream>
#include <string>
using namespace std;

class People {
public:
	int x = 0x9999;
};

class Father : virtual public People {
public:
	int a = 0x1111;
	virtual void hobby() {
		cout << "Father()::hobby()" << endl;
	}
};

class Mother : virtual public People {
public:
	int b = 0x2222;
};

class Me : public Father, public Mother {
public:
	virtual void hobby() {
		cout << "Me()::hobby()" << endl;
	}
	int c = 0xefef;
};

int main() {

	Me* me = new Me();

	cout << sizeof(Me) << endl;

	return 0;
}