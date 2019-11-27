#ifndef ATTEN_H
#define ATTEN_H
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
namespace hw4
{
	
	class Attendance
	{
		private:
		string *name;
		int *student_id;		
		public:
		int **arrr[11];		
		string *getName(){return name;};
		int* getStudent_id(){return student_id;};
		int*** getArrr(){return arrr;};	
		//int *count;
		
		
		Attendance()/*default*/
		{
			for (int i = 0; i < 11; i++) {
 			 arrr[i] = new int *[19]();
  				for (int j = 0; j < 19; j++)
    				arrr[i][j] = new int [1]();
			}
			name=new string[12]{};
			student_id=new int[12]{};
		}
		~Attendance()/*destructor*/
		{
			 
			for (int i = 0; i < 11; i++)
			{
				for (int j = 0; j < 19; j++)
					delete[] arrr[i][j];

				delete[] arrr[i];
			}

			delete[] *arrr;
			delete [] name;
			delete [] student_id;
		}
		Attendance(int a,string b)
		{
			
			name=new string[12]{};
			student_id=new int[12]{};
			for(int i=0;i<12;i++)
			{
				name[i]=b;
				student_id[i]=a;
			}
			
			
		}
		Attendance(const Attendance& other)/*copy coınstructor*/
		{
			for (int i = 0; i < 11; i++) {
 			 arrr[i] = new int *[19]();
  				for (int j = 0; j < 19; j++)
    				arrr[i][j] = new int [1]();
			}
			name=new string[12]{};
			student_id=new int[12]{};
			for(int i=0; i<11 ;i++)
			{
			    for(int j=0;j<19;j++)
				{
				     for(int z=0;z<1;z++)
					{
					   arrr[i][j][z]=other.arrr[i][j][z];					
					}				
				}
			}
			memcpy(name,other.name,12*sizeof(char));
			memcpy(student_id,other.student_id,12*sizeof(int));
			
		}
		Attendance &operator =(const Attendance& other)/*operator*/
		{
			for (int i = 0; i < 11; i++) {
 			 arrr[i] = new int *[19]();
  				for (int j = 0; j < 19; j++)
    				arrr[i][j] = new int [1]();
			}
			
			 name=new string[12]{};
			student_id=new int[12]{};
			for(int i=0; i<11 ;i++)
			{
			    for(int j=0;j<19;j++)
				{
				     for(int z=0;z<1;z++)
					{
					   arrr[i][j][z]=other.arrr[i][j][z];					
					}				
				}
			}
			memcpy(name,other.name,12*sizeof(char));
			memcpy(student_id,other.student_id,12*sizeof(int));
			
			return *this;
			
		}
		
	
					
	


	};
		






}
#endif 	
