
#include<iostream>
#include<string>
using namespace std;
bool IsPAT(string str);       //�������� 
int BeforeP(string str);      //PǰA��Ŀ 
int BetweenPandT(string str); //P-T֮��A��Ŀ 
int AfterP(string str);       //P֮��A��Ŀ 
bool Charge(string str);      //�о� 

int main()
{
	string str[9];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	for(int i=0;i<n;i++)
	{
		if(IsPAT(str[i]))
		{
			//cout<<"ֻ��PAT������ĸ"<<endl;
			if(Charge(str[i]))
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;	
		}	
		else
		{
			cout<<"no"<<endl;
		}
	}	
} 

bool Charge(string str)
{
	//cout<<"����CHARGE"<<endl;
	int x=BeforeP(str);
	int y=BetweenPandT(str);
	int z=AfterP(str);
	cout<<x<<'\t'<<y<<'\t'<<z<<endl;
	if(x+y==z)
		return true;
	else
		return false;
}

bool IsPAT(string str)
{
	int n=str.length();
	int x(0);
	int y(0);
	int z(0);
	for(int i=0;i<n;i++)
	{
		switch(str[i])
		{
			case 'P':
				x++;
				break;
			case 'A':
				y++;
				break;
			case 'T':
				z++;
				break;
		}
		if(str[i]!='P' && str[i]!='A' && str[i]!='T')
			return false;
	}	
	if(x==0 || y==0 || z==0)
	{
		return false;
	}
	//cout<<"true"<<endl<<x<<endl<<y<<endl<<z<<endl;
	return true;
} 
int BeforeP(string str)    //PǰA��Ŀ 
{
	int n=str.length();
	//cout<<"����BEFORE"<<str<<endl;
	int sum(0);
	int i(0);

	while(i<n)
	{
		if(str[i]=='A')
			sum++;
		else if(str[i]=='P')
			return sum;
		i++;
	}
}

int BetweenPandT(string str) //P-T֮��A��Ŀ 
{
	//cout<<"����BETWEEN"<<endl;
	int sum(0);
	int n(0);
	while(str[n]!='P')
	{
		n++;
	}
	n+=1;
	int m(n);
	while(str[m]!='T')
	{
		m++;
	}
	for(int i=n;i<m;i++)
	{
		if(str[i]=='A')
			sum++;
	}
	return sum;
}
int AfterP(string str)
{
	//cout<<"����AFTER"<<endl;
	int sum(0);
	int n(0);
	while(str[n]!='P')
	{
		n++;
	}
	n+=1;
	for(int i=n;i<str.length();i++)
	{
		if(str[i]=='A')
			sum++;
	}
	return sum;
}
