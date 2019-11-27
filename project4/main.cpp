#include "lecture.h"
#include "student.h"
#include "attendance.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main()
{
	srand(time(NULL));/*for timetable and assign*/
	hw3::lecturer *lec=new hw3::lecturer[7]; /*dynamical multi dimensional object*/
	hw3::lecturer lec_temp;
	int tmp_personal_id;

	string tmp_name,tmp_surname, tmp_title,tmp_professions;//lecturer variable//
	ifstream file("lecturers.txt");	
	int lecturer_count=0;
	int ll=0;			
	while( !file.eof())/*read file*/
	{

		file >> tmp_personal_id;
		file >> tmp_name;
		file>> tmp_surname;
		file>> tmp_title;
		file>> tmp_professions;
		lec[ll].setInput(tmp_personal_id,tmp_name,tmp_surname,tmp_title,tmp_professions,3);
		lecturer_count++;
		ll++;
	}
	
	int course_count=0,classroom_count=0;
	vector<hw3::Course> c1;

	hw3::Classroom cr[6];

	hw3::Classroom cr_temp;

	hw3::Course c1_temp;
	string course_temp,garbage,classroom_temp;
	ifstream course_file("courses_classrooms.txt");
	getline(course_file,garbage);
	
	while(getline(course_file,course_temp))/*read file*/
	{
		if(course_temp[0]=='C' && course_temp[1]=='L' &&  course_temp[8]=='M')
		{
			break;
		}
		istringstream some_stream(course_temp);
		some_stream>>c1_temp.id;		
		some_stream>>c1_temp.name;
		some_stream>>c1_temp.code;
		some_stream>>c1_temp.credit;
		some_stream>>c1_temp.total_hours;
		some_stream>>c1_temp.isMandatory;
		course_count++;
		c1.push_back(c1_temp);

	}
	
	
	int ty=0;
	while(getline(course_file,classroom_temp))/*read classroom*/
	{
		istringstream some_stream(classroom_temp);
		some_stream>>cr[ty].id;		
		some_stream>>cr[ty].c_no;
		some_stream>>cr[ty].capacity;
		classroom_count++;
		ty++;
	}
	string input,com,courseName,courseField;
	int courseCode,courseCredit,courseHours;
	int i=0;
	int number,num,j=0;
	int there1=0;
	hw3::Administrator admin[course_count];
	while(i<course_count)
	{
		c1[i].flagg=0;
		i++;
	}
	i=0;
	while(i<classroom_count)
	{
		for(int k=0;k<5;k++)
		{
			for(int l=0;l<24;l++)
			{
				cr[i].arr[k][l]=0;
			}
		}
		i++;
	}
	i=0;
	int flag3=0;
	
		input="assign";												/*Call assign function*/
		cout<<input<<endl;
		istringstream some_stream(input);
		i=0;
		j=0;
		
	    if(input[0]=='a'&& input[1]=='s' && input[6]=='\0')
		{

			int flag=0;
			int i=0;
			istringstream ss(lec[0].professions);
			string token;
			int count=0;
			int q,o=0;
			while(flag==0)
			{
				i=0;
				while(i<course_count)
				{
					c1[i].field=0;
					i++;
				}
				i=0;
				while(i<course_count)
				{
					c1[i].tt=0;
					i++;
				}
				i=0;
				
				while(o<lecturer_count)
				{
					lec[o].assignCourse(c1,lec,lecturer_count,course_count);
					o++;
				}
				o=0;
				int a;
				while(o<lecturer_count)
				{
					lec[o].assignCourse(c1,course_count);
					o++;
				}
				
				i=0;
					while(i<course_count)
					{
						i++;
					}
					i=0;
					while(i<course_count)
						{
							if(c1[i].tt ==0)
							{

								lec[0].set_Courses();
								lec[0].set_count();

								lec[1].set_Courses();
								lec[1].set_count();

								lec[2].set_Courses();		/*courses clear and*/
								lec[2].set_count();			/*again random distrubition*/
								
								lec[3].set_Courses();
								lec[3].set_count();
								
								lec[4].set_Courses();
								lec[4].set_count();
								
								lec[5].set_Courses();
								lec[5].set_count();
								
								lec[6].set_Courses();
								lec[6].set_count();
								flag=0;
								break;
							}
							else
							{

								flag=1;

							}
						i++;

						}
			}
		}
		
		input="timetable";										/*call timetable*/
		cout<<input<<endl;
		if(input[0]=='t'&& input[1]=='i' && input[2]=='m' && input[9]=='\0')
		{
			int i=0;
			while(i<course_count)
			{
				if(c1[i].flagg==0)
				{
					c1[i].flagg=1;
					admin[i].arrangeTimeTable(c1[i]);
				}
				i++;

			}
			i=0;
			while(i<course_count)
			{
				admin[i].arrangeTimeTable(c1[i], course_count);
				i++;
			}
		}
		input="arrangeC";
		cout<<input<<endl;
		 if(input[0]=='a'&& input[1]=='r' && input[2]=='r' && input[7]=='C'&& input[8]=='\0')
		{
			int i=0,j=0;
				int count=0,temp,temp1;
			int m,a;
			while(i<course_count)
			{	
				count=0;
				while((admin[i].getTable())[j] != '\0')
				{
					if((admin[i].getTable())[j] ==',')
					{
						count++;
					}
					j++;
				}

				m=0;
				
					j=0;
					while(j<count+1)
					{
						a=rand()%classroom_count;
						m=admin[i].arrangeClasroom(cr[a],j,c1[i]);
						if(j==0)
						{
							temp=a;
						}
						if(j==2)
						{
							temp1=a;
						}
						if(m==0)
						{
							j=0;
						}
						j++;
					}
					istringstream pp(admin[i].getTable());
					string mm,token;
					getline(pp,mm,',');
					cout<<"DONE :"<<"("<<c1[i].id<<")"<<c1[i].name<<" in "<<cr[temp].id<<" at "<<mm;

					int t=0,m=0;
					
					getline(pp,mm,',');
						cout<<","<<" in "<<cr[a].id<<" at "<<mm;
					if(count==2)
					{
						getline(pp,mm,',');
						cout<<","<<" in "<<cr[temp1].id<<" at "<<mm;
					}
					cout<<endl;
					
					
				i++;
			}

		}
		
		ifstream fil("student.txt");	/*read student.txt*/
		hw4::Attendance attd;
		hw4::Attendance ww;


		i=0;
		int k=0;
		while(!fil.eof())
		{
			fil>>attd.getName()[k];
			fil>>attd.getStudent_id()[k];	/*enter attance class variable*/
			
			k++;
			
		}
		string inp;
		int n1,n2,n3;
		int arar[19][6][11];
		
		int there2=0,there3=0;
		memset(arar, 0, 19*6*11*sizeof(int));
		while(1)
		{
			there2=0;
			there3=0;
			j=0;
			i=0;
			getline(cin,inp);
			istringstream some_stream(inp);
			if(inp[1]=='e' && inp[2]=='x')
			{
				exit(1); /*end of program*/
			}
			else if(inp[1]=='e' && inp[2]=='n')/*enter student in course*/
			{
				some_stream>>com;
				some_stream>>n1;
				some_stream>>n2;
				some_stream>>n3;
				while(i<11)
				{
					if(attd.getStudent_id()[i] ==n1)/*until student_id find*/
					{

						there2=1;/*conttrol do you have studen*/
						break;
					}
					i++;
				}
				
				while(j<6)
				{
					if(cr[j].id ==n2)/*until student_id find*/
					{
						there3=1; /*control do you have course*/
						break;

					}
					j++;
				}
				if(there2==0)
				{
					cout<<"ERROR: no student"<<endl;/*error message*/
				}
				else if(there3==0)
				{
					cout<<"ERROR: no class"<<endl;/*error message*/
				}
				else if(n3<=8)/*for monday*/
				{
					
					if(cr[j].arr[0][n3-1+9] !=0 && cr[j].arr[0][n3+9] !=0)/*control do you have lessons in that hour*/
					{
						attd.arrr[i][cr[j].arr[0][n3-1+9]][0]++;/*attandance count increase*/
						arar[cr[j].arr[0][n3-1+9]][j][cr[j].student_inroom]=attd.getStudent_id()[i];/*attandance assign student_id*/

						cr[j].enterClassroom(arar,cr[j].arr[0][n3-1+9],j);/*call enter classrom*/
					}
					else
					{
						cout<<"no lessons in class"<<endl;
					}

				}
				else/*other days of the week*/
				{
					
					int x=n3/8;
					int y=n3%8;
					if(cr[j].arr[x][y+9] !=0 && cr[j].arr[x][y-1+9] !=0)
					{

						attd.arrr[i][cr[j].arr[x][y+9]][0]++;
						arar[cr[j].arr[x][y+9]][j][cr[j].student_inroom]=attd.getStudent_id()[i];
						cr[j].enterClassroom(arar,cr[j].arr[x][y+9],j);
					}
					else
					{
						cout<<"no lessons in class"<<endl;
					}

				}

			}

			else if(inp[1]=='q')
			{
				int fflag=0;
				int n=0;
				int w=0;
				int f=0;
				some_stream>>com;
				some_stream>>n1;
				while(attd.getStudent_id()[i] !=n1)
				{
					i++;	/*find student_id*/
				}
				for(w=0;w<18;w++)
				{
					for(n=0;n<6;n++)
					{
						for(int m=0;m<11;m++)
						{
							if(arar[w][n][m] ==attd.getStudent_id()[i])
							{
								f=n;
								arar[w][n][m]=0;/*find student*/
								fflag=1;
								break;
							}

						}
						if(fflag==1)
						{
							break;
						}
					}
				
				}
				
				if(fflag==1)
				{
					cout<<"f :"<<f<<endl;
					cr[f].quitClassroom(arar,w,n+1);/*if find student,enter quitclassroom*/
				}
				else
				{
					cout<<"BLOCK: s/he is not in any classroom"<<endl;
				}

			}
			else if(inp[1]=='a')
			{
				some_stream>>com;
				
				some_stream>>n1;
				
				int fflag=0;
				int wat=0;
				while(wat<11)
				{
					fflag=0;
					if(attd.getArrr()[wat][n1][0] !=0)
					{
						for(int w=0;w<18;w++)
							{
								for(int n=0;n<6;n++)
								{
									for(int m=0;m<11;m++)
									{
										if(arar[w][n][m] ==attd.getStudent_id()[i])
										{
											
											fflag=1;
											break;
										}

									}
									if(fflag==1)
									{
										break;
									}
								}
							
							}
						if(fflag==1)
						{
							cout<<attd.getName()[wat]<<" "<<attd.getArrr()[wat][n1][0];
							cout<<"--";/*print assign of course student name*/
						}

					}
					wat++;
				}
				cout<<endl;

			}
			

		}
		
		

	
}

