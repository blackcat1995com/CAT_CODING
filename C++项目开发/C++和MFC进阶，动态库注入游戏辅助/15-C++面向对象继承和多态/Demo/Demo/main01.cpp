//#include <iostream>
//using namespace std;
//
//class Animal {
///*
//private ˽�е� ����ⲿ�޷����� 
//protected �ܱ����� ����ⲿ�޷����� 
//*/
//protected:
//	int m_age;
//public: 
//	Animal() {
//		cout << "���๹�캯��" << endl;
//	}
//	void eat() {
//		cout << "������ԳԷ�" << endl;
//	}
//
//	void sleep() {
//		cout << "�������˯��" << endl;
//	}
//
//	~Animal() {
//		cout << "������������" << endl;
//	}
//};
//
//class Dog :public Animal {
//public:
//	Dog() {
//		cout << "���๹�캯��" << endl;
//	}
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
//		cout << m_age << endl;
//	}
//
//	~Dog() {
//		cout << "������������" << endl;
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