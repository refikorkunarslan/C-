#include <iostream>
#include <string>
#include <complex>
#include "YOK.h"
#include "university.h"
#include "complex.h"
#include "employee.h"
#include "lecturer.h"
#include "ra.h"
#include "secretary.h"
#include "officer.h"
using namespace std;
int Lecturer::work(action act)/*work function for lecturer*/
{
	if(act==slackness)
	{
		drinkTea();
		return -2;
	}
	else if(act==lesson)
	{
		giveLesson();
		return 5;
	}
	else if(act==seminar)
	{
		seeSuccessfulStudent();
		return 0;
	}
	else if(act==academicPaper)
	{
		makePublish();
		return 5;
	}
	else if(act==homeworkTime)
	{
		giveHW();
		return 1;
	}
	else if(act==solution)
	{
		submitPetition();
		return -2;
	}
	
}
void Lecturer::giveLesson()
{
	cout<<getName()<<" "<<getSurname()<<" have lesson. Therefore, "<<getName()<<" "<<getSurname()<<" give lesson. ";
	setHappiness(getHapiness()+1);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
void Lecturer::giveHW()
{
	cout<<getName()<<" "<<getSurname()<<" have HomeworkTime. Therefore, "<<getName()<<" "<<getSurname()<<" give HW. ";
	setHappiness(getHapiness()-2);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
void Lecturer::seeSuccessfulStudent()
{
	cout<<getName()<<" "<<getSurname()<<" have seminar. Therefore, "<<getName()<<" "<<getSurname()<<" see successful student. ";
	setHappiness(getHapiness()+10);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
void Lecturer::makePublish()
{
	cout<<getName()<<" "<<getSurname()<<" have academicPaper. Therefore, "<<getName()<<" "<<getSurname()<<" make publish. ";
	setHappiness(getHapiness()+2);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
void Lecturer::drinkTea()
{
	cout<<getName()<<" "<<getSurname()<<" have slackness. Therefore, "<<getName()<<" "<<getSurname()<<" drinks tea. ";
	setHappiness(getHapiness()+5);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";
}
void Lecturer::submitPetition()
{
	cout<<getName()<<" "<<getSurname()<<" have solution. Therefore, "<<getName()<<" "<<getSurname()<<" submit petition. ";
	setHappiness(getHapiness()+1);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";
}

/*----------------------------------------------------------------------------------*/
int ResearchAssistant::work(action act)/*work fuctiob for ResearchAssistant*/
{
	if(act==slackness)
	{
		drinkTea();
		return -2;
	}
	else if(act==project)
	{
		research();
		return 4;
	}
	else if(act==seminar)
	{
		seeSuccessfulStudent();
		return 0;
	}
	else if(act==academicPaper)
	{
		makePublish();
		return 5;

	}
	else if(act==homeworkTimeout)
	{
		readHW();
		return 2;
	}
	else if(act==solution)
	{
		submitPetition();
		return -2;
	}
	
}



void ResearchAssistant::drinkTea()
{
	cout<<getName()<<" "<<getSurname()<<" have slackness. Therefore, "<<getName()<<" "<<getSurname()<<" drinks tea. ";
	setHappiness(getHapiness()+5);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";
}
void ResearchAssistant::submitPetition()
{
	cout<<getName()<<" "<<getSurname()<<" have solution. Therefore, "<<getName()<<" "<<getSurname()<<" submit petition. ";
	setHappiness(getHapiness()+1);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
void ResearchAssistant::seeSuccessfulStudent()
{
	cout<<getName()<<" "<<getSurname()<<" have seminar. Therefore, "<<getName()<<" "<<getSurname()<<" see successful student. ";
	setHappiness(getHapiness()+10);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
void ResearchAssistant::makePublish()
{
	cout<<getName()<<" "<<getSurname()<<" have academicPaper. Therefore, "<<getName()<<" "<<getSurname()<<" make publish. ";
	setHappiness(getHapiness()+2);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
void ResearchAssistant::research()
{
	cout<<getName()<<" "<<getSurname()<<" have project. Therefore, "<<getName()<<" "<<getSurname()<<" research. ";
	setHappiness(getHapiness()+3);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
void ResearchAssistant::readHW()
{
	cout<<getName()<<" "<<getSurname()<<" have homeworkTimeout. Therefore, "<<getName()<<" "<<getSurname()<<" read HW. ";
	setHappiness(getHapiness()-3);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
//*************************************************************
int Secretary::work(action act)/*work fuctiob for Secretary*/
{
	if(act==slackness)
	{
		drinkTea();
		return -2;
	}
	else if(act==administration)
	{
		manageProcess();
		return 5;
	}
	else if(act==incident)
	{
		receivePetition();
		return -1;
	}
	else if(act==solution)
	{
		submitPetition();
		return -2;
	}
	
}
void Secretary::receivePetition()
{	
	cout<<getName()<<" "<<getSurname()<<" have indicent. Therefore, "<<getName()<<" "<<getSurname()<<" receive petition. ";
	setHappiness(getHapiness()-1);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";
}
void Secretary::drinkTea()
{
	cout<<getName()<<" "<<getSurname()<<" have slackness. Therefore, "<<getName()<<" "<<getSurname()<<" drinks tea. ";
	setHappiness(getHapiness()+5);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";
}
void Secretary::submitPetition()
{
	cout<<getName()<<" "<<getSurname()<<" have solution. Therefore, "<<getName()<<" "<<getSurname()<<" submit petition. ";
	setHappiness(getHapiness()+1);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
void Secretary::manageProcess()
{
	cout<<getName()<<" "<<getSurname()<<" have administration. Therefore, "<<getName()<<" "<<getSurname()<<" manage process. ";
	setHappiness(getHapiness()-1);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";
}
//**************************************************
int Officer::work(action act)/*work fuctiob for Officer*/
{
	if(act==document)
	{
		makeDoc();
		return 3;
	}
	else if(act==slackness)
	{
		drinkTea();
		return -2;
	}
	else if(act==administration)
	{
		manageProcess();
		return +2;
	}
	
	else if(act==solution)
	{
		submitPetition();
		return -2;
	}
	
}
void Officer::drinkTea()
{
	cout<<getName()<<" "<<getSurname()<<" have slackness. Therefore, "<<getName()<<" "<<getSurname()<<" drinks tea. ";
	setHappiness(getHapiness()+5);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";
}
void Officer::submitPetition()
{
	cout<<getName()<<" "<<getSurname()<<" have solution. Therefore, "<<getName()<<" "<<getSurname()<<" submit petition. ";
	setHappiness(getHapiness()+1);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";

}
void Officer::makeDoc()
{
	cout<<getName()<<" "<<getSurname()<<" have solution. Therefore, "<<getName()<<" "<<getSurname()<<" submit petition. ";
	setHappiness(getHapiness()-2);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";
}
void Officer::manageProcess()
{
	cout<<getName()<<" "<<getSurname()<<" have administration. Therefore, "<<getName()<<" "<<getSurname()<<" manage process. ";
	setHappiness(getHapiness()-1);
	cout<<"Happiness of "<<getName()<<" "<<getSurname()<<" is "<<getHapiness()<<", ";
}
//*********************************************************************
University <int >* YOK::foundUni(int Unitype)
{
	University<int > *gtu;
	return gtu;
}
University <double >* YOK::foundUni(double Unitype)
{
	University<double > *odtu;
	return odtu;
}

Employee& YOK::givejob(string name,string surname,int emptype)
{
	if(emptype==0)
	{
		Employee *aa=new Lecturer;
		aa->setName(name);
		aa->setSurname(surname);
		return *aa;
		
	}
	else if(emptype==1)
	{
		Employee *aa=new ResearchAssistant;
		aa->setName(name);
		aa->setSurname(surname);
	return *aa;

	}
	else if(emptype==2)
	{
		Employee *aa=new Secretary;
		aa->setName(name);
		aa->setSurname(surname);
	return *aa;

	}
	else if(emptype==3)
	{
		Employee *aa=new Secretary;
		aa->setName(name);
		aa->setSurname(surname);
	return *aa;


	}

	
}
