#ifndef OFFICER_H
#define OFFICER_H
#include <iostream>
#include <string>
#include <vector>
#include "University.h"
//#include "complex.h"
#include "employee.h"
//#include "lecturer.h"
//#include "ra.h"
//#include "secretary.h"
using namespace std;

class Officer:public Employee
{
	public:
	int work(action act);	
	void makeDoc();
	void manageProcess();
	void drinkTea();
	void submitPetition();
	
};

class ComOff:public Officer
{
	
};
class LibOff:public Officer
{

};
class BrokerOfficer:public Officer
{

};
class WorkerOfficer:public Officer
{

};

#endif
