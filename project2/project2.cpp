#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
struct Course{	/*Course Struct*/
	int id;
	string namee;
	int code;
	int credit;
	int total_hours;
	string lecture_dates;
	int field;
};
struct Classroom{ /*Clasrrom Struct*/
	int idd;
	string c_no;
	int capacity;
	int student_inroom;
};
class Student{		/*Class Student*/
public:
	int enrollCourse(Course &Cour);
	int disenroll(Course &Cour);
	bool control(Course &cour,int flag1);
	string extractSchedule();
	void enterClassroom(Classroom &Cr);
	void quitClassroom(Classroom &Cr);
	string name;
	string surname;
	int student_no;
	int level;
	int tt;
	string str;
	int arr[5][24];
	int array[9];
};
int main()
{
	int flag1=3;
	string satir;
	int count=0,count1=0;
	ifstream www("courses_classrooms.txt");
	while(getline(www,satir))
	{
		if(satir =="CLASSROOMS")
			 {
			 	break;			/*calculate line for course struct*/
			 }
		count++;
	}

	while(getline(www,satir))
	{
		count1++;	/*calculate line for clasroom struct*/
	}
	www.close();
	string a;
	string b;
	Course c1[count];
	Classroom cr[count1];
	ifstream file("courses_classrooms.txt");
	ofstream fileTxt("file.txt");
    int i=0;
    file>>a;
  
    
    while(i< count-1)
    {
    	file>>c1[i].id;
    	file>>c1[i].namee;	/*read file*//*for course*/
    	file>>c1[i].code;
    	file>>c1[i].credit;
    	file>>c1[i].total_hours;
    	file>>c1[i].lecture_dates;
  			i++;
	}
	i=0;
    file>>b;
    while(i<count1)
    {
    	file>>cr[i].idd;
    	file>>cr[i].c_no;		/*read file*//*for struct*/
    	file>>cr[i].capacity;
    	
    	i++;
	}
	i=0;
	while(i<count1)
	{
		cr[i].student_inroom=cr[i].capacity;
		i++;
	}
		
	i=0;
	Student *stu = new Student[1] ;
	Student *temp = new Student[1] ;
	int n=0,m;
	string com;
	int number;
	int num;
	bool trfs;
	string s;
	int asd;
	int j=0;
	int k =0, l=2 ,q;
	int flag=0;
	int ic=0;
	while(1)	/*loop*/
	{
		j=0;
		i=0;
		flag=0;
		getline(cin,s);
		istringstream some_stream(s);
		if(s[0]=='-' && s[1] =='n')
		{
			ic++;
			some_stream>>com;
			some_stream>>stu[k].name;		/*enter new student*/
			some_stream>>stu[k].surname;
			some_stream>>stu[k].student_no;
			some_stream>>stu[k].level;
			while(n<9)
			{
				stu[k].array[n]=0;
				n++;
			}
				if(stu[k].level==1)
				{
					stu[k].tt=20;		/*student credit*/
				}
				if(stu[k].level==2)
				{
					stu[k].tt=21;	
				}
				if(stu[k].level==3)
				{
					stu[k].tt=22;	
				}
				if(stu[k].level==4)
				{
					stu[k].tt=23;	
				}
				
			temp = new Student[l];
			q = 0;
			while(q < l -1)
			{
				temp[q] = stu[q];	/*memory allocation*/
				q++;
			}
			stu = temp ;
			k++;
			l++;
		}
		else if(s[0]=='-' && s[1] =='e' )	/*enroll course*/
		{
			flag1=0;
			int there=0;
			some_stream>>com;
			some_stream>>number;
			some_stream>>num;
			
			while( i<ic)
			{
				if(number ==stu[i].student_no)
				{
					break;
				}
				
				i++;
			}
			if(number ==stu[i].student_no)
				{
					there=1;			/*you have the appropriate student*/
				}
			while(num !=c1[j].id)
			{
				j++;				/*appropriate course*/
			}
			if(there ==1)
			{
				stu[i].enterClassroom(cr[j%(count1+1)]);/*clasroom funciton*/
				asd=stu[i].enrollCourse(c1[j]);/*enroll funcion for student*/
				if(stu[i].tt>=asd && asd !=0 && there==1)
				{
					stu[i].tt=stu[i].tt-asd;
					cout<<"DONE!"<<endl;	/*total credit reduce and print done*/
				}
				else if(stu[i].level+19<=asd)
				{
					cout<<"BLOCK!Because of (credits)"<<endl;/*credit exceed*/
				}
				else if(asd ==0)
				{
					cout<<"BLOCK!Because of (Overlap)"<<endl;/*Course overlap*/

				}
			}
			else
			{
				cout<<"ERROR: NO STUDENT"<<endl;/*given student number not found*/
			}

		}
		else if(s[0]=='-' && s[1] =='l' )
		{
			while(i<8)
			{
			cout<<"("<<c1[i].id<<")"<<" "<<c1[i].namee<<" ";/*print course name and id*/
			i++;
			}
		}
		else if(s[0]=='-' && s[1] =='d')/*disenroll*/
		{
			flag1=1;
			int there=0;
			some_stream>>com;
			some_stream>>number;
			some_stream>>num;
			while( i<ic)
			{
				if(number ==stu[i].student_no)
				{
					break;
				}
				
				i++;
			}
			if(number ==stu[i].student_no)
			{
				there=1;		/*you have the appropriate student*/
				
			}
			
			while(num !=c1[j].id)
			{
				j++;			/*approiate couse*/
			}
			if(there ==1)
			{
				asd=stu[i].disenroll(c1[j]);/*disenroll funcion for studeunt*/
				if(stu[i].level+19>=asd && asd !=0 && there==1)
				{
					stu[i].tt=stu[i].tt+asd;	/*total credit increase and print done*/
					cout<<"DONE!"<<endl;
				}
				else if(stu[i].level+19<=asd)
				{
					cout<<"BLOCK!Because of (credits) "<<endl;/*credit exceed*/
					
				}
				else if(asd==0 )
				{
					cout<<"BLOCK!Because of (Overlap)"<<endl;/*Course overlap*/
					
				}
			}

			else 
			{
				cout<<"ERROR: NO STUDENT"<<endl;/*given student number not found*/
				
			}
			
		}
		else if(s=="exit")
		{
			exit(1);		/*exit*/
		}
		else if(s=="-o")
		{
			int h=0;
			int sum=0;
			while(i<k)
					{
						h=0;
						cout<<stu[i].name<<" "<<stu[i].surname<<": ";
						while(h<9)
						{
							if(stu[i].array[h] ==1)/*student courses 1 has been assigned and courses are printed*/
							{
								cout<<c1[h-1].namee<<" "<<c1[h-1].credit<<" ";
								sum=sum+c1[h-1].credit;
							}
							
							h++;
						}

						cout<<" "<<"total credits:"<<" "<<sum<<" "<<" credit right :"<<stu[i].level+19<<endl;			
						i++;
					}
				
		}
		else if( s[0]=='-' && s[1]=='o' && s[2]==' ' &&s[4] !='f' )
		{
			int h=0;
			int sum=0;
			some_stream>>com>>number;
			while(number !=stu[i].student_no)
			{
				i++;		/*find student*/
			}
			cout<<stu[i].name<<" "<<stu[i].surname<<": ";
			
			while(h<9)
				{
					if(stu[i].array[h] ==1)/*student courses 1 has been assigned and courses are printed*/
							{
								cout<<c1[h-1].namee<<" "<<c1[h-1].credit<<" ";
								sum=sum+c1[h-1].credit;
							}
							
							h++;
				}
			cout<<" total credits :"<<sum<<" "<<" credit right :"<<stu[i].level+19<<endl;
		}
		
		else if(s[0]=='-' &&s[1]=='o'&& s[2]==' ' &&s[3]=='-' &&s[4]=='f'&&s[6]=='f')
		{
			
			int h=0;
			int sum=0;
			while(i<k)
					{
						h=0;
						fileTxt<<stu[i].name<<" "<<stu[i].surname<<": ";
						while(h<9)
						{
							if(stu[i].array[h] ==1)
							{
								fileTxt<<c1[h-1].namee<<" "<<c1[h-1].credit<<" ";
								sum=sum+c1[h-1].credit;
							}
							
							h++;
						}

						fileTxt<<" "<<"total credits:"<<" "<<sum<<" "<<" credit right :"<<stu[i].level+19<<endl;			
						i++;
					}
  

		}
		else if( s[0]=='-' && s[1]=='o' && s[2]==' ' &&s[4] =='f' )
		{
			int h=0;
			int sum=0;
			some_stream>>com>>number;
			while(number !=stu[i].student_no)
			{
				i++;
			}
			fileTxt<<stu[i-1].name<<" "<<stu[i-1].surname<<": ";
			
			while(h<9)
				{
					if(stu[i-1].array[h] ==1)
							{
								cout<<"bbbb";
								fileTxt<<c1[h].namee<<" "<<c1[h].credit<<" ";
								sum=sum+c1[h].credit;
							}
							
							h++;
				}
			fileTxt<<" total credits :"<<sum<<" "<<" credit right :"<<stu[i].level+19<<endl;
		}
	}
}
int Student::enrollCourse(Course &cour) /*enroll function*/
{	
	int flag1=0;
	bool tf;	
		tf=control( cour, flag1);/*control funcion for overlapped*/
		if(tf==0)
		{
			tf=disenroll(cour);/*Calling the asd function if it is not convenient to add a course*/
			return 0;
		}
		else
		{
			return cour.credit;
		}
}
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
void Student::quitClassroom(Classroom &cr)
{
	
		cr.student_inroom++;
}

void Student::enterClassroom(Classroom &cr)
{
		cr.student_inroom--;
}

