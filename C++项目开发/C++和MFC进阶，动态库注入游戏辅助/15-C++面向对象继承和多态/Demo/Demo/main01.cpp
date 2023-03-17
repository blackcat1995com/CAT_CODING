//#include <iostream>
//using namespace std;
//
//class Animal {
///*
//private 私有的 类的外部无法访问 
//protected 受保护的 类的外部无法访问 
//*/
//protected:
//	int m_age;
//public: 
//	Animal() {
//		cout << "父类构造函数" << endl;
//	}
//	void eat() {
//		cout << "动物可以吃饭" << endl;
//	}
//
//	void sleep() {
//		cout << "动物可以睡觉" << endl;
//	}
//
//	~Animal() {
//		cout << "父类析构函数" << endl;
//	}
//};
//
//class Dog :public Animal {
//public:
//	Dog() {
//		cout << "子类构造函数" << endl;
//	}
//	// 父类方法重定义 就近原则
//	void eat() {
//		cout << "狗可以吃饭" << endl;
//	}
//
//	void sleep() {
//		cout << "狗可以睡觉" << endl;
//	}
//
//	void bark() {
//		cout << "狗可以叫" << endl;
//	}
//
//	void output() {
//		cout << m_age << endl;
//	}
//
//	~Dog() {
//		cout << "子类析构函数" << endl;
//	}
//};
//
//int main() {
//
//	{
//		Dog dog;
//	}
//	/*dog.eat();
//	dog.sleep();*/
//	/*dog.bark();
//	dog.output();*/
//
//	return 0;
//}