#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <vector>
#include "YOK.h"
#include "university.h"
#include "complex.h"

using namespace std;
enum action{document=0,slackness,project,lesson,seminar,academicPaper,administration,homeworkTime,homeworkTimeout,incident,solution};
class Employee
{
	private:
	int pid;
	string name;
	string surname;
	int happiness;
	
	
	public:
	int ww;
	action act;
	void employ(University<int >* uni)
	{
		emp=uni;
	}
	void employ(University<double >* uni)
	{
		em=uni;
	}
	void employ(University<Complex<int>>*uni)
	{
		e=uni;
	}
	University<int> *emp;
	University<double> *em;
	University<Complex<int>> *e;
	int getPid(){return pid;}
	string getName(){return name;}
	string getSurname(){return surname;}
	int getHapiness(){return happiness;}
	void setPid(int pid){this->pid=pid;}
	void setName(string name){this->name=name;}
	void setSurname(string surname){this->surname=surname;}
	void setHappiness(int happiness){this->happiness=happiness;}	
	virtual int work(action act)=0;

};
#endif

