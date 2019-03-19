#include<iostream>
#include<stdlib.h>
using namespace std;
//===========================
bool charge(int a);
int caculator(int x);
//===========================
int main()
{
	int x=0;
	cin>>x;
	cout<<caculator(x)<<endl;
	system("pause");
	return 0;
}

bool charge(int a)
{
	if(a%2==0)
		return true;
	else
		return false;
}

int caculator(int x)
{
	int i=0;
	while(x!=1 && x!=0)
	{
		if(charge(x))
		{
			x=x/2;
		}
		else
		{
			x=(3*x+1)/2;
		}
		i++;
	}
	return i;
}
