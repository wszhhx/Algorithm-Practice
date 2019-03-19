#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> a;
	int E;
	char flag;
	char temp;
	while(temp!='E')
	{
		temp=getchar();
		if(temp=='+' || temp=='-')
		{
			flag=temp;
			continue;
		}
		else if(temp=='.' || temp=='E')
		{
			continue;
		}
		a.push_back(int(temp)-48);
		//cout<<temp<<endl;
	}
	cin>>E;
	if(E<0)
	{
		E=-E;
		for(int i=0;i<E-1;i++)
		{
			a.insert(a.begin(),0);
		}
		if(flag=='-')
		{
			cout<<"-0.";
		}
		else
		{
			cout<<"0.";
		}
		for(int i=0;i<a.size();i++)
		{
			cout<<a[i];
		}
	}
	else if(E>0)
	{
		if(E>=a.size()-1)
		{
			E=E-(a.size()-1);
			for(int i=0;i<E;i++)
			{
				a.push_back(0);
			}
			if(flag=='-')
			{
				cout<<"-";
			}
			for(int i=0;i<a.size();i++)
			{
				cout<<a[i];
			}
		}
		else
		{
			if(flag=='-')
			{
				cout<<"-";
			}
			for(int i=0;i<a.size();i++)
			{
				if(i==E+1)
				{
					cout<<'.';
				}
				cout<<a[i];
			}
		}
	}
	else
	{
		for(int i=0;i<a.size();i++)
		{
			cout<<a[i];
		}
	}
	return 0;
}
