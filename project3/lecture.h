#ifndef LECTURE_H
#define LECTURE_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Course{
	int id;
	string name;
	int code;
	int credit;
	int total_hours;
	int tt;
	string lecture_dates;
	int field;
	string isMandatory;
	int flagg;
	
};
struct Classroom{
	int id;
	string c_no;
	int capacity;
	int arr[5][24];
};


class lecturer
{
public:
	bool proposeCourse();
	bool assignCourse(Course &cour);
	bool assignCourse(vector<Course> &cour,int course_count);
	void setInput(int id,string name1, string surname1,string tittle1,string profession1,int as);
	
	int get_Personal(){return personal_id;}
	string get_Field(){return professions;}
	string get_Courses(){return courses;}
	void set_count(){count1=3;}
	void set_Courses(){courses.clear();}
	bool proposeCourse(vector<Course> &cour,string ww);
	string professions;
	bool assignCourse(vector<Course> &cour,vector<lecturer> &lec,int lecturer_count,int course_count);
	string courses;
private:
	
	string name;
	string surname;
	string title;
	int personal_id;
	int count1;
	
	
};
class Administrator
{
public:
	 bool arrangeClasroom(Classroom &Cr,int count);
	void arrangeTimeTable(Course &cour);
	void arrangeTimeTable(Course &cour,int course_count);
	string getTable(){return table;}
	
	
	
private:
	string table;
	
	int pid;
	string password;
	
};



#endif 
