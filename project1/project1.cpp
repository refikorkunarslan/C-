#include <iostream>
using namespace std;
unsigned long fibonacci(unsigned int number);/*fibonacci function*/

int main()
{
	unsigned long int a,biggest,center1,center2;
	int flag=0 ,i ,j ;
	cin >>a;
	if(a%2==0)
	{
		a=a+1;	/*if a=4 ,(4+1)/2+1=3 so +1*/
	}
	if(a<0)
	{
		return 0;/*the program ends when a negative number is entered*/
	}

	for(i=0;i<=a+1;i++)
	{
		for(j=0; j<i;j++)
		{
			/*fibonnaci pyramid equation*/
			/*ex : i=5 j =3 --6*1=6*/
			cout <<fibonacci(j+1)*fibonacci(i-j)<<" ";
			if(i==a+1 && j==i-1)
			{
				biggest =fibonacci(j+1)*fibonacci(i-j);/*last elememt is biggest element*/
			}
			
			if((a+1)/2+1 ==i )
			{
				if(i%2==1 && j==i/2)
					{
						flag=2;
						center1=fibonacci(j+1)*fibonacci(i-j);/*odd number fin heart of the pyramid*/
					}
					else if(i %2==0 && j==i/2)
					{
						flag=1;
						center1=fibonacci(j+1)*fibonacci(i-j);/*even number fin heart of the pyramid*/
						center2=fibonacci(j+1)*fibonacci(i-j);
				    }
			}

		}
		if(i !=0)
		{
			cout<<endl;
		}
	}
	cout<<"Biggest number: "<<biggest<<endl;/*print biggest number*/
	if(flag==2)
	{
		cout<<"Heart of the pyramid: "<<center1<<endl;/*print center*/
	}
	if(flag==1)
	{
		cout<<"Heart of the pyramid: "<<center1<<" "<<center2<<endl;
	}
}
unsigned long int fibonacci(unsigned int number)/*fibonacci function*/
{
	int i;
	unsigned long int num1=0;/*two variable for fibonacci*/
	unsigned long int num2=1;
	unsigned long int temp;
	for(i=2;i<=number;i++)/*as number*/
	{
		temp=num2;
		num2=num2 + num1;	/*fibonaci 0 1 1 2 3 5 8 13 22..*/
		num1=temp;
	}
	return num2; /*return num*/
}