#ifndef SECRETARY_H
#define SECRETARY_H
#include <iostream>
#include <string>
#include <vector>
#include "YOK.h"
#include "university.h"
#include "complex.h"
#include "employee.h"
#include "lecturer.h"
#include "ra.h"
#include "officer.h"
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
#endif
