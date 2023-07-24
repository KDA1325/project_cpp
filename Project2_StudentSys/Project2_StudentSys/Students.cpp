#include "Students.h"

Students::Students(std::string name, float studentNum, std::string department):_name(name), _studentNum(studentNum), _department(depar
){}

Students::~Students(){}

std::string Students::getName()
{
	return _name;
}

float Students::getStudentNum()
{
	return _studentNum;
}

std::string Students::getDepartment()
{
	return _department;
}

// 학생 추가
void Students::addStudent(Students* student)
{
	students.push_back(student);
}

void Students::deleteStudent(Students* stubents)
{

}

//void Students::editStudents()
//{
//
//}