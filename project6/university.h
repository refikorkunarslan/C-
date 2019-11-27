#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <iostream>
#include <string>
#include <vector>
#include "YOK.h"
#include "complex.h"

using namespace std;
template <class T>
class University
{
  private:
	//Employee *emp;
	string ss;	
	
  public:
	T cont;
	University()
	{   }
	//University(Employee *emlp):emp(empl);
	//{    }
	T getCont();
	//void setCont(T cc)
	T contribute(int a)
	{
		//cout<<"a : "<<a<<endl;
		cont=cont+a;
		return cont;
	}
};
#endif
