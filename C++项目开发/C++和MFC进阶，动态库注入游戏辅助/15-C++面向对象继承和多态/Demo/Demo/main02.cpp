//#include <iostream>
//#include <string>
//using namespace std;
//
//class Animal {
//	/*
//	private ˽�е� ����ⲿ�޷�����
//	protected �ܱ����� ����ⲿ�޷�����
//	*/
//protected:
//	string m_name;
//	int m_age;
//public:
//	/*Animal() {
//		cout << "���๹�캯��" << endl;
//	}*/
//	/*Animal(string name, int age) {
//		m_name = name;
//		m_age = age;
//	}*/
//	Animal(string name, int age):m_name(name), m_age(age){}
//	void eat() {
//		cout << "������ԳԷ�" << endl;
//	}
//
//	void sleep() {
//		cout << "�������˯��" << endl;
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
//		cout << "���๹�캯��" << endl;
//	}*/
//
//	Dog(string name, int age, char gender):m_gender(gender), Animal(name, age){}
//	/*Dog(string name, int age, char gender) : Animal(name, age) {
//		m_gender = gender;
//	}*/
//	// ���෽���ض��� �ͽ�ԭ��
//	void eat() {
//		cout << "�����ԳԷ�" << endl;
//	}
//
//	void sleep() {
//		cout << "������˯��" << endl;
//	}
//
//	void bark() {
//		cout << "�����Խ�" << endl;
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
//	/*Animal ani("����", 0);
//	ani.output();*/
//	Dog dog("����", 7, 'm');
//	dog.output();
//	/*Dog dog("����", 7, 'm');
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