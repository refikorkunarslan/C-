#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
namespace hw2
{
	struct Course{	/*Course Struct*/
		int id;
		string namee;
		int code;
		int credit;
		int total_hours;
		string lecture_dates;
		int field;
	};
	struct Classroom{ /*Clasrrom Struct*/		
				
		int idd;
		string c_no;
		int capacity;
		int student_inroom;
	};
	class Student{		/*Class Student*/
	public:
		int enrollCourse(Course &Cour);
		int disenroll(Course &Cour);
		bool control(Course &cour,int flag1);
		string extractSchedule();
		void enterClassroom(Classroom &Cr);
		void quitClassroom(Classroom &Cr);
		string name;
		string surname;
		int student_no;
		int level;
		int tt;
		string str;
		int arr[5][24];
		int array[9];
	};
}
#endif 
