#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> a;
	int term[10];
	for(int i=0;i<10;i++)
	{
		cin>>term[i];
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<term[i];j++)
		{
			a.push_back(i);
		}
	}
	for(int i=0;i<a.size()-1;i++)
	{
		for(int j=0;j<a.size()-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	if(term[0]!=0)
	{
		int flag;
		for(flag=0;a[flag]==0;flag++);
		int temp;
		temp=a[0];
		a[0]=a[flag];
		a[flag]=temp;
	}
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i];
	}
	return 0;
}
