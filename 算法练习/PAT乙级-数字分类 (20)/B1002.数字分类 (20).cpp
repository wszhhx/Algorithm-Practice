//给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：



//A1 = 能被5整除的数字中所有偶数的和；

//A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；

//A3 = 被5除后余2的数字的个数；

//A4 = 被5除后余3的数字的平均数，精确到小数点后1位；

//A5 = 被5除后余4的数字中最大数字。
#include<iostream>
#include<iomanip>
using namespace std;
int A1(int array[],int n);
int A2(int array[],int n);
int A3(int array[],int n);
float A4(int array[],int n);
int A5(int array[],int n);
int main()
{
	int n;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	for(int i=0;i<5;i++)
	{
		switch(i)
		{
			case 0:
				if(A1(array,n)==0)
				{
					cout<<'N'<<' ';
					break;
				}
				cout<<A1(array,n)<<' ';
				break;
			case 1:
				if(A2(array,n)==0)
				{
					cout<<'N'<<' ';
					break;
				}
				cout<<A2(array,n)<<' ';
				break;
			case 2:
				if(A3(array,n)==0)
				{
					cout<<'N'<<' ';
					break;
				}
				cout<<A3(array,n)<<' ';
				break;
			case 3:
				if(A4(array,n)>0)
				{
					float temp=A4(array,n);
					cout<<setiosflags(ios::fixed)<<setprecision(1)<<temp<<' ';
					break;	
				}
				cout<<'N'<<' ';
				break;
			case 4:
				if(A5(array,n)==0)
				{
					cout<<'N';
					break;
				}
				cout<<A5(array,n);
				break;
		}
		
	}
	
	
	return 0;
}

int A1(int array[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(array[i]%5==0 && array[i]%2==0)
		{
			sum+=array[i];
		}
	}
	return sum;
}

int A2(int array[],int n)
{
	int sum=0;
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		if(array[i]%5==1)
		{
			if(flag)
			{
				sum+=array[i];
				flag=false;
			}
			else
			{
				sum-=array[i];
				flag=true;
			}
		}
	}
	return sum;
}

int A3(int array[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(array[i]%5==2)
			sum++;
	}
	return sum;
}

float A4(int array[],int n)
{
	float sum=0;
	float counter=0;
	for(int i=0;i<n;i++)
	{
		if(array[i]%5==3)
		{
			sum+=array[i];
			counter++;
		}
	}
	return sum/counter;
}

int A5(int array[],int n)
{
	int symbol=0;
	for(int i=0;i<n;i++)
	{
		if(array[i]%5==4)
		{
			if(array[i]>symbol)
			{
				symbol=array[i];
			}
		}
	}
	return symbol;
}
