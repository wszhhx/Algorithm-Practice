#include<iostream>
using namespace std;
int main()
{
	int a=-1234567;
	int *p=&a;
	for(int i=31;i>=0;i--)
	{
		cout<<(*p>>i & 1)<<((i)%4==0 && i!=0 ? "-":"");
	}
	return 0;
}
