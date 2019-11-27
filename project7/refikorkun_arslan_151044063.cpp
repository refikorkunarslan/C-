
#include <iostream>
#include <string>
#include <fstream>
#include "educationSystem.h"
#include "liberalEducation.h"
#include "communistEducation.h"
#include "comUni.h"
#include "University.h"
#include "libUni.h"
#include "employee.h"
#include "lecturer.h"
#include "ra.h"
#include "secretary.h"
#include "officer.h"
#include "comlex.h"
using namespace std;
int ComUni::contribute(int a)
{
	cont=cont+a;
	return cont;
}
void ComUni::start()
{
	int lec_size=2;
	int lec_iter=0;
	int ra_size=2;
	int ra_iter=0;	/*increased as you add elements*/
	int sec_size=2;
	int sec_iter=0;
	int off_size=2;
	int off_iter=0;
	ComLec *lec=new ComLec[1];
	ComLec *temp=new ComLec[1];
	ComReAssist *ra=new ComReAssist[1];
	ComReAssist *temp1=new ComReAssist[1];
	ComSec *sec=new ComSec[1];
	ComSec *temp2=new ComSec[1];
	ComOff *off=new ComOff[1];
	ComOff *temp3=new ComOff[1];
	ifstream file("personnellist.txt");

   action arr1[12];
	
	arr1[0]=document;
	arr1[1]=slackness;
	arr1[2]=project;
	arr1[3]=lesson;
	arr1[4]=seminar;
	arr1[5]=academicPaper;	
	arr1[6]=administration;	/*determination of actors*/
	arr1[7]=homeworkTime;
	arr1[8]=homeworkTimeout;
	arr1[9]=incident;
	arr1[10]=solution;
	arr1[11]=solution;
	int random;
	int q=0;
	int a,b;
	string c,d,ppp;
	while(!file.eof())	/*employ personells*/
	{
		random=rand()%4;
		if(random==0)
		{
			lec[lec_iter].ww=0;
			lec[lec_iter].setHappiness(0);
			file>>c;
			lec[lec_iter].setName(c);
			file>>d;
			lec[lec_iter].setSurname(d);
			file>>ppp;
		   temp=new ComLec[lec_size];
			q=0;
			while(q<lec_size-1)
			{
				temp[q]=lec[q];
				q++;
			}
			lec=temp;
			lec_iter=lec_iter+1;
			lec_size=lec_size+1;
		}
		else if(random==1)
		{
			ra[ra_iter].ww=0;
			ra[ra_iter].setHappiness(0);
			file>>c;
			ra[ra_iter].setName(c);
			file>>d;
			ra[ra_iter].setSurname(d);
			file>>ppp;
		   temp1=new ComReAssist[ra_size];
			q=0;
			while(q<ra_size-1)
			{
				temp1[q]=ra[q];
				q++;
			}
			ra=temp1;
			ra_iter=ra_iter+1;
			ra_size=ra_size+1;
		}
		else if(random==2)
		{
			sec[sec_iter].ww=0;
			sec[sec_iter].setHappiness(0);
			file>>c;
			sec[sec_iter].setName(c);
			file>>d;
			sec[sec_iter].setSurname(d);
			file>>ppp;
		   temp2=new ComSec[sec_size];
			q=0;
			while(q<sec_size-1)
			{
				temp2[q]=sec[q];
				q++;
			}
			sec=temp2;
			sec_iter=sec_iter+1;
			sec_size=sec_size+1;
		}
		else if(random==3)
		{
			off[off_iter].ww=0;
			off[off_iter].setHappiness(0);
			file>>c;
			off[off_iter].setName(c);
			file>>d;
			off[off_iter].setSurname(d);
			file>>ppp;
		   temp3=new ComOff[off_size];
			q=0;
			while(q<off_size-1)
			{
				temp3[q]=off[q];
				q++;
			}
			off=temp3;
			off_iter=off_iter+1;
			off_size=off_size+1;
		}
		

		
	}
	int ss[11];
	int sum=0,sum1=0,sum2=0,sum3=0;
	int i=0;
	while(i<12)/*compare contribution*/
	{	

		random=rand()%11;/*Select bes personell for action*/
		ss[i]=random;
		if(random==0 )
		{
			sum3=sum3+3;
		}
		else if(random==1)
		{
			sum=sum-2;
			sum1=sum1-2;
			sum2=sum2-2;
			sum3=sum3-2;
		}
		else if(random==2)
		{
			sum1=sum1+4;
		}
		else if(random==3)
		{
			sum=sum+5;
		}
		else if(random==4)
		{
			sum=sum+0;
			sum1=sum1+0;
		}
		else if(random==5)
		{
			sum=sum+5;
			sum1=sum1+5;
		}
		else if(random==6)
		{
			sum2=sum2+2;
			sum3=sum3+2;
		}
		else if(random==7)
		{
			sum=sum+1;
		}
		else if(random==8)
		{
			sum1=sum1+2;
		}
		else if(random==9)
		{
			sum2=sum-1;
		}
		else if(random==10)
		{
			sum=sum-2;
			sum1=sum1-2;
			sum2=sum2-2;
			sum3=sum3-2;
		}
		i++;
	}
	int max=0;
	double money=sum1+sum2+sum3+sum;
	int flag=0,flag1=0,flag2=0,flag3=0;
	if(sum>max)/*select max contribution*/
	{
		flag=1;
		max=sum;
	}
	if(sum1>max)
	{
		flag1=1;
		max=sum1;
		flag=0;
	}
	if(sum2>max)
	{
		flag2=1;
		max=sum2;
		flag=0;
		flag1=0;
	}
	if(sum3>max)
	{
		flag3=1;
		max=sum3;
		flag=0;
		flag1=0;
		flag2=0;
	}

	if(flag==0)/*tell story*/
	{
		i=0;
		while(i<12)
		{
			lec[0].work(arr1[ss[i]]);
			i++;
			cout<<endl;
		}
		cout<<"After all,"<<lec[0].getName()<<" "<<lec[0].getSurname()<<" happiness is "<<lec[0].getHapiness()<<".My money is "<<money/4<<".Contribution of university is "<<sum<<endl;

	}
	if(flag==1)
	{
		i=0;
		while(i<12)
		{
			ra[0].work(arr1[ss[i]]);
			i++;
			cout<<endl;

		}
		cout<<"After all,"<<ra[0].getName()<<" "<<ra[0].getSurname()<<" happiness is "<<ra[0].getHapiness()<<".My money is "<<money/4<<".Contribution of university is "<<sum1<<endl;

	}
	if(flag==2)
	{
		i=0;
		while(i<12)
		{
			sec[0].work(arr1[ss[i]]);
			i++;
			cout<<endl;

		}
		cout<<"After all,"<<sec[0].getName()<<" "<<sec[0].getSurname()<<" happiness is "<<sec[0].getHapiness()<<money/4<<".Contribution of university is"<<sum2 <<endl;

	}
	if(flag==3)
	{
		i=0;
		while(i<12)
		{
			off[0].work(arr1[ss[i]]);
			i++;
			cout<<endl;

		}
		cout<<"After all,"<<off[0].getName()<<" "<<off[0].getSurname()<<" happiness is "<<off[0].getHapiness()<<".My money is "<<money/4<<".Contribution of university is"<<sum3 <<endl;
	}
}
void ComUni::employ()
{
	
}

University* LiberalEducation::foundUni(int uniType)
{
 	LiberalEducation *lib;
 	return lib->uni;
	
}
Employee& LiberalEducation::giveJob(string name,string surname,int empType)
{
	if(empType==0)
	{
		LibLec *ll=new LibLec;
		ll->setName("My");
		ll->setSurname("");
		return *ll;
		
	}
	else if(empType==1)
	{
		LibLec *ll=new LibLec;
		ll->setName("My");
		ll->setSurname("");
		return *ll;
	}
	else if(empType==2)
	{
		LibLec *ll=new LibLec;
		ll->setName("My");
		ll->setSurname("");
		return *ll;
	}
	else if(empType==3)
	{
		LibLec *ll=new LibLec;
		ll->setName("My");
		ll->setSurname("");
		return *ll;

	}
	
}
University* communistEducation::foundUni(int uniType)
{
 	communistEducation *lib;
 	return lib->uni;
	
}
Employee& communistEducation::giveJob(string name,string surname,int empType)
{
	if(empType==0)
	{
		ComLec *ll=new ComLec;
		ll->setName("My");
		ll->setSurname("");
		return *ll;
		
	}
	else if(empType==1)
	{
		ComLec *ll=new ComLec;
		ll->setName("My");
		ll->setSurname("");
		return *ll;
	}
	else if(empType==2)
	{
		ComLec *ll=new ComLec;
		ll->setName("My");
		ll->setSurname("");
		return *ll;
	}
	else if(empType==3)
	{
		ComLec *ll=new ComLec;
		ll->setName("My");
		ll->setSurname("");
		return *ll;

	}
	
}
int LibUni::contribute(int a)
{
	cont=cont+a;
	return cont;
}
void LibUni::start()/*print output*/
{	
	//determination of action*/
	//tell story while talking actors
    int a;
	cout<<"I see that there is an opportunity for being Lecturer in the university.So I am Lecturer."<<endl;
	cout<<"University has project.I did research.";
	a=emp->work(project);
	cout<<endl;
	cout<<"University has seminar.I did seeSuccessfulStudent.";
	a=emp->work(seminar);
	cout<<"and my money is "<<contribute(a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has academicPaper.I did makePublish.";
	a=emp->work(academicPaper);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has academicPaper.I did makePublish.";
	a=emp->work(academicPaper);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has academicPaper.I did makePublish.";
	a=emp->work(academicPaper);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has seminar.I did seeSuccessfulStudent.";
	a=emp->work(seminar);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has academicPaper.I did makePublish.";
	a=emp->work(academicPaper);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has academicPaper.I did makePublish.";
	a=emp->work(academicPaper);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has academicPaper.I did makePublish.";
	a=emp->work(academicPaper);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has academicPaper.I did makePublish.";
	a=emp->work(academicPaper);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has seminar.I did seeSuccessfulStudent.";
	a=emp->work(seminar);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has academicPaper.I did makePublish.";
	a=emp->work(academicPaper);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has academicPaper.I did makePublish.";
	a=emp->work(academicPaper);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;

	cout<<"University has academicPaper.I did makePublish.";
	a=emp->work(academicPaper);
	cout<<"and my money is "<<contribute(a-a)<<" I contribute "<<contribute(a)<<" to university"<<endl;
	cout<<"After all, my happiness is "<<emp->getHapiness()<<" My money is "<<contribute(a-a)<<".Contribution of university is "<<contribute(a-a)<<endl;
	/*print summary*/
}
void LibUni::employ()
{
	LibLec *ll=new LibLec;
	string s,m;
	ll->setName("My");
	ll->setSurname("");
	emp=ll;
}

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
	else
	{
		cout<<"I cannot do that.";
		return 0;
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
	else
	{
		cout<<"I cannot do that.";
		return 0;
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
	else
	{
		cout<<"I cannot do that.";
		return 0;
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
	else
	{
		cout<<"I cannot do that.";
		return 0;
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