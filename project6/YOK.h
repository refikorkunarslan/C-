#ifndef YOK_H
#define YOK_H
#include <iostream>
#include <string>
#include <vector>
#include "university.h"
#include "complex.h"
#include "employee.h"
#include "lecturer.h"
#include "ra.h"
#include "secretary.h"
#include "officer.h"
using namespace std;

class YOK
{
	
	public:
	Employee *lecc;
	Employee *raa;
	Employee *secc;
	Employee *offf;
	
	
	University <int >* foundUni(int Unitype);
	University <double >* foundUni(double Unitype);
	Employee& givejob(string name,string surname,int emptype);
};


#endif

