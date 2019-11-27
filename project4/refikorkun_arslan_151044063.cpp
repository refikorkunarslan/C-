#include "lecture.h"
#include "student.h"
#include "attendance.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <random>
using namespace std;
namespace hw3	/*homework 3 functions*/
{
	void lecturer::setInput(int id,string name1, string surname1,string tittle1,string profession1,int as)
	{
		personal_id = id;
		name = name1;
		surname = surname1;
		title = tittle1;
		professions = profession1;
		count1=as;
		
	}
	bool lecturer::assignCourse(Course &cour)
	{
		int i=0,j=0;
		string asd;
		
			if (professions.find(cour.isMandatory) !=string::npos) 
			{

				if(count1>1)
				{
					count1=count1-1;
					courses=courses+cour.name;
					courses=courses+" ";
					cout<<"DONE"<<endl;
	  			}
	  			
	  		} 
	  		else
	  		{
	  			cout<<"Block: field and profession mismatch"<<endl;
	  		}
	  		
	}
	bool lecturer::assignCourse(vector<Course> &cour,int course_count)
	{
		string ss;
		int z=0;
		int yy=0;
		int i=0;
		int arr[course_count];

		i=0;
		
		int count=0;
		while(professions[i] !='\0')
		{
			if(professions[i]==',')
			{
				count++;
			}
			i++;
		}
		i=0;
		int j=0;

		while(j<count1)
		{

			z=0;
			yy=0;
			fill(arr,arr+course_count,0);
			i=0;	
				
			while(i<course_count)
			{
				if(professions.find(cour[i].isMandatory) !=string::npos)
				{
					if(cour[i].tt ==0 && cour[i].field ==0)
					{

						arr[z]=i;
						yy++;
						z++;
					}
						
				}
				i++;
			}
			if(yy==0)
			{
				break;
			}

			int randomNumber = ((arr) )[rand() % yy];
			cour[randomNumber].tt=1;
			cour[randomNumber].field=1;
			courses=courses+cour[randomNumber].name;
			courses=courses+" ";
			j++;
		}





		


	}
	void lecturer::assignCourse(vector<Course> &cour,lecturer lec[],int lecturer_count,int course_count)
	{
		int i=0;
		string token;
		int count=0;
		istringstream ss(professions);
		//count1=3;
		while(getline(ss,token,','))
		{
			count=0;
			while(i<lecturer_count)
			{
				
				
					if(lec[i].professions.find(token) !=string::npos)
					{
						count++;
					}
				i++;
			}
			i=0;
			if(count==1)
			{
				while(i<course_count)
				{
					if(token ==cour[i].isMandatory)
					{
						count1=count1-1;
						courses=courses+cour[i].name;
						courses=courses+" ";
						cour[i].tt=1;
						cour[i].field=1;
					}
					i++;
				}
				
			}
		}

	}
	bool lecturer::proposeCourse(vector<Course> &cour,string ww)/*propose*/
	{
			if(count1>1)
			{
				count1=count1-1;
				courses=courses+ww;
				courses=courses+" ";
			}
	}
	void Administrator::arrangeTimeTable(Course &cour)/*random time funcion*/
	{	
		int day,tim;
		string a;
		int m=cour.total_hours;
		
		while(m>0)
		{
			string str[5]={"Mon","Thu","Wed","Tue","Fri"};
			day=rand()%5;

			table=table+str[day];
			table=table+"_";
			string time[9]={"9","10","11","12","13","14","15","16","17"};
			tim=rand()%7;
			table=table+time[tim];
			table=table+"-";

			if(m/2>0)
			{
				table=table+time[tim+2];

			}
			else
			{
				table=table+time[tim+1];

			}
			if(m==cour.total_hours || m>2)
			{
				table=table+",";
			}
			m=m-2;
		}	
	}
	void Administrator::arrangeTimeTable(Course &cour,int course_count)
	{
		
			cout<<"DONE :"<<"("<<cour.id<<")"<<cour.name<<" "<<table<<endl;
		
	}
	bool Administrator::arrangeClasroom(Classroom &cr,int count,Course &cour)
	{
		string w;

		int i=0;
		int j=0;
		int x,y;
		w.clear();

		if(count==0)
		{
			
				w[0]=table[0];
				w[1]=table[1];
			
		}
		else if(count==1)
		{
			while(table[i] !=',')
			{
				i++;
			}
			i++;
			w[0]=table[i];
			w[1]=table[i+1];
			
		}
		else if(count==2)
		{
			while(table[i] !=',')
			{
				i++;
			}
			i++;
			while(table[i] !=',')
			{
				i++;
			}
			i++;
			w[0]=table[i];
			w[1]=table[i+1];
			

		}

		
			while(table[i] !='_')
			{
				i++;
			}

			
			if(w[0]=='M')
			{
				x=0;
			}
			
			
			if(w[0]=='T' && w[1]=='h')
			{
				x=1;
			}
			if(w[0]=='W')
			{
				x=2;
			}
			if(w[0]=='T' && w[1]=='u')
			{
				x=3;
			}
			if(w[0]=='F')
			{
				x=4;
			}
			
			i++;
			j=0;
			w.clear();
			
			while(table[i] !='-')
			{
				w[j]=table[i];
				i++;
				j++;
			}
			

			y=stoi(w);
			
			if(cr.arr[x][y] ==0 && cr.arr[x][y+1]==0)
			{

				cr.arr[x][y]=cour.id;
				cr.arr[x][y+1]=cour.id;
			}
			else
			{
			
				return 0;
			}
			
			i++;
			j=0;
			w.clear();
			while(table[i] !=',' && table[i] !='\0')
			{
				w[j]=table[i];
				i++;
				j++;
			}
			y=stoi(w);
			cr.arr[x][y]=cour.id;
			i++;
			return 1;
		
		



		
	}
	void Classroom::quitClassroom(int (*arar)[6][11],int x,int y)
		{
			student_inroom=student_inroom-1;
			cout<<student_inroom<<endl;
		}

	void Classroom::enterClassroom(int (*arar)[6][11],int x,int y)
		{
			int i=0;
			int w=student_inroom;
			int z=0;
			while(i<11)
			{
				if(arar[x][y][i] !=0)
				{
					student_inroom++;
					z=i;
				}
				
				i++;
			}
			
			student_inroom=student_inroom-w;
			cout<<student_inroom<<endl;

		}
	
}
namespace hw2/*homework 2 funcitons*/
{
					int Student::disenroll(Course &cour)/*disenroll funcion*/
		{
			int flag1=1;
			bool tf;	
				tf=control( cour, flag1);/*control function*/

				if(tf==0)
				{
					return 0;
				}
				else
				{
					return cour.credit;
				}
		}
		string Student::extractSchedule()
		{
			
		}
		bool Student::control(Course &cour,int flag1)
		{
			int fff=0;
			int count1=0;
			int flag=3;
			char time[2];
			char time1[2];
			int i=0;
			int x;
			int y;
			int z;
			int m1;
			int m2;
			int k=0;
			int p=0;
			int count2=0;
			int pp=0;
			while(cour.lecture_dates.size()>=i)
			{
				k=0;
				p=0;
				time[0]=' ';
				time[1]=' ';
				time1[0]=' ';
				time1[1]=' ';
				if(cour.lecture_dates[i]=='M')/*see monday and x=0*/
				{
					x=0;
				}
				else if(cour.lecture_dates[i]=='T' && cour.lecture_dates[i+1]=='U')
				{
					x=1;
				}
				else if(cour.lecture_dates[i]=='W')
				{

					x=2;
				}
				else if(cour.lecture_dates[i]=='T' && cour.lecture_dates[i+1]=='H')
				{

					x=3;
				}
				else if(cour.lecture_dates[i]=='F')
				{

					x=4;
				}

				while(cour.lecture_dates[i] !='_')
				{
					i++;
				}
				i=i+1;
				int count=0;
				while(cour.lecture_dates[i] !='-')
				{
					count++;
					time[p]=cour.lecture_dates[i];/*convert from string to integer*/
					p++;
					i++;
				}
				i=i+1;
				y=stoi(time);
				p=0;
				while(cour.lecture_dates[i] !=',' && cour.lecture_dates[i] !='\0')
				{
					time1[p]=cour.lecture_dates[i];
					i++;	/*convert from string to integer*/
					p++;
				}
				i=i+1;
				z=stoi(time1);
				if(flag1==1)	/*disenroll part*/
				{
					if(array[cour.id]==0)
					{
						flag=0;
					}
					else
					{
						int j=0;
						pp=1;
						int ff=0;
						while(j<24)
						{
							if(arr[x][j]==y && arr[x][j+1]==z )
							{
								ff=1;
								break;
							}
							if(ff==1)
							{
								break;
							}
							j +=2;

						}
						if(arr[x][j]==y && arr[x][j+1]==z )
						{
							arr[x][j]=-1;
							arr[x][j+1]=-1;
						}	
						flag=1;
					}
				}
				else/*enroll part*/
				{
					array[cour.id]=1;
					if(arr[x][0]==0)
					{
						arr[x][0]=y;	/*first elemet*/
						arr[x][1]=z;
						flag=1;
					}
					else
					{
						while(arr[x][k+1] !=0)
						{
							
							if(arr[x][k]>=y )
							{
								m1=arr[x][k];	/* get first biggest*/

							}
							else
							{
								m1=y;			/*control overlapped*/
							}
						
							if(arr[x][k+1]<=z)
								{
								m2=arr[x][k+1];	/*get seconde smallest*/
							}
							else
							{
								m2=z;
							}
							if(m2-m1>=2)	/*fist biggest and seconde smalles extracion*/
							{
							
								flag=0;
								
								
							}
							k++;
						}
							arr[x][k+1]=y;
							arr[x][k+2]=z;
				}
				 if(flag==0 )
				 {
				 	break;
				 }
			}
			}
			if(pp==1)
			{
				array[cour.id]=0;	
			}

			if(flag==0)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		

}

