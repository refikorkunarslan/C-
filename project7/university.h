#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <iostream>
#include <string>
#include <vector>
#include "complex.h"
#include "University.h"

using namespace std;
template <class T>
class university 
{
  private:
	
	string ss;	
	
  public:
	int contribute();
	void employ();
	void start();
	
	T cont;
	university()
	{   }
	//University(Employee *emlp):emp(empl);
	//{    }
	T getCont();
	//void setCont(T cc)
	
};
#endif
