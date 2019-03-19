#include<iostream>
using namespace std;
int main()
{
	int sum=40;
	int bottle=40;
	int cap=40;
	int more;
	do
	{
		more=(cap/4)+(bottle/2);
		bottle=bottle%2+more;
		cap=cap%4+more;
		sum+=more;
	}while(more!=0);
	cout<<sum;	
} 
