#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[100000];
	int N;
	int P;
	cin>>N>>P;
	for(int i=0;i<N;i++)
	{
	
		cin>>a[i];
	}
	sort(a,a+N);
	int MAX=0;
	for(int i=0;i<N;i++)
	{
		for(int j=i+MAX-1;j<N;j++)
		{
			if(a[j]>a[i]*P)
			{
				break;
			}
			if(j-i+1>MAX)
			{
				MAX=j-i+1;
			}
		}
	}
	cout<<MAX;
	return 0;
}
