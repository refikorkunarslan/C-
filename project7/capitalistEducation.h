#ifndef CAPEDU_H
#define CAPEDU_H
#include <iostream>
#include "capitalistEducation.h"
#include <string>

using namespace std;

class CapitalistEducation:public EducationSystem
{
 public:
	
	University* foundUni(int uniType);
	Employee& giveJob(string name,string surname,int empType);
};
#endif
