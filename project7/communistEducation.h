#ifndef COMEDU_H
#define COMEDU_H
#include <iostream>
#include <string>

#include "university.h"
#include "employee.h"
using namespace std;
class communistEducation:public EducationSystem
{
public:
	University* foundUni(int uniType);
	Employee& giveJob(string name,string surname,int empType);

};
#endif
