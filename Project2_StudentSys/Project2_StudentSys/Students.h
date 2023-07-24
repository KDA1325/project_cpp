#ifndef STUDENTS_H
#define STUDENTS_H
#include <iostream>
#include <string>
#include <vector>

class Students
{
private:
	std::string _name;
	float _studentNum;
	std::string _department;
	std::vector<Students*> students;

public:
	Students(std::string name, float studentNum, std::string department);
	~Students();
	std::string getName();
	float getStudentNum();
	std::string getDepartment();
	void addStudent(Students* student);
	void deleteStudent(Students* student);
	//void editStudents();
};
#endif // !STUDENTS_H