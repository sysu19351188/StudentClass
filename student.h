#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include<iostream>
using namespace std;

class Student {
	friend class StudentClass;
private:
	static const int maxCourses_ = 3;
	int id_;
	std::string name_;
	std::string courseNames_[maxCourses_];
	double grades_[maxCourses_];
public:
	Student();
	Student(int id, std::string name, std::string courseName[maxCourses_], double grades[maxCourses_]);
	Student(const Student& p);
	void setid();
	void setname();
	void showid() { cout << "id:" << id_; }
	void showname() { cout << "name:" << name_; }
	bool AddCourse(const std::string& courseName, double grade);                     //�����Ƿ�ɹ�
	void SetGrade(const std::string& courseName, double grade);                      //�β����γ������������������������
	double GetGrade(const std::string& courseName) const;                             //�β�Ϊ�γ���
	double GetAverageGrade() const;
	void ShowGrades() const;
};

#endif
