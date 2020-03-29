#ifndef STUDENT_CLASS _H_INCLUDED
#define STUDENT_CLASS_H_INCLUDED

class StudentClass {
private:
	static const int maxStudents_ = 20;
	static int studentCount_;
	std::string code_;
	Student* students_[maxStudents_];
public:
	StudentClass();
	StudentClass(std::string code, Student students[maxStudents_]);
	StudentClass(const StudentClass& p);
	~StudentClass() {};
	void set(std::string code, Student students[maxStudents_]);
	void show() const;
	bool AddStudent(const Student student);
	void ShowStudent(int id) const;
	void ShowStudentsByIdOrder(bool (*compare)(int, int));
	void showStudentCount();
};

#endif