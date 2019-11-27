#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>
#include <vector>
#include "YOK.h"
#include "university.h"

using namespace std;

template<class T>
class Complex
{
	public:
	T pp;
	Complex()
	{

	}
	T operator+(T cont)const
	{
		return pp+cont;
	}
	T operator++()const
	{
		return pp++;
	}
	T operator-(const Complex &other)const
	{
		return other.pp-pp;
	}
	T& operator=(T cont)
	{
		return pp=cont;
	}
};
#endif
