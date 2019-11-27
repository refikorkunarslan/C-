#include <iostream>
#include <cstdlib>
#include <time.h>
#include "inher.h"
#include <fstream>
#define actor 10/*number of actor*/
#define action 50/*number of action*/
using namespace std;
int main()
{
	srand(time(NULL));	/*random function*/
	Employee uni;
	ifstream file("personnellist.txt");
	int yy=0;
	while(!file.eof())	/*read file*/
	{
		uni.getEmp()[yy].ww=0;
		file>>uni.getEmp()[yy].asd;
		file>>uni.getEmp()[yy].namee;
		file>>uni.getEmp()[yy].surnamee;
		yy++;
	}
	Lecturer lec[6];
	ResearchAssistant ra[6];
	Officer off[7];
	Secretary sec[6];
	string pro;
	int lec_count=0;
	int ra_count=0;
	int sec_count=0;
	int off_count=0;
	int w,random;
	int ll=0,i=0,y=0,z=0;
	int tt=0;
	while(tt<actor)/*Randomly 10 people to choose*/
	{
		w=rand()%yy-1;/*random personal*/

		if(uni.getEmp()[w].ww==0)
		{
			uni.getEmp()[w].ww=1;	
			if(uni.getEmp()[w].asd=="Lecturer")
			{
				lec_count++;	/*number of lecturer*/
				lec[ll].employ(uni.getEmp());
				lec[ll].setHappinees(0);
				lec[ll].setPid(0);
				lec[ll].setName(uni.getEmp()[w].namee);
				lec[ll].setSurname(uni.getEmp()[w].surnamee);
				ll++;
			}
			else if(uni.getEmp()[w].asd=="ResearchAssistant")
			{
				ra_count++;	/*number of research assistant*/
				ra[i].employ(uni.getEmp()); /*record university pointer*/
				ra[i].setHappinees(0);
				ra[i].setPid(1);
				ra[i].setName(uni.getEmp()[w].namee);
				ra[i].setSurname(uni.getEmp()[w].surnamee);
				i++;	
			}
			else if(uni.getEmp()[w].asd=="Secretary")
			{
				sec_count++;/*number of secretary*/
				sec[y].employ(uni.getEmp());/*record university pointer*/
				sec[y].setHappinees(0);
				sec[y].setPid(2);
				sec[y].setName(uni.getEmp()[w].namee);
				sec[y].setSurname(uni.getEmp()[w].surnamee);
				y++;	
			}
			else if(uni.getEmp()[w].asd=="Officer")
			{

				off_count++;/*number officer*/
				off[z].employ(uni.getEmp());/*record university pointer*/
				off[z].setHappinees(0);

				off[z].setPid(3);
				off[z].setName(uni.getEmp()[w].namee);
				off[z].setSurname(uni.getEmp()[w].surnamee);
				z++;	
			}
			tt++;
		}
	}
		
	
	
	
	i=0;
	int ran;
	int *arr1=new int [6];/*actions assing array after random choose*/
	arr1[0]=1;
	arr1[1]=3;
	arr1[2]=4;
	arr1[3]=5;
	arr1[4]=7;
	arr1[5]=10;
	int *arr2=new int [6];
	arr2[0]=1;
	arr2[1]=2;
	arr2[2]=4;
	arr2[3]=5;
	arr2[4]=8;
	arr2[5]=10;
	int *arr3=new int [4];
	arr3[0]=1;
	arr3[1]=6;
	arr3[2]=9;
	arr3[3]=10;
	int *arr4=new int[4];
	arr4[0]=0;
	arr4[1]=1;
	arr4[2]=6;
	arr4[3]=10;
	

	
	while(i<action)/*random action*/
	{
		
		random=rand()%4;
		if(random==0 && lec_count !=0)
		{
			ran=rand()%6;
			random=rand()%lec_count;
			if(arr1[ran]==slackness)
			{
				lec[random].drinkTea();
				uni.getEmp()->contribution=uni.getEmp()->contribution-2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;
			}
			else if(arr1[ran]==lesson)
			{
				lec[random].giveLesson();
				uni.getEmp()->contribution=uni.getEmp()->contribution+5;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;	
			}
			else if(arr1[ran]==seminar)
			{
				lec[random].seeSuccessfulStudent();
				uni.getEmp()->contribution=uni.getEmp()->contribution+0;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr1[ran]==academicPaper)
			{
				lec[random].makePublish();
				uni.getEmp()->contribution=uni.getEmp()->contribution+5;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr1[ran]==homeworkTime)
			{
				lec[random].giveHW();
				uni.getEmp()->contribution=uni.getEmp()->contribution+1;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr1[ran]==solution)
			{
				lec[random].submitPetition();
				uni.getEmp()->contribution=uni.getEmp()->contribution-2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;
			}

		}
		else if(random==1 && ra_count !=0)
		{
			ran=rand()%6;
			random=rand()%ra_count;
			if(arr2[ran]==slackness)
			{
				
				ra[random].drinkTea();
				uni.getEmp()->contribution=uni.getEmp()->contribution-2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;
			}
			else if(arr2[ran]==project)
			{
				ra[random].research();
				uni.getEmp()->contribution=uni.getEmp()->contribution+4;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr2[ran]==seminar)
			{
				ra[random].seeSuccessfulStudent();
				uni.getEmp()->contribution=uni.getEmp()->contribution+0;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr2[ran]==academicPaper)
			{
				ra[random].makePublish();
				uni.getEmp()->contribution=uni.getEmp()->contribution+5;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr2[ran]==homeworkTimeout)
			{
				ra[random].readHW();
				uni.getEmp()->contribution=uni.getEmp()->contribution+2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr2[ran]==solution)
			{
				ra[random].submitPetition();
				uni.getEmp()->contribution=uni.getEmp()->contribution-2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}

		}
		else if(random==2 && sec_count !=0)
		{
			ran=rand()%4;
			random=rand()%sec_count;
			if(arr3[ran]==slackness)
			{
				sec[random].drinkTea();
				uni.getEmp()->contribution=uni.getEmp()->contribution-2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;
			}
			else if(arr3[ran]==administration)
			{
				sec[random].manageProcess();
				uni.getEmp()->contribution=uni.getEmp()->contribution+2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr3[ran]==incident)
			{
				sec[random].receivePetition();
				uni.getEmp()->contribution=uni.getEmp()->contribution-1;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr3[ran]==solution)
			{
				sec[random].submitPetition();
				uni.getEmp()->contribution=uni.getEmp()->contribution-2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}

		}
		else if(random==3 && off_count !=0)
		{
			ran=rand()%4;
			random=rand()%off_count;
			if(arr4[ran]==document)
			{
				off[random].makeDoc();
				uni.getEmp()->contribution=uni.getEmp()->contribution+3;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;
			}
			else if(arr4[ran]==slackness)
			{
				off[random].drinkTea();
				uni.getEmp()->contribution=uni.getEmp()->contribution-2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr4[ran]==administration)
			{
				off[random].manageProcess();
				uni.getEmp()->contribution=uni.getEmp()->contribution+2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}
			else if(arr4[ran]==solution)
			{
				off[random].submitPetition();
				uni.getEmp()->contribution=uni.getEmp()->contribution-2;
				cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

			}

		}
		i++;
	}
	for(int i=0;i<lec_count;i++)
	{
		cout<<"Happiness of "<<lec[i].getName()<<" "<<lec[i].getSurname()<<" is "<<lec[i].getHappiness()<<endl;
	}
	for(int i=0;i<ra_count;i++)
	{
		cout<<"Happiness of "<<ra[i].getName()<<" "<<ra[i].getSurname()<<" is "<<ra[i].getHappiness()<<endl;
	}
	for(int i=0;i<sec_count;i++)
	{
		cout<<"Happiness of "<<sec[i].getName()<<" "<<ra[i].getSurname()<<" is "<<sec[i].getHappiness()<<endl;
	}
	for(int i=0;i<off_count;i++)
	{
		cout<<"Happiness of "<<off[i].getName()<<" "<<ra[i].getSurname()<<" is "<<off[i].getHappiness()<<endl;
	}
	cout<<"contribution of uni is "<<uni.getEmp()->contribution<<endl;

}

