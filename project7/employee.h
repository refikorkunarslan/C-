#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <vector>
#include "University.h"
#include "comlex.h"

using namespace std;
enum action{document=0,slackness,project,lesson,seminar,academicPaper,administration,homeworkTime,homeworkTimeout,incident,solution};
template <class T>
class university;
class Employee
{
	private:
	int pid;
	string name;
	string surname;
	
	int happiness;
	Employee *link;
	
	
	public:
	string typ;	
	int ww;
	action act;
	Employee* getLink() const { return link; }
	void employ(university<int >* uni)
	{
		emp=uni;
	}
	void employ(university<double >* uni)
	{
		em=uni;
	}
	void employ(university<Complex<int>>*uni)
	{
		e=uni;
	}
	university<int> *emp;
	university<double> *em;
	university<Complex<int>> *e;
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

