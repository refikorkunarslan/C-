#include <iostream>
#include <string>
using namespace std;
enum action{document=0,slackness,project,lesson,seminar,academicPaper,administration,homeworkTime,homeworkTimeout,incident,solution};
class University
{
	public:
	University()
	{
		asd="";
		namee="";
		surnamee="";
		contribution=0;
		
	}
	
	string asd;
	string namee;
	string surnamee;
	int ww;
	int contribution;
	
	
};
class Employee
{
	public:	
	Employee()
	{
		pid=-1;
		name="";
		surname="";
		happiness=0;
		emp=new University[25];
	}
	int getPid(){return pid;}
	void setPid(int a){pid=a;}
	string getName(){return name;}
	void setName(string a){name=a;}
	string getSurname(){return surname;}
	void setSurname(string a){surname=a;}
	int getHappiness(){return happiness;}
	void setHappinees(int a){happiness=a;}
	University* getEmp(){return emp;} 
	void drinkTea();
	void submitPetition();
	void employ(University* uni)
	{
		emp=uni;
	}	

	protected:
	int pid;
	string name;
	string surname;
	int happiness;
	University *emp;
	
	
	
};
class AcademicPersonel:public Employee
{
	public:
	 void seeSuccessfulStudent();
	 void makePublish();
	
	
};
class AdministrativePersonnel:public Employee
{
	public:
	 void manageProcess();

};
class Lecturer:public AcademicPersonel
{
	public:
	
	void giveLesson();
	void giveHW();
	
};
class ResearchAssistant:public AcademicPersonel
{
	public:
	
	void research();
	void readHW();

};
class Secretary:public AdministrativePersonnel
{
	public:
	
	void receivePetition();
	
};
class Officer:public AdministrativePersonnel
{
	public:
	
	void makeDoc();
	
};


