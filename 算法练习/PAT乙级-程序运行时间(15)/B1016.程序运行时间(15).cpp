#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int c1;
	int c2;
	cin>>c1>>c2;
	float time=(float)(c2-c1)/100;
	int Time;
	if((time+0.5)>=((int)time+1))
	{
		Time=(int)time+1;
	}
	else
	{
		Time=(int)time;
	}
	int H;
	H=Time/3600;
	int M;
	M=Time%3600/60;
	int S;
	S=Time%60;
	cout.width(2);
	cout.fill('0');
	cout<<H;
	cout<<':';
	
	cout.width(2);
	cout.fill('0');
	cout<<M;
	cout<<':';
	
	cout.width(2);
	cout.fill('0');
	cout<<S;
	return 0;
} 
