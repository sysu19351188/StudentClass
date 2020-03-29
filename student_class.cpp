#include<iostream>
#include"student.h"
#include"student_class.h"
using namespace std;

int StudentClass::studentCount_ = 0;
StudentClass::StudentClass() {
	int i;
	code_ = "ise201901";
	for (i = 0; i < maxStudents_; i++)
	{
		students_[i]->id_ = 1 + i;
		students_[i]->name_ = "zh";
		students_[i]->courseNames_[0] = "English";
		students_[i]->courseNames_[1] = "History";
		students_[i]->courseNames_[2] = "Technology";
		students_[i]->grades_[0] = 90;
		students_[i]->grades_[1] = 91;
		students_[i]->grades_[2] = 92;
		studentCount_++;
	}
}

StudentClass::StudentClass(std::string code, Student students[maxStudents_]) {
	int i;
	code_ = code;
	for (i = 0; i < maxStudents_; i++)
	{
		students_[i] = &students[i];
		studentCount_++;
	}
}
StudentClass::StudentClass(const StudentClass& p) {
	int i;
	code_ = p.code_;
	for (i = 0; i < maxStudents_; i++)
	{
		students_[i] = p.students_[i];
		studentCount_++;
	}
}
void StudentClass::set(std::string code, Student students[maxStudents_]) {
	int i;
	code_ = code;
	for (i = 0; i < maxStudents_; i++)
	{
		students_[i] = &students[i];
	}studentCount_++;
}
void StudentClass::show() const {
	int i;
	cout << "班级:" << code_ << endl;
	cout << "学生资料：" << endl;
	cout << "id:\tname:\tcoursename:\t\t\tgrades:" << endl;
	for (i = 0; i < maxStudents_; i++)
	{
		if (students_[i]->id_ > 0)
		{
			cout << students_[i]->id_ << "\t" << students_[i]->name_ << "\t";
			cout << students_[i]->courseNames_[0] << "\t" << students_[i]->courseNames_[1] << "\t";
			cout << students_[i]->courseNames_[2] << "\t" << students_[i]->grades_[0] << " ";
			cout << students_[i]->grades_[1] << " " << students_[i]->grades_[2] << endl;
		}
		else break;
	}
}
bool StudentClass::AddStudent(const Student student) {
	if (studentCount_ < maxStudents_)
	{
		students_[studentCount_ + 1] = (Student*)&student;
		return 1;
	}
	else return 0;
}
void StudentClass::ShowStudent(int id) const {
	int i, j = 0;
	for (i = 0; i < maxStudents_; i++)
	{
		if (students_[i]->id_ == id)
		{
			cout << "这个学生的信息是：" << endl;
			cout << students_[i]->id_ << "\t" << students_[i]->name_ << "  ";
			cout << students_[i]->courseNames_[0] << "  " << students_[i]->courseNames_[1] << "  ";
			cout << students_[i]->courseNames_[2] << "  " << students_[i]->grades_[0] << "  ";
			cout << students_[i]->grades_[1] << "  " << students_[i]->grades_[2] << endl;
		}
		else j++;
	}
	if (j == maxStudents_)
		cout << "没有这个学生";
}
bool ascending(int a, int b) {
	return a < b;
}
bool descending(int a, int b) {
	return a > b;
}
void swap(Student* const a, Student* const b) {
	Student t = *a;
	*a = *b;
	*b = t;
}
void StudentClass::ShowStudentsByIdOrder(bool (*compare)(int, int)) {
	int smallestorlargest, i, j = 0;
	for (int i = 0; i < maxStudents_; i++)
	{
		if (students_[i]->id_ > 0)
			j++;
		else break;
	}
	for (int i = 0; i < maxStudents_; i++)
	{
		if (students_[i]->id_ > 0)
		{
			smallestorlargest = i;
			for (int index = i + 1; index < j; index++)
				if (!(*compare)(students_[smallestorlargest]->id_, students_[index]->id_))
					smallestorlargest = index;
			swap(students_[smallestorlargest], students_[i]);
		}
		else break;
	}
	cout << endl << "班级:" << code_ << endl;
	cout << "id:\tname:\tcoursename:\t\t\tgrades:" << endl;
	for (i = 0; i < maxStudents_; i++)
	{
		if (students_[i]->id_ > 0)
		{
			cout << students_[i]->id_ << "\t" << students_[i]->name_ << "\t";
			cout << students_[i]->courseNames_[0] << "\t" << students_[i]->courseNames_[1] << "\t";
			cout << students_[i]->courseNames_[2] << "\t" << students_[i]->grades_[0] << " ";
			cout << students_[i]->grades_[1] << " " << students_[i]->grades_[2] << endl;
		}
		else break;
	}
}
void StudentClass::showStudentCount() {
	cout << "学生人数是：" << studentCount_;
}