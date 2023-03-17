//#include <iostream>
//#include <string>
//using namespace std;
//
//class Animal {
//
//public:
//	int m_age;
//	virtual void eat() {
//		cout << "动物吃饭" << endl;
//	}
//
//	void sleep() {
//		cout << "动物睡觉" << endl;
//	}
//
//	virtual ~Animal() {
//		cout << "父类析构" << endl;
//	}
//};
//
//class Dog : public Animal {
//public:
//	int m_weight = 0x5678ccdd;
//	int m_height = 0xabcdef;
//
//	virtual void eat() {
//		cout << "狗吃饭" << endl;
//	}
//
//	void sleep() {
//		cout << "狗睡觉" << endl;
//	}
//
//	void bark() {
//		cout << "狗可以叫" << endl;
//	}
//
//	~Dog() {
//		cout << "子类析构" << endl;
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