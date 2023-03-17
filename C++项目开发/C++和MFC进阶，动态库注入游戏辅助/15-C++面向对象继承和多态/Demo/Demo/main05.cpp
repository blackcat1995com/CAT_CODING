//#include <iostream>
//#include <string>
//using namespace std;
//
//class Father {
//public:
//	int a;
//
//	virtual void hobby() {
//		cout << "Father()::hobby()" << endl;
//	}
//};
//
//class Mother {
//public:
//	int b;
//
//	virtual void job() {
//		cout << "Mother()::job()" << endl;
//	}
//};
//
//class Me : public Father, public Mother {
//public:
//	virtual void hobby() {
//		cout << "Me()::hobby()" << endl;
//	}
//
//	virtual void job() {
//		cout << "Me()::job()" << endl;
//	}
//
//	void play() {
//		cout << "Me()::play()" << endl;
//	}
//};
//
//int main() {
//
//	Me* me = new Me();
//	
//	me->a = 0x11111111;
//	me->b = 0x22222222;
//
//	me->hobby();
//	me->job();
//	me->play();
//
//	cout << sizeof(Me) << endl;
//
//	return 0;
//}