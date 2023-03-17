//#include <iostream>
//#include <string>
//using namespace std;
//
//class Animal {
//	/*
//	private 私有的 类的外部无法访问
//	protected 受保护的 类的外部无法访问
//	*/
//protected:
//	string m_name;
//	int m_age;
//public:
//	/*Animal() {
//		cout << "父类构造函数" << endl;
//	}*/
//	/*Animal(string name, int age) {
//		m_name = name;
//		m_age = age;
//	}*/
//	Animal(string name, int age):m_name(name), m_age(age){}
//	void eat() {
//		cout << "动物可以吃饭" << endl;
//	}
//
//	void sleep() {
//		cout << "动物可以睡觉" << endl;
//	}
//	void output() {
//		cout << m_name << " " << m_age << endl;
//	}
//};
//
//class Dog :public Animal {
//private:
//	char m_gender;
//public:
//	/*Dog() {
//		cout << "子类构造函数" << endl;
//	}*/
//
//	Dog(string name, int age, char gender):m_gender(gender), Animal(name, age){}
//	/*Dog(string name, int age, char gender) : Animal(name, age) {
//		m_gender = gender;
//	}*/
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
//		cout << m_name << " " << m_age << " " << m_gender << endl;
//	}
//
//};
//
//int main() {
//
//	/*Animal ani("动物", 0);
//	ani.output();*/
//	Dog dog("旺财", 7, 'm');
//	dog.output();
//	/*Dog dog("旺财", 7, 'm');
//	dog.output();*/
//	/*{
//		Dog dog;
//	}*/
//	/*dog.eat();
//	dog.sleep();*/
//	/*dog.bark();
//	dog.output();*/
//
//	return 0;
//}