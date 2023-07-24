#ifndef GRADES_H
#define GREADES_H
#include <iostream>
#include <string>

class Grades
{
private:
	std::string _subName;
	float _score;
	std::string _grade;
public:
	Grades(std::string subName, float score, std::string grade);
	~Grades();
	std::string getSubName();
	float getScore();
	std::string getGrade();

	std::string convertScore(float score);
};
#endif // !GRADES_H