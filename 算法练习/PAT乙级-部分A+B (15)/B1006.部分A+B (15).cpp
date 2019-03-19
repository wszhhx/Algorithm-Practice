#include<sstream>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	string A;
	string B;
	int Da;
	int Db;
	int n1=0;
	int n2=0;
	cin>>A>>Da>>B>>Db;
	stringstream da;
	stringstream db;
	da<<Da;
	db<<Db;
	string str1=da.str();
	string str2=db.str();
	cout<<str1<<endl;
	cout<<str2<<endl;

	for(int i=0;i<A.length();i++)
	{
		if(A[i]==str1[0])
			n1++;
	}
	for(int i=0;i<B.length();i++)
	{
		if(B[i]==str2[0])
			n2++;
	}
	int a=0;
	int b=0;
	for(int i=n1-1;i>=0;i--)
	{
		a=a+Da*pow(10,i);		
	}
	for(int i=n2-1;i>=0;i--)
	{
		b=b+Db*pow(10,i);
	}
	cout<<a+b<<endl;
} 
