#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "educationSystem.h"
#include "communistEducation.h"
#include "liberalEducation.h"
#include "University.h"
#include "libUni.h"
#include "comUni.h"
#include "employee.h"
#include "lecturer.h"
#include "ra.h"
#include "secretary.h"
#include "officer.h"
using namespace std;
void communist();
void capitalist();
int main()
{
	
cout<<"**********************************LİBERAL EDUCATİON***************************************"<<endl;
	cout<<endl;
	string aa,bb;

	srand(time(NULL));
	LiberalEducation lib;		/*Liberal education system*/
	LibUni libedu; 				

	lib.uni=lib.foundUni(5);	/*create liberal university*/
	
	lib.uni->emp=&lib.giveJob(aa,bb,0);/*actor decision*/
	
	libedu.cont=0;

	libedu.employ();
	libedu.start();	/*start liberal*/

cout<<"**********************************COMMUNİST EDUCATİON***************************************"<<endl;
cout<<endl;
	communist();
	capitalist();
	
	


}
void communist()
{
	string aa,bb;
	communistEducation com;//Communist education ststem
	ComUni comedu;

	com.un=com.foundUni(5);
	comedu.start();/*tell story*/
}
void capitalist()
{
	ifstream file("personnellist.txt");
	 Employee *tt=NULL;
	 Employee *bl;
	 bl=tt;

	string a,b,c;
	int i=0;
	while(!file.eof())
	{

		if(i<8)
		{
				bl=new Lecturer;
			file>>a;
			file>>b;
			file>>c;
			bl->setName(a);
			bl->setSurname(b);
			bl->typ=c;
			i++;
		}
		else if(i<16)
		{
			bl=new ResearchAssistant;
			file>>a;
			file>>b;
			file>>c;
			bl->setName(a);
			bl->setSurname(b);
			bl->typ=c;
			i++;

		}
		else if(i<23)
		{
			bl=new Secretary;
			file>>a;
			file>>b;
			file>>c;
			bl->setName(a);
			bl->setSurname(b);
			bl->typ=c;
			i++;
		}
		else if(i<30)
		{

			bl=new Officer;
			file>>a;
			file>>b;
			file>>c;
			bl->setName(a);
			bl->setSurname(b);
			bl->typ=c;
			i++;
		}
		bl=bl->getLink();
		

	}
	//cout<<bl->getName()<<endl;

	/*Employee *aa=new BrokerLec;
	Employee *w1=new WorkerLec;
	Employee *w2=new WorkerLec;
	aa=tt;
	w1=tt->getLink();
	w2=tt->getLink()->getLink();*/




}