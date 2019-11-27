#ifndef LECTURE_H
#define LECTURE_H
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;
namespace hw3
{
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
	class Classroom{
		public:
		Classroom () /*default*/
		{
			id=0;	
			c_no="";
			capacity=0;
			student_inroom=0;
			
		}
		Classroom(const Classroom& other)/*copy constructor*/
		{	
				id=other.id;
				c_no=other.c_no;
				capacity=other.capacity;
				student_inroom=other.student_inroom;
			
		}
		Classroom &operator =(const Classroom& other)/*operator*/
		{
			
				id=other.id;
				c_no=other.c_no;
				capacity=other.capacity;
				student_inroom=other.student_inroom;
			
			return *this;
			
		}
		~Classroom()/*destructor*/
		{
						
		}
			
		int id;
		string c_no;
		int capacity;
		int arr[5][24];
		void enterClassroom(int (*arar)[6][11],int x,int y);
		void quitClassroom(int (*arar)[6][11],int x,int y);
		int ww[18];
		int student_inroom;

	};


	class lecturer
	{
	public:
		lecturer()/*default*/
		{
			
			personal_id=0;	
			name="";
			surname="";			
			title="";
			professions="";			
		}
		lecturer(const lecturer& other)/*copy consturoctor*/
		{	
			personal_id=other.personal_id;	
			name=other.name;
			surname=other.surname;			
			title=other.title;
			professions=other.professions;	
		}
		lecturer &operator =(const lecturer& other)/*operator*/
		{
			
			personal_id=other.personal_id;	
			name=other.name;
			surname=other.surname;			
			title=other.title;
			professions=other.professions;		
			return *this;
			
		}
		~lecturer()/*destructor*/
		{
						
		}
		







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
		void assignCourse(vector<Course> &cour,lecturer lec[],int lecturer_count,int course_count);
		string courses;
	private:
		//lecturer *lec;
		string name;
		string surname;
		string title;
		int personal_id;
		int count1;
	
	
	};
	class Administrator
	{
	public:
		Administrator()/*default*/
		{
			
			pid=0;	
			table="";
			password="";			
		}
		Administrator(const Administrator& other)/*copy constructor*/
		{	
			pid=other.pid;	
			table=other.table;
			password=other.password;			
		}
		Administrator &operator =(const Administrator& other)/*operator*/
		{
			
			pid=other.pid;	
			table=other.table;
			password=other.password;			
			return *this;
			
		}
		~Administrator()/*destructor*/
		{
						
		}
		 bool arrangeClasroom(Classroom &Cr,int count,Course &cour);
		void arrangeTimeTable(Course &cour);
		void arrangeTimeTable(Course &cour,int course_count);
		string getTable(){return table;}
		
	
	
	private:
		string table;
		
		int pid;
		string password;
	
	};
}



#endif 
