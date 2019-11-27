#ifndef RA_H
#define RA_H
#include <iostream>
#include <string>
#include <vector>
#include "YOK.h"
#include "university.h"
#include "complex.h"
#include "employee.h"
#include "lecturer.h"
#include "secretary.h"
#include "officer.h"
using namespace std;

class ResearchAssistant:public Employee
{
	public:
	int work(action act);
	void research();
	void readHW();
	void seeSuccessfulStudent();
	void makePublish();
	void drinkTea();
	void submitPetition();

};
#endif
