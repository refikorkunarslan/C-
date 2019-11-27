#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "YOK.h"
#include "university.h"
#include "complex.h"
#include "employee.h"
#include "lecturer.h"
#include "ra.h"
#include "secretary.h"
#include "officer.h"
using namespace std;
int main()
{
	srand(time(NULL));
	int lec_size=2;
	int lec_iter=0;
	int ra_size=2;
	int ra_iter=0;	/*increased as you add elements*/
	int sec_size=2;
	int sec_iter=0;
	int off_size=2;
	int off_iter=0;
	Lecturer *lec=new Lecturer[1];
	Lecturer *temp=new Lecturer[1];
	ResearchAssistant *ra=new ResearchAssistant[1];
	ResearchAssistant *temp1=new ResearchAssistant[1];
	Secretary *sec=new Secretary[1];
	Secretary *temp2=new Secretary[1];
	Officer *off=new Officer[1];
	Officer *temp3=new Officer[1];
	ifstream file("personnellist.txt");
	int random;
	int q=0;
	int a,b;
	string c,d;

	while(!file.eof())	/*read file*/
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
		   temp=new Lecturer[lec_size];
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
		   temp1=new ResearchAssistant[ra_size];
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
		   temp2=new Secretary[sec_size];
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
		   temp3=new Officer[off_size];
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
	int ran;
	action arr1[6];
	arr1[0]=slackness;
	arr1[1]=lesson;
	arr1[2]=seminar;
	arr1[3]=academicPaper;
	arr1[4]=homeworkTime;
	arr1[5]=solution;
	action arr2[6];
	arr2[0]=slackness;
	arr2[1]=project;
	arr2[2]=seminar;	/*action for Employee type*/
	arr2[3]=academicPaper;
	arr2[4]=homeworkTimeout;
	arr2[5]=solution;
	action arr3[4];
	arr3[0]=slackness;
	arr3[1]=administration;
	arr3[2]=incident;
	arr3[3]=solution;
	action arr4[4];
	arr4[0]=document;
	arr4[1]=slackness;
	arr4[2]=administration;
	arr4[3]=solution;
	int aaa;
	double bbb;
	University<int > *gtu=new University<int>;/*produce int*/
	University<double> *odtu=new University<double>;/*produce double*/
	University<Complex<int>>* au = new University<Complex<int>>;/*produce complex*/
	gtu->cont=0;
	odtu->cont=0;
	au->cont=0;
	YOK yok;	/*yok object*/
	yok.lecc=new Lecturer[30];
	yok.raa=new ResearchAssistant[30];
	yok.secc=new Secretary[30];
	yok.offf=new Officer[30];
	gtu=yok.foundUni( aaa);
	odtu=yok.foundUni(bbb);
	//au=yok.foundUni(ccc);
	int i=0,k=0,j=0,l=0,z=0;
	int tt;
	int count1=0,count2=0,count3=0,count4=0;
	int c1=0,c2=0,c3=0,c4=0;
	
	i=0;
	while(z<30)/*random assign Employee*/
	{
		tt=rand()%4;/*random assing Employee type(lecturer..)*/
		

		if(tt==0 && i<=lec_size)/*for lecturer*/
		{

			random=rand()%(lec_size-2);
			if(lec[random].ww==0 )
			{
				
				
				lec[random].ww=1;
				if(z<10)	/*for gtu*/
				{
					cout<<"GTU"<<" request"<<" Lecturer"<<endl;
					yok.lecc[i]=yok.givejob(lec[random].getName(),lec[random].getSurname(),0);/*give job*/
					cout<<"YOK give job to "<<yok.lecc[i].getName()<<" "<<yok.lecc[i].getSurname()<<" as "<<"Lecturer"<<endl;
					lec[random].employ(gtu);/*record gtu adresss*/
					
					c1++;
					count1++;
					z++;
					i++;
				}
				else if(z<20)/*for odtu*/
				{
					cout<<"ODTU"<<" request"<<" Lecturer"<<endl;

					yok.lecc[i]=yok.givejob(lec[random].getName(),lec[random].getSurname(),0);/*give job*/
					cout<<"YOK give job to "<<yok.lecc[i].getName()<<" "<<yok.lecc[i].getSurname()<<" as "<<"Lecturer"<<endl;
					lec[random].employ(odtu);/*record odtu adress*/
					
					
					count1++;
					z++;
					i++;

				}
				else if(z<30)/*for au*/
				{
					cout<<"AU"<<" request"<<" Lecturer"<<endl;

					yok.lecc[i]=yok.givejob(lec[random].getName(),lec[random].getSurname(),0);/*for give job*/
					cout<<"YOK give job to "<<yok.lecc[j].getName()<<" "<<yok.lecc[j].getSurname()<<" as "<<"Lecturer"<<endl;
					lec[random].employ(au);/*record au adress*/
					
					
					count1++;
					z++;
					i++;

				}
			}
		}
		else if(tt==1 && j<=ra_size)
		{
			random=rand()%ra_iter;
			if(ra[random].ww==0)
			{
				
				ra[random].ww=1;
				if(z<10)
				{
					cout<<"GTU"<<" request"<<" ResearchAssistant"<<endl;

					yok.raa[j]=yok.givejob(ra[random].getName(),ra[random].getSurname(),1);
					cout<<"YOK give job to "<<yok.raa[j].getName()<<" "<<yok.raa[j].getSurname()<<" as "<<"ResearchAssistant"<<endl;
					ra[random].employ(gtu);/*record gtu adresss*/
					
					c2++;
					count2++;
					z++;
					j++;
				}
				else if(z<20)
				{
					cout<<"ODTU"<<" request"<<" ResearchAssistant"<<endl;

					yok.raa[j]=yok.givejob(ra[random].getName(),ra[random].getSurname(),1);
					cout<<"YOK give job to "<<yok.raa[j].getName()<<" "<<yok.raa[j].getSurname()<<" as "<<"ResearchAssistant"<<endl;
					ra[random].employ(odtu);
					
					
					count2++;
					z++;
					j++;

				}
				else if(z<30)
				{
					cout<<"AU"<<" request"<<" ResearchAssistant"<<endl;

					yok.raa[j]=yok.givejob(ra[random].getName(),ra[random].getSurname(),1);
					cout<<"YOK give job to "<<yok.raa[j].getName()<<" "<<yok.raa[j].getSurname()<<" as "<<"ResearchAssistant"<<endl;
					ra[random].employ(au);
					
					
					count2++;
					z++;
					j++;

				}
			}
		}
		else if(tt==2 && k<=sec_size)
		{
			random=rand()%sec_iter;
			if(sec[random].ww==0)
			{	
				sec[random].ww=1;
				if(z<10)
				{
					cout<<"GTU"<<" request"<<" Secretary"<<endl;

					yok.secc[k]=yok.givejob(sec[random].getName(),sec[random].getSurname(),2);
					cout<<"YOK give job to "<<yok.secc[k].getName()<<" "<<yok.secc[k].getSurname()<<" as "<<"Secretary"<<endl;
					sec[random].employ(gtu);/*record gtu adresss*/
					
					c3++;
					count3++;
					z++;
					k++;
				}
				else if(z<20)
				{
					cout<<"ODTU"<<" request"<<" Secretary"<<endl;

					yok.secc[k]=yok.givejob(sec[random].getName(),sec[random].getSurname(),2);
					cout<<"YOK give job to "<<yok.secc[k].getName()<<" "<<yok.secc[k].getSurname()<<" as "<<"Secretary"<<endl;
					sec[random].employ(odtu);
					
					
					count3++;
					z++;
					k++;

				}
				else if(z<30)
				{
					cout<<"AU"<<" request"<<" Secretary"<<endl;

					yok.secc[k]=yok.givejob(sec[random].getName(),sec[random].getSurname(),2);
					cout<<"YOK give job to "<<yok.secc[k].getName()<<" "<<yok.secc[k].getSurname()<<" as "<<"Secretary"<<endl;
					sec[random].employ(au);
					
					
					count3++;
					z++;
					k++;

				}
			}
		}
		else if(tt==3 && l<=off_size)
		{
			random=rand()%off_iter;
			if(off[random].ww==0)
			{	
				off[random].ww=1;
				if(z<10)
				{
					cout<<"GTU"<<" request"<<" Officer"<<endl;

					yok.offf[l]=yok.givejob(off[random].getName(),off[random].getSurname(),3);
					cout<<"YOK give job to "<<yok.offf[l].getName()<<" "<<yok.offf[l].getSurname()<<" as "<<"Officer"<<endl;
					off[random].employ(gtu);/*record gtu adresss*/
					
					
					count4++;
					c4++;
					z++;
					l++;
				}
				else if(z<20)
				{
					cout<<"ODTU"<<" request"<<" Officer"<<endl;

					yok.offf[l]=yok.givejob(off[random].getName(),off[random].getSurname(),3);
					cout<<"YOK give job to "<<yok.offf[l].getName()<<" "<<yok.offf[l].getSurname()<<" as "<<"Officer"<<endl;
					off[random].employ(odtu);
					
					
					count4++;

					z++;
					l++;
				}
				else if(z<30)
				{
					cout<<"AU"<<" request"<<" Officer"<<endl;

					yok.offf[l]=yok.givejob(off[random].getName(),off[random].getSurname(),3);
					cout<<"YOK give job to "<<yok.offf[l].getName()<<" "<<yok.offf[l].getSurname()<<" as "<<"Officer"<<endl;
					off[random].employ(au);
					
					
					count4++;

					z++;
					l++;

				}
			}

		}
	}
	i=0;
		int yy=0;
		int ac;
		while(yy<15)/*random action*/
		{
			i=0;
			while(i<count1)
			{
				ran=rand()%6;
				yok.lecc[i].act=arr1[ran];
				ac=yok.lecc[i].work(yok.lecc[i].act);/*random work*/
				if(yy<5)
				{
					cout<<"contribution of uni is "<<gtu->contribute(ac)<<endl;/*for gtu*/
					
				}
				else if(yy<10)
				{
					cout<<"contribution of uni is "<<odtu->contribute(ac)<<endl;/*for odtu*/

				}
				else
				{
					au->cont=au->cont+ac;
					cout<<"contribution of uni is "<<au->cont+ac-ac<<endl;/*for au*/
				}
			 	i++;
			 }
			i=0;
			while(i<count2)
			{
			    ran=rand()%6;
			    yok.raa[i].act=arr2[ran];
					ac=yok.raa[i].work(yok.raa[i].act);
				if(yy<5)
				{
					cout<<"contribution of uni is "<<gtu->contribute(ac)<<endl;
					
				}
				else if(yy<10)
				{
					cout<<"contribution of uni is "<<odtu->contribute(ac)<<endl;

				}	
				else
				{
					au->cont=au->cont+ac;

					cout<<"contribution of uni is "<<au->cont+ac-ac<<endl;
				}
					i++;
					
			}		
			i=0;
			while(i<count3)
			{
					ran=rand()%4;
					yok.secc[i].act=arr3[ran];
					ac=yok.secc[i].work(yok.secc[i].act);
				if(yy<5)
				{
					cout<<"contribution of uni is "<<gtu->contribute(ac)<<endl;
					
				}
				else if(yy<10)
				{
					cout<<"contribution of uni is "<<odtu->contribute(ac)<<endl;

				}	
				else
				{
					au->cont=au->cont+ac;

					cout<<"contribution of uni is "<<au->cont+ac-ac<<endl;
				}
					i++;
			
			}
			i=0;
			while(i<count4)
			{
				ran=rand()%4;
				yok.offf[i].act=arr4[ran];
					ac=yok.offf[i].work(yok.offf[i].act);
				if(yy<5)
				{
					cout<<"contribution of uni is "<<gtu->contribute(ac)<<endl;
					
				}
				else if(yy<10)
				{
					cout<<"contribution of uni is "<<odtu->contribute(ac)<<endl;

				}
				else
				{
					au->cont=au->cont+ac;

					cout<<"contribution of uni is "<<au->cont+ac-ac<<endl;
				}		
					i++;
				
			 }
				
				yy++;

		}
	

}
