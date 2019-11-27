#ifndef EDUSYS_H
#define EDUSYS_H
#include <iostream>
#include <string>
#include "university.h"
using namespace std;

class University;

class Employee;
class EducationSystem
{
public:
	University *uni;
	University *un;
	University *u;
	virtual University* foundUni(int uniType)=0;
	virtual Employee& giveJob(string name,string surname,int empType)=0;
};
#endif
