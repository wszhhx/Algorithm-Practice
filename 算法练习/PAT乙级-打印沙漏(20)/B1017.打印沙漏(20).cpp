#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int N;
	char c;
	cin>>N>>c;
	int n;
	n=sqrt((N+1)/2);
	int max=1+2*(n-1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			cout<<' ';
		}
		for(int j=0;j<max-2*i;j++)
		{
			if(j==(max-2*i-1))
			{
				cout<<c<<endl;
				break;
			}
			cout<<c;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<(max-(1+2*i))/2;j++)
		{
			cout<<' ';
		}
		for(int j=0;j<1+2*i;j++)
		{
			if(j==(2*i))
			{
				cout<<c<<endl;
				break;
			}
			cout<<c;
		}
	}
	int sum;
	sum=2*n*n-1;
	cout<<N-sum<<endl;
	return 0;
}
