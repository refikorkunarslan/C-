#include <iostream>
#include "inher.h"
using namespace std;
/*functions*/
void Employee::drinkTea()
{
	cout<<name<<" "<<surname<<" have slackness. Therefore, "<<name<<" "<<surname<<" drinks tea. ";
	happiness=happiness+5;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";
}
void Employee::submitPetition()
{
	cout<<name<<" "<<surname<<" have solution. Therefore, "<<name<<" "<<surname<<" submit petition. ";
	happiness=happiness+1;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";

}
void AcademicPersonel::seeSuccessfulStudent()
{
	cout<<name<<" "<<surname<<" have seminar. Therefore, "<<name<<" "<<surname<<" see successful student. ";
	happiness=happiness+10;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";

}
void AcademicPersonel::makePublish()
{
	cout<<name<<" "<<surname<<" have academicPaper. Therefore, "<<name<<" "<<surname<<" make publish. ";
	happiness=happiness+2;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";

}
void AdministrativePersonnel::manageProcess()
{
	cout<<name<<" "<<surname<<" have administration. Therefore, "<<name<<" "<<surname<<" manage process. ";
	happiness=happiness-1;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";

}
void Lecturer::giveLesson()
{
	cout<<name<<" "<<surname<<" have lesson. Therefore, "<<name<<" "<<surname<<" give lesson. ";
	happiness=happiness+1;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";

}
void Lecturer::giveHW()
{
	cout<<name<<" "<<surname<<" have HomeworkTime. Therefore, "<<name<<" "<<surname<<" give HW. ";
	happiness=happiness-2;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";

}
void ResearchAssistant::research()
{
	cout<<name<<" "<<surname<<" have project. Therefore, "<<name<<" "<<surname<<" research. ";
	happiness=happiness+3;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";

}
void ResearchAssistant::readHW()
{
	cout<<name<<" "<<surname<<" have homeworkTimeout. Therefore, "<<name<<" "<<surname<<" read HW. ";
	happiness=happiness-3;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";

}
void Secretary::receivePetition()
{	
	cout<<name<<" "<<surname<<" have indicent. Therefore, "<<name<<" "<<surname<<" receive petition. ";
	happiness=happiness-1;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";

}
void Officer::makeDoc()
{
	cout<<name<<" "<<surname<<" have solution. Therefore, "<<name<<" "<<surname<<" submit petition. ";
	happiness=happiness-2;
	cout<<"Happiness of "<<name<<" "<<surname<<" is "<<happiness<<", ";

}