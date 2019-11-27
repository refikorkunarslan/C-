#ifndef LIBEDU_H
#define LIBEDU_H
#include <iostream>
#include <string>

#include "University.h"
#include "employee.h"
using namespace std;
class LiberalEducation:public EducationSystem
{
public:
      University* foundUni(int uniType);
	Employee& giveJob(string name,string surname,int empType);

};
#endif
