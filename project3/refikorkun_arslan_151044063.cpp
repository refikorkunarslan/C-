#include "lecture.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <random>
using namespace std;
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
bool lecturer::assignCourse(vector<Course> &cour,vector<lecturer> &lec,int lecturer_count,int course_count)
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
		string time[13]={"8","9","10","11","12","13","14","15","16","17","18","19","20"};
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
bool Administrator::arrangeClasroom(Classroom &cr,int count)
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

			cr.arr[x][y]=1;
			cr.arr[x][y+1]=1;
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
		cr.arr[x][y]=1;
		i++;
		return 1;
	
	



	
}
