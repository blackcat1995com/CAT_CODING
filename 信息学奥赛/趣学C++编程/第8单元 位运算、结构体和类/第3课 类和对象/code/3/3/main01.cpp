#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class Student {
private:
	char* m_name;
	int m_age;

	void copyName(const char* name) {
		if (name == NULL) return;
		m_name = new char[strlen(name) + 1]();
		strcpy(m_name, name);
	}
public:
	/*Student(char* name, int age):m_name(name), m_age(age){}*/
	Student(const char* name, int age) {
		copyName(name);
		m_age = age;
	}

	Student(const Student& stu) {
		copyName(stu.m_name);
		m_age = stu.m_age;
	}

	void output() {
		cout << m_name << " " << m_age << endl;
	}

	void changeName(int i, char x) {
		m_name[i] = x;
	}

	~Student() {
		if (m_name == NULL) return;
		delete[] m_name;

		//printf("%p\n", m_name);
		m_name = NULL;
	}
};
int main() {

	char* name = new char[20]();
	memcpy(name, "noi.hioier.com", 20);

	Student stu1("xxx", 28);
	stu1.output();

	Student stu2 = stu1;
	stu2.output();

	stu1.changeName(0, 'w');
	stu1.changeName(1, 'w');
	stu1.changeName(2, 'w');
	stu2.output();

	stu1.output();
	//char name[20] = "blackcat"; // {'b','l', ... , '\0'} 
	//Student* stu1 = new Student(name, 28);
	//name[0] = 'x';
	//stu1->output();
	//stu1->changeName(2, 'y');
	//cout << name << endl;

	//delete stu1;

	getchar();
	return 0;
}