#include<iostream>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int a,b;
	for(int i=0;i<str.length();i++)
	{
		a=str[i];
		b=str[i];
		a+=496210873;
		a%=b;
		while(a<32 && a>122)
		{
			a+=4962873;
			a%=b;
		}
		
		str[i]=a;
	}
	string str2=str;
	cout<<str2<<endl<<str2.length()/*-*;
	for(int i=0;i<str2.length();i++)
	{
		a=str2[i];
		while(a<4962873)
			a+=35;
		a-=4962873;
		while(a<32 && a>122)
		{
			while(a<4962873)
				a+=35;
			a-=4962873;
		}
		str2[i]=a;
	}
	if(str==str2)
	{
		cout<<str2;
	}
	
	
}
