#include "Grades.h"

Grades::Grades(std::string subName, float score, std::string grade):_subName(subName), _score(score), _grade(grade){}

Grades::~Grades(){}

std::string Grades::getSubName()
{
	return _subName;
}

float Grades::getScore()
{
	return _score;
}

std::string Grades::getGrade()
{
	return _grade;
}

std::string Grades::convertScore(float score)
{
	if (score == 0)
	{
		return "0";
	}
	else if (1 <= score <= 79)
	{
		return "C+";
	}
	else if (80 <= score <= 84)
	{
		return "B";
	}
	else if (84 <= score <= 89)
	{
		return "B+";
	}
	else if (90 <= score <= 94)
	{
		return "A";
	}
	else if (95 <= score <= 100)
	{
		return "A+";
	}
}