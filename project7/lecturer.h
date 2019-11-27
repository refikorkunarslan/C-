#ifndef LECTURER_H
#define LECTURER_H
#include <iostream>
#include <string>
#include <vector>
#include "University.h"
//#include "complex.h"
#include "employee.h"
//#include "ra.h"
//#include "secretary.h"
//#include "officer.h"
using namespace std;

class Lecturer:public Employee
{
	public:
	int work(action act);
	void giveLesson();
	void giveHW();
	void seeSuccessfulStudent();
	void makePublish();
	void drinkTea();
	void submitPetition();
	
};

class ComLec:public Lecturer
{

	
};
class LibLec:public Lecturer
{
	
	
};
class BrokerLec:public Lecturer
{
	
	
};
class WorkerLec:public Lecturer
{
	
	
};

#endif
