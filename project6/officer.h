#ifndef OFFICER_H
#define OFFICER_H
#include <iostream>
#include <string>
#include <vector>
#include "YOK.h"
#include "university.h"
#include "complex.h"
#include "employee.h"
#include "lecturer.h"
#include "ra.h"
#include "secretary.h"
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
#endif
