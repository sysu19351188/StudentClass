#include<iostream>
#include"student.h"
#include"student_class.h"
#include"student.cpp"
#include"student_class.cpp"
using namespace std;

int main()
{
	std::string a[3] = { "Robotics", " C++", " Math" };
	double b[3] = { 60.5, 61.5, 62.5 }, c[3] = { 70,80,90 };
	Student Bob, John(1234, "John", a, b), Alice(1345, "Alice", a, c);
	Bob.setid();
	Bob.setname();
	Bob.showid();
	cout << "\t";
	Bob.showname();
	cout << endl;
	Bob.AddCourse("English", 87);
	Bob.SetGrade("history", 88);
	Bob.ShowGrades();
	cout << "����˵�Robotic�ɼ��ǣ�" << Bob.GetGrade("Robotics") << "\t";
	cout << "����˵�ƽ�����ǣ�" << Bob.GetAverageGrade() << endl << endl;
	John.showid();
	cout << "\t";
	John.showname();
	cout << endl;
	John.ShowGrades();
	cout << "\t" << "ƽ���֣�" << John.GetAverageGrade() << endl << endl;
	Alice.showid();
	cout << "\t";
	Alice.showname();
	cout << endl;
	Alice.ShowGrades();
	cout << "\t" << "ƽ���֣�" << Alice.GetAverageGrade();

	int order1, order2;
	Student str[3] = { Bob,John,Alice };
	StudentClass  e("ie201801", str);
	cout << endl << endl;
	e.show();
	e.set("ios101701", str);
	cout << endl << endl << "��������֮��";
	e.show();
	e.AddStudent(Bob);
	cout << endl << "Ҫ���ҵ�ѧ����";
	e.ShowStudent(1234);
	cout << endl;
	e.showStudentCount();
	cout << endl << endl << "�������������֣�1�����򣩣�2�����򣩣�";  //��һ������������
	cin >> order1;
	if (order1 == 1)
	{
		int i;
		cout << "���������ǣ�";
		e.ShowStudentsByIdOrder(ascending);
	}
	if (order1 == 2)
	{
		int i;
		cout << "���������ǣ�";
		e.ShowStudentsByIdOrder(descending);
	}
	cout << endl << endl << "�������������֣�1�����򣩣�2�����򣩣�"; //�ڶ��������罵��
	cin >> order2;
	if (order2 == 1)
	{
		int i;
		cout << "���������ǣ�";
		e.ShowStudentsByIdOrder(ascending);
	}
	if (order2 == 2)
	{
		int i;
		cout << "���������ǣ�";
		e.ShowStudentsByIdOrder(descending);
	}
	return 0;
}