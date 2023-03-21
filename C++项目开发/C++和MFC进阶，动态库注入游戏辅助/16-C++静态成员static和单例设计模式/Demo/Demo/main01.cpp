//#include <iostream>
//using namespace std;
//
//class Student {
//private:
//	int m_id;
//	static int ms_count;
//public:
//	static int get_count() {
//		return ms_count;
//	}
//
//	Student(int id = 0) :m_id(id) {
//		ms_count++;
//	}
//
//	~Student() {
//		ms_count--;
//	}
//};
//
//int Student::ms_count = 0;
//
//int main() {
//
//	Student* stu1 = new Student(101);
//	cout << Student::get_count() << " " << stu1->get_count() << endl;
//
//	Student* stu2 = new Student(102);
//	cout << Student::get_count() << " " << stu1->get_count() << " " << stu2->get_count() << endl;
//
//	delete stu2;
//
//	cout << Student::get_count() << " " << stu1->get_count() << endl;
//
//	return 0;
//}