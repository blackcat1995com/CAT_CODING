#include <iostream>
using namespace std;

class Student {
private:
	static int ms_id;
	static Student* ms_stu;
	Student(){};
	~Student(){};
public:
	static Student* createStudent(int id) {
		if (ms_stu == NULL) {
			ms_stu = new Student();
			ms_id = id;
		}

		return ms_stu;
	}

	static void deleteStudent() {
		if (ms_stu != NULL) {
			delete ms_stu;
			ms_id = -1;
		}
	}

	static int getStudentId() {
		return ms_id;
	}
};

int Student::ms_id = -1;
Student* Student::ms_stu = NULL;

int main() {

	Student* stu = Student::createStudent(101);
	cout << stu->getStudentId() << endl;

	Student* stu2 = Student::createStudent(102);
	cout << stu2->getStudentId() << endl;

	stu->deleteStudent();
	cout << stu->getStudentId() << endl;

	return 0;
}