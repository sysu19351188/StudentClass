#include<iostream>
#include"student.h"
using namespace std;

Student::Student() {
	id_ = 1234;
	name_ = "noname";
	courseNames_[0] = "Robotics";
	courseNames_[1] = "cd";
	courseNames_[2] = "ef";
	grades_[0] = 97;
	grades_[1] = 98;
	grades_[2] = 99;
}
Student::Student(int id, std::string name, std::string courseName[maxCourses_], double grades[maxCourses_]) {
	id_ = id;
	name_ = name;
	courseNames_[0] = courseName[0];
	courseNames_[1] = courseName[1];
	courseNames_[2] = courseName[2];
	grades_[0] = grades[0];
	grades_[1] = grades[1];
	grades_[2] = grades[2];
}
Student::Student(const Student& p) {
	id_ = p.id_;
	name_ = p.name_;
	courseNames_[0] = p.courseNames_[0];
	courseNames_[1] = p.courseNames_[1];
	courseNames_[2] = p.courseNames_[2];
	grades_[0] = p.grades_[0];
	grades_[1] = p.grades_[1];
	grades_[2] = p.grades_[2];
}
void Student::setid() {
	int id;
	cout << "请设置id:";
	cin >> id;
	id_ = id;
}
void Student::setname() {
	std::string name;
	cout << "请输入名字：";
	cin >> name;
	name_ = name;
}
bool Student::AddCourse(const std::string& courseName, double grade) {
	if (courseNames_[2] != "\0")                              //如果第三个课程有名字，返回0，不可添加
		return 0;
	if (courseNames_[0] == "\0")                           //如果第一个课程无名字，返回1，添加课程名字和分数
	{
		courseNames_[0] = courseName;
		grades_[0] = grade;
		return 1;
	}
	else
	{
		if (courseNames_[1] == "\0")             //如果第二个课程无名字，第一个课程有名字，返回1，添加课程名字和分数
		{
			courseNames_[1] = courseName;
			grades_[1] = grade;
			return 1;
		}
		else {                                  //第一，二个课程都有了，返回1，添加课程名字和分数到第三个课程
			courseNames_[2] = courseName;
			grades_[2] = grade;
			return 1;
		}
	}
}
void Student::SetGrade(const std::string& courseName, double grade) {
	int i = 0;
	for (; i < 3; i++)
	{
		if (courseNames_[i] == courseName)
			grades_[i] = grade;
	}
}
double Student::GetGrade(const std::string& courseName) const {
	int i = 0;
	for (; i < 3; i++)
	{
		if (courseNames_[i] == courseName)
		{
			return grades_[i];
			break;
		}
	}
}
double Student::GetAverageGrade() const {
	double sum = 0.0, average;
	int i;
	for (i = 0; i < 3; i++)
	{
		sum = sum + grades_[i];
	}
	average = sum / 3;
	return average;
}
void Student::ShowGrades() const {
	int i = 0;
	cout << "成绩分别是：";
	for (; i < 3; i++)
	{
		cout << grades_[i] << "\t";
	}
}