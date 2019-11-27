#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

struct Course{
	int id;
	string namee;
	int code;
	int credit;
	int total_hours;
	string lecture_dates;
	int field;
};
struct Classroom{
	int idd;
	string c_no;
	int capacity;
	int student_inroom;
};
class Student{
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
			 	break;
			 }
		count++;
	}

	while(getline(www,satir))
	{
		count1++;
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
    	file>>c1[i].namee;
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
    	file>>cr[i].c_no;
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
	int add=1;
	int ss=0;
	while(add !=0)
	{
		if(ss==0)
		{
			s="-ns Orkun Arslan 111 2";
		}
		else if(ss==1)
		{
			s="-ns Murat Boz 112 3";
		}
		else if(ss==2)
		{
			s="-ns Seda Akyol 113 1";
		}
		else if(ss==3)
		{
			s="-ns Zafer Çaliş 114 4";
		}
		else if(ss==4)
		{
			s="-e 111 1";
		}
		else if(ss==5)
		{
			s="-e 112 2";
		}else if(ss==6)
		{
			s="-e 113 3";
		}else if(ss==7)
		{
			s="-e 114 4";
		}else if(ss==8)
		{
			s="-e 114 5";
		}else if(ss==9)
		{
			s="-de 114 4";
		}
		else if(ss==10)
		{
			s="-e 114 5";
		}
		else if(ss==11)
		{
			s="-o";
		}
		else if(ss==12)
		{
			s="-o -f file.txt";
		}
		else if(ss==13)
		{
			s="exit";
			add=0;
		}
		j=0;
		i=0;
		flag=0;
		istringstream some_stream(s);
		if(s[0]=='-' && s[1] =='n')
		{
			ic++;
			some_stream>>com;
			some_stream>>stu[k].name;
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
					stu[k].tt=20;	
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
				temp[q] = stu[q];
				q++;
			}
			stu = temp ;
			k++;
			l++;
		}
		else if(s[0]=='-' && s[1] =='e' )
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
					there=1;
				}
			while(num !=c1[j].id)
			{
				j++;
			}
			if(there ==1)
			{
				stu[i].enterClassroom(cr[j%(count1+1)]);
				//stu[i].extractSchedule();
				asd=stu[i].enrollCourse(c1[j]);
				//stu[i].extractSchedule();
				if(stu[i].tt>=asd && asd !=0 && there==1)
				{
					stu[i].tt=stu[i].tt-asd;
					cout<<"DONE!"<<endl;
				}
				else if(stu[i].level+19<=asd)
				{
					cout<<"BLOCK!Because of (credits)"<<endl;
				}
				else if(asd ==0)
				{
					cout<<"BLOCK!Because of (Overlap)"<<endl;

				}
			}
			else
			{
				cout<<"ERROR: NO STUDENT"<<endl;
			}

		}
		else if(s[0]=='-' && s[1] =='l' )
		{
			while(i<8)
			{
			cout<<"("<<c1[i].id<<")"<<" "<<c1[i].namee<<" ";
			i++;
			}
		}
		else if(s[0]=='-' && s[1] =='d')
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
				there=1;
				
			}
			
			while(num !=c1[j].id)
			{
				j++;
			}
			if(there ==1)
			{
				asd=stu[i].disenroll(c1[j]);
				//stu[i].extractSchedule();
				if(stu[i].level+19>=asd && asd !=0 && there==1)
				{
					stu[i].tt=stu[i].tt+asd;
					cout<<"DONE!"<<endl;
				}
				else if(stu[i].level+19<=asd)
				{
					cout<<"BLOCK!Because of (credits) "<<endl;
					
				}
				else if(asd==0 )
				{
					cout<<"BLOCK!Because of (Overlap)"<<endl;
					
				}
			}

			else 
			{
				cout<<"ERROR: NO STUDENT"<<endl;
				
			}
			
		}
		else if(s=="exit")
		{
			exit(1);
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
							if(stu[i].array[h] ==1)
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
				i++;
			}
			cout<<stu[i].name<<" "<<stu[i].surname<<": ";
			
			while(h<9)
				{
					if(stu[i].array[h] ==1)
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
								fileTxt<<c1[h].namee<<" "<<c1[h].credit<<" ";
								sum=sum+c1[h].credit;
							}
							
							h++;
				}
			fileTxt<<" total credits :"<<sum<<" "<<" credit right :"<<stu[i].level+19<<endl;
		}
		
		
		ss++;
	}
}
int Student::enrollCourse(Course &cour) 
{	
	int flag1=0;
	bool tf;	
		tf=control( cour, flag1);
		if(tf==0)
		{
			tf=disenroll(cour);
			
			return 0;
		}
		else
		{
			return cour.credit;
		}
}
int Student::disenroll(Course &cour)
{
	int flag1=1;
	bool tf;	
		tf=control( cour, flag1);

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


		if(cour.lecture_dates[i]=='M')
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
			time[p]=cour.lecture_dates[i];
			p++;
			i++;
		}
		i=i+1;
		y=stoi(time);
		p=0;
		while(cour.lecture_dates[i] !=',' && cour.lecture_dates[i] !='\0')
		{
			time1[p]=cour.lecture_dates[i];
			i++;
			p++;
		}

		i=i+1;
		z=stoi(time1);
		if(flag1==1)
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
		else
		{
			array[cour.id]=1;
			if(arr[x][0]==0)
			{
				arr[x][0]=y;
				arr[x][1]=z;
				flag=1;


			}
			else
			{

				while(arr[x][k+1] !=0)
				{
					
					if(arr[x][k]>=y )
					{
						m1=arr[x][k];

					}
					else
					{
						m1=y;
					}
				
					if(arr[x][k+1]<=z)
						{
						m2=arr[x][k+1];
					}
					else
					{
						m2=z;
					}
					if(m2-m1>=2)
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
