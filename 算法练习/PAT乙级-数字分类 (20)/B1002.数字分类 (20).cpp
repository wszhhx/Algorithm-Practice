//����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�



//A1 = �ܱ�5����������������ż���ĺͣ�

//A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��

//A3 = ��5������2�����ֵĸ�����

//A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��

//A5 = ��5������4��������������֡�
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
