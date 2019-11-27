#include "lecture.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;
int test();
int main()
{
	test();
	srand(time(NULL));
	vector<lecturer> lec;
	lecturer lec_temp;
	int tmp_personal_id;

	string tmp_name,tmp_surname, tmp_title,tmp_professions;//lecturer variable//
	ifstream file("lecturers.txt");	
	int lecturer_count=0;			
	while( !file.eof())/*read file*/
	{

		file >> tmp_personal_id;
		file >> tmp_name;
		file>> tmp_surname;
		file>> tmp_title;
		file>> tmp_professions;
		lec_temp.setInput(tmp_personal_id,tmp_name,tmp_surname,tmp_title,tmp_professions,3);
		lec.push_back(lec_temp);
		lecturer_count++;
	}
	
	int course_count=0,classroom_count=0;
	vector<Course> c1;
	vector<Classroom> cr;
	Classroom cr_temp;
	Course c1_temp;
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
	while(getline(course_file,classroom_temp))
	{
		istringstream some_stream(classroom_temp);
		some_stream>>cr_temp.id;		
		some_stream>>cr_temp.c_no;
		some_stream>>cr_temp.capacity;
		classroom_count++;
		cr.push_back(cr_temp);
	}
	string input,com,courseName,courseField;
	int courseCode,courseCredit,courseHours;
	int i=0;
	int number,num,j=0;
	int there1=0;

	Administrator admin[course_count];
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
	while(1)
	{
		getline(cin,input);
		istringstream some_stream(input);
		i=0;
		j=0;
		if(input[0]=='a'&& input[1]=='s' && input[6]==' ')
		{
			int there=0;
			some_stream>>com;
			some_stream>>number;
			some_stream>>num;
			while( i<lecturer_count)
			{
				if(number ==lec[i].get_Personal())	/*until number*/
				{
					break;
				}
				
				i++;
			}


			if(number ==lec[i].get_Personal())
			{
					there=1;			/*you have the appropriate student*/
			}
			j=0;
			while(j<course_count)
			{
				if(num ==c1[j].id)
				{
					break;
				}

				j++;				/*appropriate course*/
			}
			if(num ==c1[j].id)
			{
				there1=1;
			}
			
			if(there==1 && there1==1)
			{
				lec[i].assignCourse(c1[j]);

			}
			else
			{
				cout<<"Error: no lecture or course"<<endl;/*no found course or lecture*/
			}

		}
		else if(input[0]=='a'&& input[1]=='s' && input[6]=='\0')
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
		else if(input[0]=='p'&& input[1]=='r' && input[2]=='o')
		{
			some_stream>>com;
			some_stream>>number;
			some_stream>>courseName;
			some_stream>>courseCode;
			some_stream>>courseCredit;
			some_stream>>courseHours;
			some_stream>>courseField;
			int i=0;
			while(number ==lec[i].get_Personal())
			{
				break;	
				i++;
			}
			if(lec[i].get_Field().find(courseField) !=string::npos )
			{
					lec[i].proposeCourse(c1,courseName);
			}

		}
		else if(input[0]=='t'&& input[1]=='i' && input[2]=='m' && input[9]==' ')
		{
			some_stream>>com;
			some_stream>>number;
			int flag=0;
			int i=0;
			while(i<course_count)
			{
				if(number==c1[i].id)
				{
					flag=1;
					break;
				}
				i++;
			}
			if(c1[i].flagg ==0 && flag==1)
			{
				c1[i].flagg =1;	
				admin[i].arrangeTimeTable(c1[i]);
				cout<<"DONE :"<<"("<<number<<")"<<c1[i].name<<" "<<admin[i].getTable()<<endl;
			}
			else if(flag==0)
			{
				cout<<"Error: no course"<<endl;

			}
			else
			{
				cout<<"Assigned Before: "<<"("<<number<<")"<<c1[i].name<<" "<<admin[i].getTable()<<endl;
			}
		}
		else if(input[0]=='t'&& input[1]=='i' && input[2]=='m' && input[9]=='\0')
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
		else if(input[0]=='a'&& input[1]=='r' && input[2]=='r' && input[7]=='C'&& input[8]==' ')
		{
			flag3=0;
			int gg=0;
			bool a;
			string token,mm;
			int kk;
			int count=0;
			some_stream>>com;
			some_stream>>number;
			some_stream>>courseName;
			istringstream ss(courseName);
			
			while(i<course_count)
			{
				if(number==c1[i].id)
				{
					gg=1;
					break;
				}
				i++;
			}
			if(gg==0)
			{
				cout<<"Error: no course"<<endl;
				break;
			}
			if(c1[i].flagg==0)
			{
				cout<<"Error: timetable not arranged yet "<<endl;
				break;
			

			}

			while(getline(ss,token,','))
			{
				
				kk=stoi(token);
				j=0;

				while(j<classroom_count)
				{
					if(kk==cr[j].id)
					{
						flag3=1;
						break;
					}
					j++;
				}
				if(flag3 ==0 )
				{
					cout<<"Error: no class"<<endl;
					break;
				}	
				a=admin[i].arrangeClasroom(cr[j],count);
				

				count++;
				if(a==0)
				{
					cout<<"Block: class is not available, there is another class assigned for this date"<<endl;
					break;
				}
				istringstream pp(admin[i].getTable());
				if(count==1)
				{
					getline(pp,mm,',');
					cout<<"DONE :"<<"("<<c1[i].id<<")"<<c1[i].name<<" in "<<token<<" at "<<mm;
				}
				else 				
				{
					int t=0,m=0;
					getline(pp,mm,'\0');
					while(m<count-1)
					{	
						while(mm[t] !=',')
						{
							t++;
						}
						t++;
						m++;
					}
					cout<<","<<" in "<<token<<" at "<<&mm[t]<<endl;

				}


			
			}
			



		}
		else if(input[0]=='a'&& input[1]=='r' && input[2]=='r' && input[7]=='C'&& input[8]=='\0')
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
						m=admin[i].arrangeClasroom(cr[a],j);
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
		else if(input=="exit")
		{
			return 0;
		}	
		
		


	}
	
}
int test()
{
	srand(time(NULL));
	vector<lecturer> lec;
	lecturer lec_temp;
	int tmp_personal_id;

	string tmp_name,tmp_surname, tmp_title,tmp_professions;//lecturer variable//
	ifstream file("lecturers.txt");	
	int lecturer_count=0;			
	while( !file.eof())
	{

		file >> tmp_personal_id;
		file >> tmp_name;
		file>> tmp_surname;
		file>> tmp_title;
		file>> tmp_professions;
		lec_temp.setInput(tmp_personal_id,tmp_name,tmp_surname,tmp_title,tmp_professions,3);
		lec.push_back(lec_temp);
		lecturer_count++;
	}
	int course_count=0,classroom_count=0;
	vector<Course> c1;
	vector<Classroom> cr;
	Classroom cr_temp;
	Course c1_temp;
	string course_temp,garbage,classroom_temp;
	ifstream course_file("courses_classrooms.txt");
	getline(course_file,garbage);
	while(getline(course_file,course_temp))
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
	while(getline(course_file,classroom_temp))
	{
		istringstream some_stream(classroom_temp);
		some_stream>>cr_temp.id;		
		some_stream>>cr_temp.c_no;
		some_stream>>cr_temp.capacity;
		classroom_count++;
		cr.push_back(cr_temp);
	}
	string input,com,courseName,courseField;
	int courseCode,courseCredit,courseHours;
	int i=0,ppp=0;
	int number,num,j=0;
	int there1=0;

	Administrator admin[course_count];
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
	int ffff=0;
	int flag3=0;
	while(1)
	{
		
			if(ppp==0)
			{
				input="assign";
			}
			if(ppp==1)
			{
				input="assign 1 2";
			}
			if(ppp==2)
			{
				input="timetable";
			}
			if(ppp==3)
			{
				input="arrangeC";
			}
			if(ppp==4)
			{
				input="exit";
				
			}
			cout<<input<<endl;
			istringstream some_stream(input);
			i=0;
			j=0;
			if(input[0]=='a'&& input[1]=='s' && input[6]==' ')
			{
				int there=0;
				some_stream>>com;
				some_stream>>number;
				some_stream>>num;
				while( i<lecturer_count)
				{
					if(number ==lec[i].get_Personal())
					{
						break;
					}
					
					i++;
				}


				if(number ==lec[i].get_Personal())
				{
						there=1;			/*you have the appropriate student*/
				}
				j=0;
				while(j<course_count)
				{
					if(num ==c1[j].id)
					{
						break;
					}

					j++;				/*appropriate course*/
				}
				if(num ==c1[j].id)
				{
					there1=1;
				}
				
				if(there==1 && there1==1)
				{
					lec[i].assignCourse(c1[j]);

				}
				else
				{
					cout<<"Error: no lecture or course"<<endl;
				}

			}
			else if(input[0]=='a'&& input[1]=='s' && input[6]=='\0')
			{
				int flag=0;
				int i=0;
				istringstream ss(lec[0].professions);
				string token;
				int count=0;
				int q;
				
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
					

					lec[0].assignCourse(c1,lec,lecturer_count,course_count);
					lec[1].assignCourse(c1,lec,lecturer_count,course_count);
					lec[2].assignCourse(c1,lec,lecturer_count,course_count);
					lec[3].assignCourse(c1,lec,lecturer_count,course_count);
					lec[4].assignCourse(c1,lec,lecturer_count,course_count);
					lec[5].assignCourse(c1,lec,lecturer_count,course_count);
					lec[6].assignCourse(c1,lec,lecturer_count,course_count);
					
					int a;

					lec[0].assignCourse(c1,course_count);

					lec[1].assignCourse(c1,course_count);

					lec[2].assignCourse(c1,course_count);
					
					lec[3].assignCourse(c1,course_count);
					
					lec[4].assignCourse(c1,course_count);
					
					lec[5].assignCourse(c1,course_count);
					
					lec[6].assignCourse(c1,course_count);
					
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

									lec[2].set_Courses();
									lec[2].set_count();
									
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
			else if(input[0]=='p'&& input[1]=='r' && input[2]=='o')
			{
				some_stream>>com;
				some_stream>>number;
				some_stream>>courseName;
				some_stream>>courseCode;
				some_stream>>courseCredit;
				some_stream>>courseHours;
				some_stream>>courseField;
				int i=0;
				while(number ==lec[i].get_Personal())
				{
					break;	
					i++;
				}
				if(lec[i].get_Field().find(courseField) !=string::npos )
				{
						lec[i].proposeCourse(c1,courseName);
				}

			}
			else if(input[0]=='t'&& input[1]=='i' && input[2]=='m' && input[9]==' ')
			{
				some_stream>>com;
				some_stream>>number;
				int flag=0;
				int i=0;
				while(i<course_count)
				{
					if(number==c1[i].id)
					{
						flag=1;
						break;
					}
					i++;
				}
				if(c1[i].flagg ==0 && flag==1)
				{
					c1[i].flagg =1;	
					admin[i].arrangeTimeTable(c1[i]);
					cout<<"DONE :"<<"("<<number<<")"<<c1[i].name<<" "<<admin[i].getTable()<<endl;
				}
				else if(flag==0)
				{
					cout<<"Error: no course"<<endl;

				}
				else
				{
					cout<<"Assigned Before: "<<"("<<number<<")"<<c1[i].name<<" "<<admin[i].getTable()<<endl;
				}
			}
			else if(input[0]=='t'&& input[1]=='i' && input[2]=='m' && input[9]=='\0')
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
			else if(input[0]=='a'&& input[1]=='r' && input[2]=='r' && input[7]=='C'&& input[8]==' ')
			{
				flag3=0;
				int gg=0;
				bool a;
				string token,mm;
				int kk;
				int count=0;
				some_stream>>com;
				some_stream>>number;
				some_stream>>courseName;
				istringstream ss(courseName);
				
				while(i<course_count)
				{
					if(number==c1[i].id)
					{
						gg=1;
						break;
					}
					i++;
				}
				if(gg==0)
				{
					cout<<"Error: no course"<<endl;
					break;
				}
				if(c1[i].flagg==0)
				{
					cout<<"Error: timetable not arranged yet "<<endl;
					break;
				

				}

				while(getline(ss,token,','))
				{
					
					kk=stoi(token);
					j=0;

					while(j<classroom_count)
					{
						if(kk==cr[j].id)
						{
							flag3=1;
							break;
						}
						j++;
					}
					if(flag3 ==0 )
					{
						cout<<"Error: no class"<<endl;
						break;
					}	
					a=admin[i].arrangeClasroom(cr[j],count);
					

					count++;
					if(a==0)
					{
						cout<<"Block: class is not available, there is another class assigned for this date"<<endl;
						break;
					}
					istringstream pp(admin[i].getTable());
					if(count==1)
					{
						getline(pp,mm,',');
						cout<<"DONE :"<<"("<<c1[i].id<<")"<<c1[i].name<<" in "<<token<<" at "<<mm;
					}
					else 				
					{
						int t=0,m=0;
						getline(pp,mm,'\0');
						while(m<count-1)
						{	
							while(mm[t] !=',')
							{
								t++;
							}
							t++;
							m++;
						}
						cout<<","<<" in "<<token<<" at "<<&mm[t]<<endl;

					}


				
				}
				



			}
			else if(input[0]=='a'&& input[1]=='r' && input[2]=='r' && input[7]=='C'&& input[8]=='\0')
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
							m=admin[i].arrangeClasroom(cr[a],j);
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
			else if(input=="exit")
			{
				cout<<"------------------------------TEST FINISH-----------------------------------------"<<endl;
				return 0;
			}

	ppp++;
		}
			



	
	
}
