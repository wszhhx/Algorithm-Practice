#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<sstream>
using namespace std;
//============================
string transformer(char a);
int trans(char a);
//============================
int main()
{
	string str1;
	cin>>str1;
	int m=str1.length();
	int sum=0;
	for(int i=0;i<m;i++)
	{
		sum=sum+trans(str1[i]);
	}
	ostringstream buf;
	buf<<sum<<endl;
	string str2=buf.str();
	//cout<<sum<<endl;
	//char str2[100];
	int n = str2.length();
	for(int i=0;i<n-1;i++)
	{
		if(i==n-2)
		{
			cout<<transformer(str2[i]);
			break;
		}
		cout<<transformer(str2[i])<<" ";
	}
	
	return 0;
} 
//============================


string transformer(char a)
{
	switch(a)
	{
		case '0':
			return "lin";
		case '1':
			return "yi";
		case '2':
			return "er";
		case '3':
			return "san";
		case '4':
			return "si";
		case '5':
			return "wu";
		case '6':
			return "liu";
		case '7':
			return "qi";
		case '8':
			return "ba";
		case '9':
			return "jiu";
	}
}

int trans(char a)
{
	switch(a)
	{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}
}
