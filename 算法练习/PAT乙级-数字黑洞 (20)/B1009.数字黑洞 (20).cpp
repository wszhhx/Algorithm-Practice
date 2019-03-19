#include<iostream>
#include<sstream>
#include<stdlib.h>
using namespace std;
int up(string str)
{
	for(int i=0;i<str.length()-1;i++)
	{
		for(int j=0;j<str.length()-1-i;j++)
		{
			if(str[j]>str[j+1])
			{
				char temp;
				temp=str[j];
				str[j]=str[j+1];
				str[j+1]=temp;	
			}	
		}	
	}	
	stringstream os;
	os<<str;
	int a;
	os>>a;
	return a;
}
  
int down(string str)
{
	for(int i=0;i<str.length()-1;i++)
	{
		for(int j=0;j<str.length()-1-i;j++)
		{
			if(str[j]<str[j+1])
			{
				char temp;
				temp=str[j];
				str[j]=str[j+1];
				str[j+1]=temp;	
			}	
		}	
	}	
	stringstream os;
	os<<str;
	int a;
	os>>a;
	return a;
}  
  
void digui(int x)
{
	stringstream os;
	os<<x;
	string str;
	str=os.str();
	for(int i=str.length();i<4;i++)
	{
		str.insert(0,"0");
	}
	if(str[0]==str[1] && str[0]==str[2] && str[0]==str[3])
	{
		cout<<str<<" - "<<str<<" = "<<"0000"<<endl;
		return;
	}
	if(x!=6174)
	{
		
		int a=down(str);
		int b=up(str);
		int c=a-b;
		stringstream os2;
		stringstream os3;
		os2<<b;
		os3<<a;
		string str2;
		string str3;
		str2=os2.str();
		str3=os3.str();
		for(int i=str2.length();i<4;i++)
		{
			str2.insert(0,"0");
		}
		for(int i=str3.length();i<4;i++)
		{
			str3.insert(0,"0");
		}
		if(str3==str2)
		{
			cout<<str3<<" - "<<str2<<" = "<<"0000"<<endl;
			return;
		}
		cout<<str3<<" - "<<str2<<" = "<<c<<endl;
		digui(c);
	}
	else
	{
		return;
	}
	
}
int main()
{
	int a;
	cin>>a;
	digui(a);
	return 0;
}
