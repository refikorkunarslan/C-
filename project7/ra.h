#ifndef RA_H
#define RA_H
#include <iostream>
#include <string>
#include <vector>
#include "University.h"
//#include "complex.h"
#include "employee.h"
//#include "lecturer.h"
//#include "secretary.h"
//#include "officer.h"
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

class ComReAssist:public ResearchAssistant
{
	

};
class LibReAssist:public ResearchAssistant
{
	

};
class BrokerReAssist:public ResearchAssistant
{
	

};
class WorkerReAssist:public ResearchAssistant
{
	

};

#endif
