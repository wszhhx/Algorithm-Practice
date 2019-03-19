//令Pi表示第i个素数。现任给两个正整数M <= N <= 10000，请输出PM到PN的所有素数。
#include<iostream>
#include<math.h>
using namespace std;
bool charge(int x)
{
	if(x%2==0 && x!=2 || x==1)
		return false;
	else
	{
		int y=sqrt(x);
		for(int i=3;i<=y;i++)
		{
			if(x%i==0)
				return false;
		}
	}
	return true;
}
int main()
{
	int M;
	int N;
	cin>>M;
	cin>>N;
	int flag=0;
	int array[10000];
	for(int i=0;i<=104729;i++)
	{
		if(flag>=10000)
			break;
		if(charge(i))
		{
			array[flag]=i;
			flag++;
		}
	}
	flag=0;
	for(int i=M-1;i<=N-1;i++)
	{
		flag++;
		if(flag%10==0 || i==N-1)
			cout<<array[i]<<endl;
		else
			cout<<array[i]<<" ";
	}
	return 0;
}
