#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

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
	bool AddCourse(const std::string& courseName, double grade);                     //返回是否成功
	void SetGrade(const std::string& courseName, double grade);                      //形参数课程名，分数，仿照上面的声明
	double GetGrade(const std::string& courseName) const;                             //形参为课程名
	double GetAverageGrade() const;
	void ShowGrades() const;
};

#endif
