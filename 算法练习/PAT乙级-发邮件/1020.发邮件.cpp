#include<iostream>
using namespace std;

int main()
{
	int n;
	long long answer[21];
	answer[0]=0;
	answer[1]=0;
	answer[2]=1;
	answer[3]=2;
	for(int i=4;i<21;i++)
	{
		answer[i]=(i-1)*(answer[i-1]+answer[i-2]);
	}
	while(cin>>n)
	{
		cout<<answer[n]<<endl;
	}
	return 0;
}
