//#include <iostream>
//#include <string>
//using namespace std;
//
//class Animal {
//
//public:
//	int m_age;
//	virtual void eat() {
//		cout << "����Է�" << endl;
//	}
//
//	void sleep() {
//		cout << "����˯��" << endl;
//	}
//
//	virtual ~Animal() {
//		cout << "��������" << endl;
//	}
//};
//
//class Dog : public Animal {
//public:
//	int m_weight = 0x5678ccdd;
//	int m_height = 0xabcdef;
//
//	virtual void eat() {
//		cout << "���Է�" << endl;
//	}
//
//	void sleep() {
//		cout << "��˯��" << endl;
//	}
//
//	void bark() {
//		cout << "�����Խ�" << endl;
//	}
//
//	~Dog() {
//		cout << "��������" << endl;
//	}
//};
//
//int main() {
//
//	Animal* dog = new Dog();
//	dog->m_age = 0x1234aabb;
//
//	dog->eat();
//	dog->sleep();
//
//	delete dog;
//	/*Animal ani;
//	cout << sizeof(ani) << endl;
//
//	Dog d;
//	cout << sizeof(d) << endl;*/
//	/*Dog* dog2 = new Animal();*/
//	// 7ff639cfbc68
//	return 0;
//}