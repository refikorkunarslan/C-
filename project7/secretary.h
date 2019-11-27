#ifndef SECRETARY_H
#define SECRETARY_H
#include <iostream>
#include <string>
#include <vector>
#include "University.h"
//#include "complex.h"
#include "employee.h"
//#include "lecturer.h"
//#include "ra.h"
//#include "officer.h"
using namespace std;

class Secretary:public Employee
{
	public:
	int work(action act);
	void receivePetition();
	void manageProcess();
	void drinkTea();
	void submitPetition();
	
};

class ComSec:public Secretary
{
	

};
class LibSec:public Secretary
{

};
class BrokerSecretary:public Secretary
{

};
class WorkerSecretary:public Secretary
{

};

#endif
